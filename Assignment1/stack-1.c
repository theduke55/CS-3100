#include "stack.h"
#include "stdio.h"
#include <stdlib.h>

stackT *NewStack(void)
{
    stackT* myStack = malloc(sizeof(stackT));
    myStack->head = NULL;
    return myStack;
}

void Push(stackT *stack, valueT value)
{
    nodeT* myNode = malloc(sizeof(nodeT));
    
    if(stack->head == NULL)
    {
        myNode->next = NULL;
    }
    else
    {
        myNode->next = stack->head;
    }
    stack->head = myNode;
    myNode->value = value;
}

valueT Pop(stackT *stack)
{
    if(stack->head == NULL)
    {
        printf("The stack is already empty.\n");
        return 0;
    }
    else
    {
        valueT value = stack->head->value;
        nodeT* temp = stack->head;
        stack->head = stack->head->next;
        free(temp);
        return value;        
    }
}

void EmptyStack(stackT *stack)
{
    while(stack->head != NULL)
    {
        Pop(stack);
    }
    stack->head = NULL;
}

void FreeStack(stackT *stack)
{
    if(stack->head == NULL)
    {
        free(stack);
    }
    else
    {
        printf("Error: the stack is not empty.\n");
    }
    
}

bool IsEmpty(stackT *stack)
{
    if(stack->head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}