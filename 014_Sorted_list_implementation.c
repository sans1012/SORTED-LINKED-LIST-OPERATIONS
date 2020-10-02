#include<stdio.h>
#include<stdlib.h>

struct node
{ int info;
  struct node *link;
};
 
struct node * start;

void create(int item)
{ struct node *nnw=(struct node *)malloc(sizeof(struct node ));
  nnw->info=item;
  nnw->link=NULL;
  if(start==NULL)
  { start=nnw; }
  else
  { struct node *temp=start;
    while(temp->link!=NULL)
    temp=temp->link;
    temp->link=nnw;
  }	
}

int sorted()
{ struct node*temp,*ptr;
  int flag=0;
  temp=start;
  ptr=start->link;
  while( ptr->link!=NULL)
  { if(ptr->info<temp->info )
    { flag=-1;
      break;
    }
    temp=ptr;
    ptr=ptr->link;
  }
  return(flag);
}

void display_list()
{ if(start==NULL)
  printf("\n No list to diplay");
  else
  { struct node * ptr=start;
    printf("\n List is as follow \n ");
    while(ptr->link!=NULL)
    { printf("%d  --->  ",ptr->info);
      ptr=ptr->link;
    }
    printf("%d",ptr->info);
  }	
}

void insert(int item)
{ struct node *nnw=(struct node *)malloc(sizeof(struct node ));
  nnw->info=item;
  nnw->link=NULL;
  if(start==NULL)
  { start=nnw; }
  else if (start->info > nnw->info)
  { nnw->link=start;
    start=nnw;	
  }
  else
  { struct node*ptr,*pre;
    pre=start;
    ptr=start->link;
    while(ptr->link!=NULL)
    { if (ptr->info < nnw->info)
      {	pre=ptr;
	ptr=ptr->link;
      }		
      else
      { break; }
    }
    if(ptr->link==NULL && ptr->info<nnw->info )
    { ptr->link=nnw; }
    else
    { nnw->link=ptr;
      pre->link=nnw;
    }
  }		
}

void Delete(struct node * loc, struct node* locp, int item)
{ if (loc==locp)
  { printf("\n Memory underflow"); }
  else if(locp==NULL &&loc!=NULL)
  { start=start->link;
  else
  { locp->link=loc->link;
    free (loc);
    loc=NULL;
    printf("\n Element Deleted ");
  }
}

void search(int item )
{ struct node*locp,*loc;	
  if (start == NULL)
  { loc=locp=NULL; }
  else if (start->info==item)
  { loc=start;
    locp=NULL;
  }
  else 
  { locp=start;
    loc=start->link;
    while(loc->link!=NULL)
    { if((loc->info) == item)
      { break; }
      else if( (loc -> info) > item)
      {	loc=locp=NULL;
	printf("\n Element not present in this list");
	exit(0);
      }
      locp=loc;
      loc=loc->link;
    }
    if(loc->info>item || (loc -> link== NULL ) )
    { printf("\n Element is not present in this list");
      exit(0);
    }
  }
  Delete(loc,locp,item);	
}

void main()
{ int ch,item;
  char ans='Y';
  start=NULL;
  while(ans=='Y'||ans=='y')
  { system("cls");
    printf("\n********************  CHOICE MENU  *************************\n");
    printf("\n Note:The following operations are only valid for a linked list in ascending order!!\n");
    printf("\n 1. Creating a sorted linked list ");
    printf("\n 2. Inserting node in a sorted linked list");
    printf("\n 3. Deleting node in a sorted linked list");
    printf("\n 4. Displaying a sorted linked list ");
    printf("\n 5. Exit");
    printf("\n Enter choice : ");
    scanf("%d",&ch);
    switch(ch)
    { case 1: printf("\n Enter the no. of nodes : ");
              int n,item,i,ans;
	      scanf("%d",&n);
	      for(i=0;i<n;i++)
	      {	printf("\n Enter the data for node %d : ",i+1);
		scanf("%d",&item);
		create(item);
	      }
	      ans=sorted();
	      if(ans==-1)
	      {	printf("\n The linked list is not sorted thus can't proceed futher\n ...Terminating...");
		exit(0);
	      }
	      break;
			
      case 2: printf("\n Enter the element to be inserted in the list : ");
	      scanf("%d",&item);
	      insert(item);
	      printf("\n Element Added ");
              break;
					
      case 3: printf("\n Enter the element to be deleted from the list \n Note: If element is not present the program will terminate ! \n Enter element to delete :  ");
	      scanf("%d",&item);
	      search(item);			
	      break;
			
      case 4: display_list();
	      break;
					
      case 5: printf("\n ...Terminating....");
	      exit(0);
	      break;
					
      default: printf("\n Wrong choice entered ");
	       break;
			
    }
    printf("\n Do you want to enter more choices(y/Y for Yes ,any other key for no): ");
    fflush(stdin);
    scanf("%c",&ans);
  }
  printf("\nPress any key to EXIT...");
  getch();
}

