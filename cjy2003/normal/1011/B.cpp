#include<stdio.h>
#include<string.h>
int n,m,a[101],x,sum;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		a[x]++;	
	}
	for(int i=101;i>0;i--)
	{
		sum=0;
		for(int j=1;j<=100;j++)	
			sum+=a[j]/i;
		if(sum>=n)
		{
			printf("%d",i);
			return 0;	
		}
	}
	printf("0");
	return 0;
}