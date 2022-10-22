#include<cstdio>
#define ll long long
using namespace std;
const int mod=998244353,N=3e5+10;
int n,T;
ll f[N],g[N],fac[N],ifac[N];
ll C(int a,int b){return fac[a]*ifac[b]%mod*ifac[a-b]%mod;}
ll fastpow(ll a,int b)
{
	ll s=1;
	while(b)
	{
		if(b&1) s=s*a%mod;
		a=a*a%mod, b>>=1;
	}
	return s;
}
void init(int n)
{
	f[0]=f[1]=g[0]=fac[0]=ifac[0]=1;
	for(int i=2;i<=n;i++) f[i]=(f[i-1]+f[i-2]*(i-1))%mod;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	ifac[n]=fastpow(fac[n],mod-2);
	for(int i=n-1;i;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++) g[i]=2*g[i-1]*(2*i-1)%mod;
}
int main()
{
	scanf("%d",&T);
	init(3e5);
	while(T--)
	{
		scanf("%d",&n);
		ll ans=0;
		for(int i=0;i*4<=n;i++)
			ans=(ans+C(n-i*2,i*2)*f[n-i*4]%mod*g[i])%mod;
		printf("%lld\n",ans);
	}
}