#include<stdio.h>
#include<string.h>
int t,a,sum;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&a);
		sum=0;
		while(a)
		{
			a&=a-1;
			++sum;	
		}	
		printf("%d\n",1<<sum);
	}
	return 0;
}