#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int main()
{
	scanf("%d %d",&n,&m);
	if(n==1&&m==1)return printf("0"),0;
	if(n==1)
	{
		for(int i=1;i<=m;++i)printf("%d ",i+1);
		return 0;
	}
	if(m==1)
	{
		for(int i=1;i<=n;++i)printf("%d\n",i+1);
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)printf("%d ",i*(j+n));
		printf("\n");
	}
	return 0;
}