#include<cstdio>
#include<cmath>
#define N 1000010
#define mod 1000000007
#define ll long long
using namespace std;
ll fastpow(ll a,int b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return ans;
}
ll n,p[N],q[N],f[N],ans,sign,fact[N];
int k,Q;
ll getans(int n)
{
	if(n<=k+2) return f[n];
	p[0]=q[k+3]=1;
	for(int i=1;i<=k+2;i++) p[i]=p[i-1]*(n-i)%mod;
	for(int i=k+2;i>=1;i--) q[i]=q[i+1]*(n-i)%mod;
	ans=0;
	for(int i=1;i<=k+2;i++)
	{
		if((k+2-i)&1) sign=-1;
		else sign=1;
		ans=(ans+p[i-1]*q[i+1]%mod*f[i]%mod*fact[i-1]%mod*fact[k+2-i]%mod*sign+mod)%mod;
	}
	return ans;
}
int main()
{
	fact[0]=1;
	scanf("%d%d",&n,&k);
	if(k==0){printf("%d",n);return 0;} 
	for(int i=1;i<=k+2;i++)
	{
		f[i]=(f[i-1]+fastpow(i,k))%mod;
		fact[i]=fact[i-1]*i%mod;
	}
	for(int i=1;i<=k+2;i++)
	{
		fact[i]=fastpow(fact[i],mod-2);
	}
	printf("%lld",getans(n));
	return 0;
}