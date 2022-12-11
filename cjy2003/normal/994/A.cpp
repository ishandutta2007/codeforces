#include<stdio.h>
#include<string.h>
int n,m,a[11],b[11],x;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		b[x]=1;
	}
	for(int i=1;i<=n;i++)
		if(b[a[i]]==1)printf("%d ",a[i]);
	return 0;
}