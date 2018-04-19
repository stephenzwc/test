#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


typedef struct _list
{
    struct _list *next;
    int val;
}List;

typedef struct _dlist
{
    struct _dlist *next;
    struct _dlist *pre;
    int val;
}DList;

/**
 *  p1 1 2 4 6 9
 *
 *  p2 3 5 7 9
 *
**/

List *Merge(List *p1, List *p2)
{
    assert(!(p1 == NULL) && !(p2 == NULL));

    List *head = NULL, *tail = NULL;
    List *ptr = NULL, *ptmp = NULL, *pbak = NULL;

    if(p1->val >= p2->val)
    {
      head = p2;
      tail = p1;
    }
    else
    {
      head = p1;
      tail = p2;
    }

    ptr = head;
    while(ptr)
    {
        ptr = ptr->next;
        while(tail)
        {
            if(tail->val > ptr->val)
            {
                if(tail->val > ptr->next->val )
                    break;
                else
                {
                   ptmp = ptr->next; 
                   pbak = tail->next;
                   ptr->next = tail;
                   tail->next = ptmp;
                   tail = pbak;
                }
            }
        }
    }
    return head;
}

void ListPrintByMethod(DList *pList, int len, int number)
{
    assert(!(pList == NULL));
}

List *ReverseList(List *pList)
{
    assert(!(pList == NULL));

    List *ptr = NULL, *ptmp = NULL;

    while(pList)
    {
        ptmp = pList->next;
        pList->next = ptr;
        ptr = pList;
        pList = ptmp;
    }

    return ptr;
}


int CreateList(List **pList, int val)
{
    assert(!(pList == NULL));

    if(*pList == NULL)
    {
       *pList = malloc(sizeof(List));
       if(*pList)   (*pList)->val = val;
    }
    else
    {
        List *ptmp = *pList;
        while(ptmp->next)   ptmp = ptmp->next;

       ptmp->next = malloc(sizeof(List));
       if(ptmp->next) ptmp->next->val = val;
    }

    return 0;
}

void FreeList(List **pList)
{
    List *ptmp = *pList;

    assert(!(pList == NULL));

    while(ptmp != NULL)
    {
        *pList = (*pList)->next;
        free(ptmp);
        ptmp = NULL;
        ptmp = *pList;
    }
}

void PrintList(List *pList)
{
    assert(!(pList == NULL));

    while(pList != NULL)
    {
        printf(" %d", pList->val);
        pList = pList->next;
    }
    printf("\n");
}

int main(int argc, void **argv)
{
    List *head = NULL;
    List *tail = NULL;

    CreateList(&head, 1);
    CreateList(&head, 2);
    CreateList(&head, 4);
    CreateList(&head, 6);
    CreateList(&head, 9);
    PrintList(head);
    
    CreateList(&tail, 3);
    CreateList(&tail, 5);
    CreateList(&tail, 7);
    CreateList(&tail, 9);
    PrintList(tail);

    Merge(head, tail);
    PrintList(head);

    List *ptr = ReverseList(head);
    PrintList(ptr);
    FreeList(&head);
    return 0;
}

