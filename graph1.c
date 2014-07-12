//linked list representation of graph

#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<alloc.h>

#define MAX  10
#define LENGTH 100
struct node
	{
	char word[LENGTH];
	struct node * next;
	};

struct node *graphlist[MAX];

void insertFunc();
struct node * searchFunc(char *keyword);
void displayFunc();



void insertFunc()
{
struct node *temp1, *temp2, *temp3;
int i=0;
char tempword[LENGTH];
temp1=(struct node *) malloc (sizeof(struct node));
printf("\nEnter the string for the current node: ");
fflush(stdin);
gets(temp1->word);
temp1->next=NULL;

// creating two nodes... 1 for the main list and 2nd for the sublist
//utilization of space is twice
temp3=(struct node *) malloc (sizeof(struct node));
strcpy(temp3->word,temp1->word);
temp3->next=temp1->next;

if ( graphlist[0] == NULL)
	graphlist[0]=temp1;
else
	{
	temp2=graphlist[0];
	while (temp2->next !=NULL)
		temp2=temp2->next;
	temp2->next=temp1;
	printf("\nEnter the key word after which you want to insert the data: ");
	fflush(stdin);
	gets(tempword);
	temp2=searchFunc(tempword);
	if ( temp2!=NULL)
		{
		if (temp2->next != NULL)
			while(temp2->next!=NULL)
				temp2=temp2->next;
		temp2->next=temp3;
		}
	else
		for ( i=1;i<MAX;i++)
			if (graphlist[i] == NULL)
				{
				graphlist[i]=temp3;
				break;
				}

	}
}


void displayFunc()
{
int i;
struct node *temp;

for(i=0;i<MAX;i++)
	{
	if (graphlist[i] !=NULL)
		{
		temp=graphlist[i];
		while (temp!=NULL)
			{
			printf(temp->word);
			printf("->");
			temp=temp->next;
			}
		printf("\n");
		}
	else continue;
	}
}

struct node* searchFunc( char *keyword)
{
struct node *start;
int i;
start=graphlist[1];
for (i=1;i<MAX;i++)
	{
	if (!(strcmp(start->word, keyword)))
		return start;
	else
		while (start->next != NULL)
			{
			start=start->next;
			if (!(strcmp(start->word, keyword)))
				{
				puts("data found..");
				return start;
				}
			}
	}
return NULL;
}


int main()
   {
	int ch,key,i;
	struct node * node1;
	clrscr();

   // setting null values to the list
   for (i=0;i<MAX;i++)
   	graphlist[i]=NULL;

	while (1)
		{
		printf("\nEnter 1 to insert a string in the tree: ");
		printf("\nEnter 2 to search a string in the tree: ");
		printf("\nEnter 3 to display the tree: ");
		fflush(stdin);
		scanf("%d",&ch);
		switch(ch)
			{
			case 1: insertFunc();
						break;
			case 2: printf("\nEnter the id for the string you want to search: ");
						scanf("%d",&key);
					/*	node=searchFunc(key,root);
						printf("\nThe result is\n");
						puts(node1->word);
						printf(" the node id is %d",node->id);   */
						break;
			case 3: displayFunc();
						break;
			default: printf("\nquitting the program.. press any key");
						getch();
						return(0);
			}
		}
	}

