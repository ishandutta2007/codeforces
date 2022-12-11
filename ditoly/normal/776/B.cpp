#include<cstdio>
#define MN 100000
int f[MN+5];
int main()
{
	int n,i,j;
	scanf("%d",&n);++n;
	for(i=2;i*i<=n;++i)if(!f[i])
		for(j=i*i;j<=n;j+=i)f[j]=1;
	puts(n<4?"1":"2");
	for(i=2;i<=n;++i)printf("%d ",f[i]+1);
}