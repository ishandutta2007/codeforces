#include<stdio.h>
#include<string.h>
int a,b,x,a1,b1,z,o;
int main()
{
	scanf("%d %d %d",&a,&b,&x);
	a1=(x-1)/2;
	b1=x/2;
	if(a>b)
	{
	for(int i=1;i<=a1;i++)
	{
		printf("01");
		a--,b--;
	}	
	if(b1>a1)
	printf("0"),a--;
	if(b1>a1)
	{
		for(int i=1;i<=b;i++)printf("1");
		for(int i=1;i<=a;i++)printf("0");	
	}
	else
	{
		for(int i=1;i<=a;i++)printf("0");	
		for(int i=1;i<=b;i++)printf("1");	
	}
	}
	else
	{
		for(int i=1;i<=a1;i++)
	{
		printf("10");
		a--,b--;
	}	
	if(b1>a1)
	printf("1"),b--;
	if(b1>a1)
	{
		for(int i=1;i<=a;i++)printf("0");
		for(int i=1;i<=b;i++)printf("1");
			
	}
	else
	{
		for(int i=1;i<=b;i++)printf("1");
		for(int i=1;i<=a;i++)printf("0");	
	}
	}
	return 0;
}