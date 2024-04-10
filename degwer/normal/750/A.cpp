#include<stdio.h>
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int t=0;
	k=240-k;
	for(int i=1;i<=n;i++)
	{
		if(k-5*i>=0)t++;
		else break;
		k-=5*i;
	}
	printf("%d\n",t);
}