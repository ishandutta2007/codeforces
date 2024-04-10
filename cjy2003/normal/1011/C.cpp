#include<stdio.h>
#include<string.h>
int n,m,a[1001],b[1001];
double sum;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&a[i],&b[i]);
	sum=m;
	if(b[1]==1||a[n]==1)
	{
		printf("-1");
		return 0;	
	}
	sum+=sum/(b[1]-1);
	sum+=sum/(a[n]-1);
	for(int i=n;i>1;i--)
	{
		if(b[i]==1||a[i-1]==1)
		{
			printf("-1");
			return 0;	
		}	
		sum+=sum/(b[i]-1);
		sum+=sum/(a[i-1]-1);
	}
	printf("%.10lf",sum-m);
	return 0;
}