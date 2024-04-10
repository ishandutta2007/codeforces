#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define re register int
#define ak *
#define inf 1e9
#define ll long long
const ll p=1e9+7;
char qwq;
ll n,m,k,a[5000005],f[5000005],g[5000005],now,ans;
inline ll qpow(ll x,ll y,ll z=1)
{
	x%=p;
	for(;y;y>>=1,x=(x*x)%p) z=(y&1)?(z*x)%p:z;
	return z;
}
inline ll inv(ll x) {return qpow(x%p,p-2);}
inline void solve()
{
	now=f[0]=g[0]=1;
	for(re i=1;i<=k+2;i++) 
	now=now*(n-i)%p,f[i]=f[i-1]*i%p,g[i]=-g[i-1]*i%p;
	for(re i=1;i<=k+2;i++)
	ans=(ans+a[i]*now%p*inv(n-i)%p*inv(f[i-1]*g[k+2-i]%p))%p;
}
int main()
{
	scanf("%lld %lld",&n,&k);
	for(re i=1;i<=k+2&&i<=n;i++) a[i]=(a[i-1]+qpow(i,k))%p;
	if(n<=k+2) return printf("%lld\n",a[n]),0;
	solve();printf("%lld",(ans+p)%p);
	return 0;
}