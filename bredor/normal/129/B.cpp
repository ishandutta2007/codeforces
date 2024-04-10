//  228

#include<stdio.h>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
int a[101][101];
int degree[101];
int main()
{
 	int n,m,i,j,s,k,q,p,flag;
 	scanf("%d%d",&n,&m);
 	for(i=1;i<=m;i++)
 	{
	    scanf("%d%d",&p,&q);
		a[p][q]=a[q][p]=1;	
		degree[q]++;
		degree[p]++;		 
	}

	flag=1,s=0;
	queue<int>stu;
	while(flag)
	{
        flag=0;
	 	for(i=1;i<=n;i++)
		 {
		  	if(degree[i]==1)
			  {
			   	flag=1;			
			   	stu.push(i);		
			  }			 
		 }	
		 if(flag==1) s++;
		 while(!stu.empty())
		 {
		  	k=stu.front();
			  stu.pop();
			  for(i=1;i<=n;i++)
			  {
			   	if(a[k][i]==1) 	
				   {
				   		a[k][i]=a[i][k]=0;
						   degree[i]--;
						   degree[k]--;		
				   }		   
			  }				   				
		 }	
	}
	printf("%d\n",s);	
	return 0;
}