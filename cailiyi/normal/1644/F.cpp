#include<bits/stdc++.h>
#define N 200000
#define mod 998244353
using namespace std;
int n,k,ans;
inline int quick_pow(int x,int b)
{
    int ret=1;
    while(b)
    {
        if(b&1) ret=1ll*ret*x%mod;
        x=1ll*x*x%mod,b>>=1;
    }
    return ret;
}
inline int inv(int x) {return quick_pow(x,mod-2);}
int fac[N+5],ifac[N+5];
int p[N+5],cnt,mu[N+5];
bool vis[N+5];
inline void init(int n=N)
{
    fac[0]=1;for(int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
    ifac[n]=inv(fac[n]);for(int i=n;i;--i) ifac[i-1]=1ll*ifac[i]*i%mod;
    mu[1]=1;
    for(int i=2;i<=n;++i)
    {
        if(!vis[i]) p[++cnt]=i,mu[i]=mod-1;
        for(int j=1;j<=cnt && i*p[j]<=n;++j)
        {
            vis[i*p[j]]=1;
            if(!(i%p[j]))
            {
                mu[i*p[j]]=0;
                break;
            }
            mu[i*p[j]]=(mod-mu[i])%mod;
        }
    }
}
inline int C(int n,int m)
{
    if(!m) return 1;
    return n>=m && m>0?1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod:0;
}
const int G=3,inv_G=inv(G);
inline void NTT(int *a,int lim,int opt=1)
{
	static int rev[N*4],inv_lim;
	for(int i=0;i<lim;++i)
	{
		rev[i]=rev[i>>1]>>1|((i&1)*lim>>1);
		if(i<rev[i]) swap(a[i],a[rev[i]]);
	}
	for(int len=1,gn,temp;len<lim;len<<=1)
	{
		gn=quick_pow(opt==1?G:inv_G,(mod-1)/(len<<1));
		for(int i=0;i<lim;i+=len<<1)
			for(int j=0,gp=1;j<len;++j,gp=1ll*gp*gn%mod)
			{
				temp=1ll*gp*a[i+j+len]%mod;
				a[i+j+len]=(a[i+j]-temp+mod)%mod;
				a[i+j]=(a[i+j]+temp)%mod;
			}
	}
	if(opt==-1)
	{
		inv_lim=inv(lim);
		for(int i=0;i<lim;++i)
			a[i]=1ll*inv_lim*a[i]%mod;
	}
}
int f[N*4],g[N*4],lim;
inline void get(int n)
{
    for(int i=0;i<=n;++i)
		f[i]=1ll*quick_pow(i,n)*ifac[i]%mod,
		g[i]=i&1?mod-ifac[i]:ifac[i];
	for(lim=1;lim<=n<<1;lim<<=1);
    for(int i=n+1;i<lim;++i) f[i]=g[i]=0;
	NTT(f,lim),NTT(g,lim);
	for(int i=0;i<lim;++i)
		f[i]=1ll*f[i]*g[i]%mod;
	NTT(f,lim,-1);
}
inline int solve(int n)
{
    int ret=0;get(n);
    for(int i=1;i<=min(n,k);++i)
        ret=(ret+f[i])%mod;
    return ret;
}
int main()
{
    scanf("%d %d",&n,&k),init(n);
    for(int i=1;i<=n;++i)
        if(mu[i]) ans=(ans+1ll*mu[i]*(solve((n-1)/i+1)-1))%mod;
    printf("%d",ans+(n==1 || k==1));
    return 0;
}