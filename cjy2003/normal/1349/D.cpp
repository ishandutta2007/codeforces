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
	void flush(){fwrite(buff,1,T-buff,stdout);T=buff;}
	inline void putc(char ch){if(T==buff+N)flush();*T++=ch;}
	inline void print(int x)
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
int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
int n,a[100010],f[300030],inv[300030],sum,ans;
int main()
{
	inv[1]=1;
	for(int i=2;i<=300000;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	n=read();
	for(int i=1;i<=n;++i)a[i]=read(),sum+=a[i];
	f[0]=n-1;
	for(int i=1;i<sum;++i)f[i]=(1ll*i*inv[sum]%mod*f[i-1]+1)%mod*sum%mod*(n-1)%mod*inv[sum-i]%mod;
	for(int i=sum-1;~i;--i)add(f[i],f[i+1]);
	for(int i=1;i<=n;++i)ans=(ans+f[a[i]])%mod;
	ans=(ans-1ll*(n-1)*f[0])%mod*inv[n]%mod;
	if(ans<0)ans+=mod;
	// for(int i=0;i<=sum;++i)printf("%d ",e[i]);printf("\n");
	printf("%d",ans);
	flush();
	return 0;
}