#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=8e5+5,G=3,mod=998244353;
int n,a,b,f[N],g[N],h[N],rev[N],jc[N],inv[N];

inline void INIT(int x);
inline int init(int n);
inline int q_pow(int a,int b);
inline void mul(int *a,int *b,int n);
inline void ntt(int *a,int id,int n);
inline void times(int *a,int *b,int l,int p);

inline void solve(int *f,int n)
{
	if(n==1) return f[1]=1,void();
	if(n%2==1)
	{
		solve(f,n-1);
		for(int i=n;i>=1;--i)
			f[i]=(f[i-1]+f[i]*(n-1)%mod)%mod;
		f[0]=f[0]*(n-1)%mod;return;
	}
	else
	{
		int nn=n/2;
		solve(f,nn);
		for(int i=0,j=1;i<=nn;++i,j=j*nn%mod)
		{
			g[i]=f[i]*jc[i]%mod;
			h[i]=j*inv[i]%mod;
		}
		reverse(g,g+nn+1);
		times(g,h,n,nn+1);
		for(int i=0;i<=nn;++i)
			h[i]=g[nn-i]*inv[i]%mod;
		times(f,h,n,n+1);
		int tmp=init(n);
		clr(g+nn+1,tmp-nn-1);
		clr(h+nn+1,tmp-nn-1);
	}
}

inline int C(int n,int m)
{
	return n<m?0:jc[n]*inv[m]%mod*inv[n-m]%mod; 
}

signed main()
{
	n=read();
	a=read();b=read();
	if(a==0||b==0)
	{
		puts("0");
		return 0;
	}
	if(n==1)
	{
		puts("1");
		return 0;
	}
	INIT(200000);solve(f,n-1);
	write(f[a+b-2]*C(a+b-2,a-1)%mod);
	return 0;
}

inline void INIT(int x)
{
	jc[0]=1;
	for(int i=1;i<=x;++i)
		jc[i]=jc[i-1]*1ll*i%mod;
	inv[x]=q_pow(jc[x],mod-2);
	for(int i=x-1;i>=0;--i)
		inv[i]=inv[i+1]*1ll*(i+1)%mod;
}

inline int init(int n)
{
	int res=1;
	for(;res<=n;res<<=1);
	return res;
}

inline int q_pow(int a,int b)
{
	register int c=1;
	while(b)
	{
		if(b&1) c=a*1ll*c%mod;
		a=a*1ll*a%mod;b>>=1;
	}
	return c;
}

inline void mul(int *a,int *b,int n)
{
	for(int i=0;i<n;++i)
		a[i]=a[i]*1ll*b[i]%mod;
}

inline void ntt(int *a,int id,int n)
{
	for(register int i=0;i<n;++i)
		rev[i]=(rev[i>>1]>>1)|((i&1)?n>>1:0);
	static int w[N];w[0]=1;
	for(register int i=0;i<n;++i)
		if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(register int l=2;l<=n;l<<=1)
	{
		register int len=l>>1,w0;
		w0=q_pow(G,(id*(mod-1)/l+mod-1)%(mod-1));
		for(register int i=1;i<len;++i)
			w[i]=w[i-1]*1ll*w0%mod;
		for(register int i=0;i<n;i+=l)
			for(register int k=i,j=0;k<i+len;++k,++j)
			{
				int tmp=w[j]*1ll*a[k+len]%mod;
				a[k+len]=(a[k]-tmp+mod)%mod;
				a[k]=(a[k]+tmp)%mod;
			}
	}
	if(id==-1)
	{
		int tmp=q_pow(n,mod-2);
		for(int i=0;i<n;++i)
			a[i]=a[i]*1ll*tmp%mod;
	}
	
}

inline void times(int *a,int *b,int l,int p)
{
	int ll=init(l<<1);
	static int c[N];cpy(c,b,ll);
	ntt(a,1,ll);
	ntt(c,1,ll);
	mul(a,c,ll);
	ntt(a,-1,ll);
	clr(c,0);clr(a+p,ll-p);clr(b+p,ll-p);
}