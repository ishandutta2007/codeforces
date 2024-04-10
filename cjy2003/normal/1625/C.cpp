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
int n,l,m,dp[510][510],d[510],a[510];
int main()
{
	n=read(),l=read(),m=read();
	for(int i=1;i<=n;++i)d[i]=read();
	for(int i=1;i<=n;++i)a[i]=read();
	memset(dp,0x3f,sizeof(dp));
	dp[1][1]=0;
	for(int i=2;i<=n;++i)
		for(int j=2;j<=i;++j)
			for(int k=1;k<i;++k)dp[i][j]=min(dp[i][j],dp[k][j-1]+a[k]*(d[i]-d[k]));
	int ans=0x3f3f3f3f;
	for(int i=n-m;i<=n;++i)
		for(int j=1;j<=n;++j)
			ans=min(ans,dp[j][i]+a[j]*(l-d[j]));
	print(ans);
	flush();
	return 0;
}