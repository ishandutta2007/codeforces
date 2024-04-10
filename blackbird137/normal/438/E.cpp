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

const int N=8e5+5,G=3,IG=332748118,mod=998244353;
int n,m,f[N],rev[N],jc[N],inv[N];

inline void INIT(int x);
inline int init(int n);
inline int q_pow(int a,int b);
inline void mul(int *a,int *b,int n);
inline void ntt(int *a,int id,int n);
inline void to_inv(int *a,int n);
inline void to_sqrt(int *a,int n);
inline void times(int *a,int *b,int l,int p);
inline void div(int *a,int *b,int n,int m);
inline void dao(int *a,int n);
inline void jifen(int *a,int n);
inline void to_ln(int *a,int n);
inline void to_exp(int *a,int n);

signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
		f[read()]=1;
	for(int i=1;i<=m;++i)
		f[i]=(mod-4*f[i])%mod;
	f[0]=1;to_sqrt(f,m);
	f[0]=(f[0]+1)%mod;
	to_inv(f,m);
	for(int i=1;i<=m;++i)
		write(f[i]*2%mod),puts("");
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

inline void to_inv(int *a,int n)
{
	int nn=init(n);
	static int w[N],r[N],p[N];
	w[0]=q_pow(a[0],mod-2);
	for(int l=2;l<=nn;l<<=1)
	{
		for(int i=0;i<(l>>1);++i)
			r[i]=(w[i]<<1)%mod;
		cpy(p,a,l);
		ntt(w,1,l<<1);mul(w,w,l<<1);
		ntt(p,1,l<<1);mul(w,p,l<<1);
		ntt(w,-1,l<<1);clr(w+l,l);
		for(int i=0;i<l;++i)
			w[i]=(r[i]-w[i]+mod)%mod;
	}
	cpy(a,w,n+1);clr(p,nn<<1);
	clr(w,nn<<1);clr(r,nn<<1);
}

inline void to_sqrt(int *a,int n)
{
	int nn=init(n);
	static int b1[N],b2[N];
	b1[0]=1;
	for(int l=2;l<=nn;l<<=1)
	{
		for(int i=0;i<(l>>1);++i)
			b2[i]=(b1[i]<<1)%mod;
		to_inv(b2,l);
		ntt(b1,1,l);
		mul(b1,b1,l);
		ntt(b1,-1,l);
		for(int i=0;i<l;++i)
			b1[i]=(b1[i]+a[i])%mod;
		times(b1,b2,l,l);
	}
	cpy(f,b1,n+1);
	clr(b1,nn<<1);clr(b2,nn<<1);
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

inline void div(int *a,int *b,int n,int m)
{
	static int aa[N],bb[N];
	cpy(aa,a,n+1);cpy(bb,b,m+1);
	for(int i=0;i<=(n>>1);++i)
		swap(aa[i],aa[n-i]);
	for(int i=0;i<=(m>>1);++i)
		swap(bb[i],bb[m-i]);
	clr(aa+n-m+2,m-1);
	clr(bb+n-m+2,n-1); 
	to_inv(bb,n-m+1);
	times(bb,aa,n-m+1,n-m+1);
	for(int i=0;i<=((n-m)>>1);++i)
		swap(bb[i],bb[n-m-i]);
	times(b,bb,n+1,n+1);
	for(int i=0;i<m;++i)
		b[i]=(a[i]-b[i]+mod)%mod;
	clr(b+m,n-m+1);
	cpy(a,bb,n-m+1);
	clr(a+n-m+1,m);
	clr(aa,n+1);clr(bb,m+1);
}

inline void dao(int *a,int n)
{
	for(int i=0;i<n;++i)
		a[i]=a[i+1]*1ll*(i+1)%mod;
	a[n]=0;
}

inline void jifen(int *a,int n)
{
	for(int i=n;i;--i)
		a[i]=a[i-1]*1ll*q_pow(i,mod-2)%mod;
	a[0]=0;
}

inline void to_ln(int *a,int n)
{
	static int b[N];
	cpy(b,a,n+1);
	to_inv(b,n);
	dao(a,n);
	times(a,b,n,n);
	jifen(a,n);
	clr(b,n+1);
}

inline void to_exp(int *a,int n)
{
	static int b1[N],b2[N];
	int m=init(n);
	b2[0]=1;
	for(int l=2;l<=m;l<<=1)
	{
		int len=l>>1;
		cpy(b1,b2,len);
		to_ln(b1,l);
		for(int i=0;i<l;++i)
			b1[i]=(a[i]-b1[i]+mod)%mod;
		b1[0]=(b1[0]+1)%mod;
		times(b2,b1,l,l);
	}
	cpy(a,b2,n+1);
	clr(b1,m);clr(b2,m);
}