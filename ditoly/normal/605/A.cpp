#include<cstdio>
#include<algorithm>
using namespace std;
#define MN 100000
int f[MN+5];
int main()
{
	int n,i,x,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&x),ans=max(ans,f[x]=f[x-1]+1);
	printf("%d",n-ans);
}