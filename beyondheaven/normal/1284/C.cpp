#include<cstdio>
#include<algorithm>
#define MaxN 250123
typedef long long LL;
int n,m;
LL ans;
int fac[MaxN];
int main()
{
	scanf("%d%d",&n,&m);
	fac[0]=1;
	for(int i=1;i<=n;++i)
	fac[i]=1LL*fac[i-1]*i%m;
	for(int i=1;i<=n;++i)
	ans=(ans+1LL*(n-i+1)*(n-i+1)%m*fac[i]%m*fac[n-i]%m)%m;
	printf("%lld\n",ans);
	return 0;
}