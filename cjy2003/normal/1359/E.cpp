#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
int n,k,fac[500050],ifac[500050],ans;
int C(int a,int b)
{
	if(a<b)return 0;
	return 1ll*fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}
int main()
{
	scanf("%d %d",&n,&k);
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=kpow(fac[n],mod-2);
	for(int i=n;i;--i)ifac[i-1]=1ll*ifac[i]*i%mod;
	for(int i=1;i<=n;++i)ans=(ans+C(n/i-1,k-1))%mod;
	printf("%d",ans);
	return 0;
}