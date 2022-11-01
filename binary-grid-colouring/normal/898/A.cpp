#include<stdio.h>
int main()
{
	long int a,n; 
	scanf("%d",&n);
	 a=n%10;
	 if(a<=5)printf("%d\n",n-a);
	 else printf("%d\n",n-a+10);
	return 0; 
}