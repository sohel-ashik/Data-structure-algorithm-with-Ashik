#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define l &head
typedef struct node Node;
//here the 'struct node' changed into Node name funny huh?

//singly linked list creation , insert , deletion

struct node
{
    int data;
    Node *next;
};

Node *create_node(int value,Node *next)
{
    Node *new_node = (Node*)(malloc(sizeof(Node)));

    new_node->data=value;
    new_node->next=next;

    return new_node;
}

void append(int value,Node **head)
{
    Node *new_node = (Node*)(malloc(sizeof(Node)));
    new_node=create_node(value,NULL);
    Node *dummy_head=*head;

    if (*head == NULL)
    {
        *head=new_node;
        return;
    }
    else
    {
        while(dummy_head->next!=NULL)
            dummy_head=dummy_head->next;
        dummy_head->next=new_node;
        return;
    }



}

void prepend(int data,Node **head)
{
    Node *new_node= create_node(data,*head);
    *head=new_node;

}

void node_after_insert(int value,int node_after_insert,Node **head)
{
    Node *pre,*post,*dummy_head;
    dummy_head=*head;

    while(dummy_head->data!=node_after_insert)
        {
            if(dummy_head->next==NULL)
            {
                printf("-------No target found\n");
                return;
            }
            dummy_head=dummy_head->next;
        }

    pre=dummy_head;
    post=dummy_head->next;

    Node *new_ndoe=create_node(value,post);
    pre->next=new_ndoe;

}



void del(int value,Node **head)
{

    Node *current=*head;
    if(current==NULL)
        {
            printf("Nothing here to delete !\n");
            return;
        }
    if(current->next==NULL && current->data!=value)
    {
        printf("Not fount !\n");
        return;
    }
    if(current->data==value)
    {
        *head=current->next;
        free(current);
        printf("Successfully deleted the first node !\n");
        return;
    }

    while((current->next)->data!=value)
    {
        if((current->next)->next==NULL)
        {
            printf("Not found.\n\n");
            return;
        }

        current=current->next;
    }

    current->next=(current->next)->next;
    printf("Successfully deleted target node.");

}

//reversing a linked list without using any space and time complexity is O(n)
void rvrs(Node **head)
{
    if(*head==NULL)
    {
        printf("ERROR !\n");
        return;
    }
    else
    {
        Node *post = *head,*pre=NULL,*current;
        while(post!=NULL)
        {
            current=post;
            post=post->next;
            current->next=pre;
            pre=current;
        }
        *head=pre;
    }
}




void print(Node *head)
{
    if (head == NULL)
    {
        printf("Nothing is here.\n");
        return;
    }
    Node *current_node=head;
    int i=1;
    while(current_node->next!=NULL)
    {

        printf("%d      %p\n",current_node->data,current_node->next);
        current_node=current_node->next;
        i++;

    }
    printf("%d      %p\n\n\n",current_node->data,current_node->next);
    printf("Total nodes are ----- %d\n\n",i);
}

Node *Search(int value,Node *head)
{
    if (head==NULL)
    {
        return NULL;
    }
    else if (head->data==value)
    {
        return head;
    }
    return Search(value,head->next);
}

int main()
{
    Node *head;
    head = (Node*)(malloc(sizeof(Node)));
    head = NULL;

    while(1)
    {
        int a;
        printf("1: Prepend 2: Append 3: Node after insert\n4: Delete selected node 5: Show all data (54): For reverse (6 for search):-> ");
        scanf("%d",&a);
        if(a==1)
        {
            int x;
            printf("Prepend Data : ");
            scanf("%d",&x);
            prepend(x,l);
        }
        else if(a==2)
        {
            int x;
            printf("Append Data : ");
            scanf("%d",&x);
            append(x,l);


        }
        else if( a==3)
        {

            int x,y;
            printf("Node after insert: "); scanf("%d",&x);
            printf("Value : ");scanf("%d",&y);

            node_after_insert(y,x,l);

        }
        else if(a==4)
        {
            printf("Which value you want to delete? = ");
            int x;
            scanf("%d",&x);
            del(x,l);

        }
        else if(a==5)
        {
            printf("\n\nAll linked data\nData    Location\n");
            print(head);
        }
        else if(a==6)
        {
            int x;printf("Search : ");scanf("%d",&x);
            Node *n;
            n=(Node*)(malloc(sizeof(Node)));
            n=Search(x,head);
            if(n==NULL)printf("Not found! \n\n");
            else
            printf("%d     %p\n\n",n->data,n->next);
        }
        else if(a==54)
        {
            rvrs(&head);
        }
        else break;
    }



    return 0;
}
