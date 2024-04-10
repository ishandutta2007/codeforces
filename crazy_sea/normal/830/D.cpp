#include<cstdio>
#define ll long long
using namespace std;
const int N=410,mod=1e9+7;
ll fac[N],ifac[N],f[N][N];
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
ll C(int a,int b){return fac[a]*ifac[b]%mod*ifac[a-b]%mod;}
int n;
void add(ll&a,ll b){a=(a+b)%mod;}
int main()
{
	scanf("%d",&n);
	fac[0]=ifac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	ifac[n]=fastpow(fac[n],mod-2);
	for(int i=n-1;i;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
	f[0][0]=f[0][1]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=n;j++)
			for(int k=0;j+k<=n;k++)
				add(f[i][j+k],f[i-1][j]*f[i-1][k]%mod*C(j+k,j)%mod*(1+2*(j+k)));
		for(int j=0;j<=n;j++)
			for(int k=0;j+k+1<=n;k++)
				add(f[i][j+k+1],f[i-1][j]*f[i-1][k]%mod*C(j+k,j)%mod*(j+k+1));
		for(int j=0;j<=n;j++)
			for(int k=0;j+k-1<=n;k++)
				if(j||k) add(f[i][j+k-1],f[i-1][j]*f[i-1][k]%mod*C(j+k,j)%mod*(j+k-1));
	}
	printf("%lld",f[n-1][1]);
}