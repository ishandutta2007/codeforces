#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
inline int pl(int x,int y){return (x+=y)>=mod?x-mod:x;}
int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
int n,fac[1000010],ifac[1000010],ans,bs[100010],gs[100010],C[1000010];
int getpow(long long x)
{
	x%=(mod-1);
	if(x<0)x+=mod-1;
	return 1ll*bs[x/100000]*gs[x%100000]%mod;
}
int main()
{
	scanf("%d",&n);
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=kpow(fac[n],mod-2);
	for(int i=n;i;--i)ifac[i-1]=1ll*ifac[i]*i%mod;
	gs[0]=1;bs[0]=1;
	for(int i=1;i<=100000;++i)gs[i]=3ll*gs[i-1]%mod;
	bs[1]=gs[100000];
	for(int i=2;i<=100000;++i)bs[i]=1ll*bs[i-1]*bs[1]%mod;
	for(int i=0;i<=n;++i)C[i]=1ll*fac[n]*ifac[i]%mod*ifac[n-i]%mod;
	for(int i=0;i<n;++i)
	{
		int w=pl(kpow(getpow(i)-1,n),mod-getpow(1ll*i*n));
		if(n&1)w=mod-w;
		if(i&1)ans=(ans+1ll*(mod-C[i])*w)%mod;
		else ans=(ans+1ll*C[i]*w)%mod;
	}
	ans=3ll*ans%mod;
	for(int i=1;i<=n;++i)
	{
		if(i&1)ans=(ans+1ll*(mod-2)*C[i]%mod*getpow(i+1ll*(n-i)*n))%mod;
		else ans=(ans+2ll*C[i]%mod*getpow(i+1ll*(n-i)*n))%mod;
	}
	printf("%d",mod-ans);
	return 0;
}