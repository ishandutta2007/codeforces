#include<cstdio>
#define MaxN 200123
typedef long long LL;
const LL Mod=998244353;
int n,k;
int p[MaxN],pos[MaxN],cnt;
LL ans1,ans2;
int main()
{
	scanf("%d%d",&n,&k);
	ans2=1;
	for(int i=1;i<=n;++i)
	scanf("%d",p+i);
	for(int i=0;i<k;++i)ans1+=(n-i);
	for(int i=1;i<=n;++i)
	if(p[i]>(n-k))pos[++cnt]=i;
	for(int i=2;i<=k;++i)
	ans2=ans2*(pos[i]-pos[i-1])%Mod;
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}