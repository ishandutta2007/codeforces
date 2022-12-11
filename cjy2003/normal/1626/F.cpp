#include<cstdio>
#include<cstring>
#include<algorithm>
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
	inline void flush(){fwrite(buff,1,T-buff,stdout);T=buff;}
	inline void putc(char ch){if(T==buff+N)flush();*T++=ch;}
	template<typename T>
	inline void print(T x)
	{
		if(!x){putc('0');return;}
		if(x<0)putc('-'),x=-x;
		static int st[30],tp;
		while(x)st[++tp]=x%10,x/=10;
		while(tp)putc(st[tp--]^48);
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
int n,a,cnt[720720],x,y,k,m,ans,po[20];
int f[18][720720],g[18][720720],h[18][720720];
int sf[720720],sg[720720],sh[720720];
int main()
{
	scanf("%d %d %d %d %d %d",&n,&a,&x,&y,&k,&m);
	++cnt[a%720720];
	add(ans,a);
	for(int i=1;i<n;++i)
	{
		a=(1ll*a*x+y)%m;
		++cnt[a%720720];
		add(ans,a);
	}
	ans=1ll*ans*k%mod;
	for(int i=1;i<k;++i)ans=1ll*ans*n%mod;
	po[0]=1;
	for(int i=1;i<=k;++i)po[i]=1ll*po[i-1]*(n-1)%mod;
	for(int i=1;i<=k;++i)
	{
		int sumh=0;
		for(int j=0;j<720720;++j)
		{
			f[i][j]=(sf[j]+1ll*po[i-1]*cnt[j])%mod;
			g[i][j]=sg[j];
			h[i][j]=pl(sh[j],g[i][j]);
			add(sumh,h[i][j]);
		}
		ans=(ans+1ll*(mod-sumh)*po[k-i])%mod;
		for(int j=0;j<720720;++j)
		{
			sf[j]=1ll*sf[j]*(n-1)%mod;
			sg[j]=1ll*sg[j]*(n-1)%mod;
			sh[j]=1ll*sh[j]*(n-1)%mod;
		}
		for(int j=0;j<720720;++j)
		{
			add(sf[j-j%i],f[i][j]);
			sg[j-j%i]=(sg[j-j%i]+g[i][j]+1ll*f[i][j]*(j%i))%mod;
			sh[j-j%i]=(sh[j-j%i]+h[i][j])%mod;
		}
	}
	printf("%d",ans);
	flush();
	return 0;
}