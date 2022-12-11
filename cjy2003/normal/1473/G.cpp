#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
namespace io
{
	const int N=1<<20;
	char buf[N],*t1=buf,*t2=buf;
	#ifdef cjy
	#define getc() getchar()
	#else
	#define getc() t1==t2&&(t2=(t1=buf)+fread(buf,1,N,stdin),t1==t2)?EOF:*t1++
	#endif
	inline int read()
	{
		static int an,f;an=0,f=1;
		static char ch;ch=getc();
		while(ch<48||ch>57)ch=='-'?f=-1:0,ch=getc();
		while(ch>=48&&ch<=57)an=(an<<3)+(an<<1)+(ch^48),ch=getc();
		return an*f;
	}
	char buff[N],*T=buff;
	void flush(){fwrite(buff,1,T-buff,stdout);T=buff;}
	inline void putc(char ch){if(T==buff+N)flush();*T++=ch;}
	template<typename o>
	inline void print(o x)
	{
		if(x<0)putc('-'),x=-x;
		if(!x)return putc('0'),void();
		static int st[20],tp;
		while(x)st[++tp]=x%10,x/=10;
		while(tp)putc(st[tp]^48),--tp;
	}
}
using io::read;
using io::putc;
using io::flush;
using io::print;
const int mod=998244353;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
inline int pl(int x,int y){return (x+=y)>=mod?x-=mod:x;}
int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
namespace poly
{
	int w[262144],r[262144];
	void init()
	{
		for(int len=1;len<262144;len<<=1)
		{
			int tmp=kpow(3,(mod-1)/len/2);
			w[len]=1;
			for(int j=1;j<len;++j)w[len+j]=1ll*w[len+j-1]*tmp%mod;
		}
	}
	void ntt(int f[],int opt,int lim)
	{
		static int r[262144];
		static unsigned long long F[262144];
		for(int i=0;i<lim;++i)r[i]=(r[i>>1]>>1)|(i&1?lim>>1:0),F[i]=f[r[i]];
		for(int len=1;len<lim;len<<=1)
			for(int j=0;j<lim;j+=len<<1)
				for(int k=0;k<len;++k)
				{
					unsigned long long x=F[j+k],y=F[j+k+len]*w[k+len]%mod;
					F[j+k]=x+y,F[j+k+len]=x+mod-y;
				}
		for(int i=0;i<lim;++i)f[i]=F[i]%mod;
		if(opt==-1)
		{
			reverse(f+1,f+lim);
			int inv=kpow(lim,mod-2);
			for(int i=0;i<lim;++i)f[i]=1ll*f[i]*inv%mod;
		}
	}
	void mul(int a[],int b[],int c[],int na,int nb)
	{
		static int f[262144],g[262144];
		int lim=1;
		while(lim<na+nb-1)lim<<=1;
		memcpy(f,a,na<<2),memcpy(g,b,nb<<2);
		ntt(f,1,lim),ntt(g,1,lim);
		for(int i=0;i<lim;++i)f[i]=1ll*f[i]*g[i]%mod;
		ntt(f,-1,lim);
		memcpy(c,f,lim<<2);
		memset(f,0,lim<<2),memset(g,0,lim<<2);
	}
}
int q,f[200020],g[200020],n,fac[200020],ifac[200020];
int C(int a,int b)
{
	if(b<0||a<b)return 0;
	return 1ll*fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}
int main()
{
	fac[0]=1;
	for(int i=1;i<=200000;++i)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[200000]=kpow(fac[200000],mod-2);
	for(int i=200000;i;--i)ifac[i-1]=1ll*ifac[i]*i%mod;
	poly::init();
	q=read();
	f[0]=1,n=1;
	int a,b;
	while(q--)
	{
		a=read(),b=read();
		for(int i=b-n+1;i<=n+a-1;++i)g[i-b+n-1]=C(a+b,i);
		// for(int i=0;i<n+a-1-b+n;++i)printf("%d ",g[i]);printf("\n");
		poly::mul(f,g,f,n,n+a-1-b+n);
		for(int i=0;i<=n+a-b;++i)f[i]=f[i+n-1];
		n=n+a-b;
		// for(int i=0;i<n;++i)printf("%d ",f[i]);printf("\n");
	}
	int ans=0;
	for(int i=0;i<n;++i)add(ans,f[i]);
	printf("%d",ans);
	flush();
	return 0;
}