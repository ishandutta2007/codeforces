#include<cstdio>
#include<cstring>
#define MN 10000
int a[MN+5],b[MN+5],p[MN+5],cnt,ans[MN+5];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		printf("? 0 %d\n",i);
		fflush(stdout);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;++i)
	{
		printf("? %d 0\n",i);
		fflush(stdout);
		scanf("%d",&b[i]);
	}
	for(i=0;i<n;++i)
	{
		memset(p,-1,sizeof(p));
		for(j=0;j<n;++j)p[i^a[j]]=j;
		for(j=0;j<n;++j)if(p[j]<0)break;
		if(j<n||p[0]!=i)continue;
		for(j=0;j<n;++j)if((p[j]^i^a[0])!=b[j])break;
		if(j<n)continue;
		if(!cnt++)for(j=0;j<n;++j)ans[j]=p[j];
	}
	printf("!\n%d\n",cnt);
	for(i=0;i<n;++i)printf("%d ",ans[i]);
}