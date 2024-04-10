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
const int mod=1000000007;
int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
int n,k,s[5050][5050],ans;
int main()
{
	n=read(),k=read();
	for(int i=0;i<=k;++i)
	{
		s[i][0]=i==0;
		for(int j=1;j<=i;++j)s[i][j]=(s[i-1][j-1]+1ll*s[i-1][j]*j)%mod;
	}
	int po2=kpow(2,n),c=1;
	for(int i=0;i<=k;++i)
	{
		ans=(ans+1ll*po2*c%mod*s[k][i])%mod;
		po2=1ll*po2*500000004%mod;
		c=1ll*(n-i)*c%mod;
	}
	printf("%d",ans);
	flush();
	return 0;
}