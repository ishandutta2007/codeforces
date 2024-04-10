#include<cstdio>
#include<algorithm>
#define ll long long
#define mod 998244353
#define N 1000010
using namespace std;
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
namespace poly{
	ll inv3=fastpow(3,mod-2),inv;
	ll a[N],b[N],c[N],d[N],e[N],g[N];
	int r[N];
	void ntt(ll*a,int lim,int type)
	{
		ll w,wn,x,y;
		for(int i=1;i<lim;i++)
			if(i<r[i]) swap(a[i],a[r[i]]);
		for(int i=1;i<lim;i*=2)
		{
			wn=fastpow(type?3:inv3,(mod-1)/i/2);
			for(int j=0;j<lim;j+=(i*2))
			{
				w=1;
				for(int k=0;k<i;k++,w=w*wn%mod)
				{
					x=a[j+k];
					y=a[j+k+i]*w%mod;
					a[j+k]=(x+y)%mod;
					a[j+k+i]=(x-y+mod)%mod;
				}
			}
		}
		if(type) return;
		inv=fastpow(lim,mod-2);
		for(int i=0;i<lim;i++)
			a[i]=a[i]*inv%mod;
	}
	void init(int&n)
	{
		int l=0,lim=1;
		while(lim<n) lim<<=1,l++;
		for(int i=0;i<lim;i++)
			r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
		n=lim;
	}
	int len;
	void getinv(ll *a,int n)
	{
		for(int i=0;i<=n*4;i++) c[i]=b[i]=0;
		b[0]=fastpow(a[0],mod-2);
		for(int i=2;i<n*2;i<<=1)
		{
			len=i<<1;
			init(len);
			ntt(b,len,1);
			for(int j=0;j<i;j++) c[j]=a[j];
			ntt(c,len,1);
			for(int j=0;j<len;j++) b[j]=b[j]*(2-c[j]*b[j]%mod+mod)%mod;
			ntt(b,len,0);
			for(int j=i;j<len;j++) b[j]=0;
		}
		for(int i=0;i<=n;i++) a[i]=b[i];
		for(int i=n+1;i<len;i++) a[i]=0;
	}
	void sqrt(ll*a,int n)
	{
		g[0]=1;
		for(int i=2;i<=n*2;i<<=1)
		{
			for(int j=0;j<i;j++) d[j]=g[j],e[j]=a[j];
			getinv(d,i-1);
			len=i<<1;
			init(len);
			ntt(g,len,1);
			ntt(e,len,1);
			ntt(d,len,1);
			for(int j=0;j<len;j++) g[j]=(g[j]+d[j]*e[j]%mod)*fastpow(2,mod-2)%mod;
			ntt(g,len,0);
			for(int j=i;j<len;j++) g[j]=0;
		}
		for(int i=0;i<=n;i++) a[i]=g[i];
	}
	void mult(ll*f,ll*g,int n,int m)
	{
		len=n+m+1;
		init(len);
		ntt(f,len,1);
		ntt(g,len,1);
		for(int i=0;i<len;i++) f[i]=f[i]*g[i]%mod;
		ntt(f,len,0);
		ntt(g,len,0);
	}
	void div(ll*f,ll*g,int n,int m)
	{
		for(int i=0;i<=m;i++) a[i]=g[m-i];
		int len1=n-m;
		getinv(a,len1);
		len=len1*2+1;init(len);
		for(int i=0;i<=n;i++) b[i]=f[n-i];
		for(int i=len1+1;i<=len;i++) a[i]=b[i]=0;
		init(len);
		ntt(a,len,1);
		ntt(b,len,1);
		for(int i=0;i<len;i++) a[i]=a[i]*b[i]%mod;
		ntt(a,len,0);
		for(int i=0;i*2<=len1;i++) swap(a[i],a[len1-i]);
		len=n+1;init(len);
		for(int i=len1+1;i<=len;i++) a[i]=0;
		mult(g,a,m,len1);
		for(int i=0;i<m;i++) g[i]=(f[i]-a[i]+mod)%mod;
		for(int i=0;i<=len1;i++) f[i]=a[i];
		for(int i=len1+1;i<=n;i++) f[i]=0;
		for(int i=m;i<=n;i++) g[i]=0;
	}
}
using namespace poly;
ll f[N];
int n,m,x;
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++) scanf("%d",&x),f[x]=1;
	for(int i=1;i<=n;i++) f[i]=mod-4*f[i];f[0]=1;
	poly::sqrt(f,n);
	f[0]++;
	poly::getinv(f,n+1);
	for(int i=1;i<=n;i++) printf("%lld ",f[i]*2%mod);
	return 0;
}