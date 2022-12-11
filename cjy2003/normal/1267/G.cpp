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
const double eps=1e-10;
int n,x,c[110];
double f[110],ans;
double dp[110][10010];
int main()
{
	n=read(),x=read();
	for(int i=1;i<=n;++i)c[i]=read();
	for(int i=0;i<n;++i)f[i]=(2.0*n-i)/(2.0*n-2.0*i)*x;
//	for(int i=0;i<n;++i)printf("%lf\n",f[i]);
	int sum=0;
	for(int i=1;i<=n;++i)sum+=c[i];	
	dp[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=i;j;--j)
			for(int k=c[i];k<=sum;++k)
				dp[j][k]+=dp[j-1][k-c[i]]*j/(n-j+1);
//	for(int i=0;i<n;++i)
//		for(int j=0;j<=sum;++j)
//			if(dp[i][j]>eps)printf("%d %d %lf\n",i,j,dp[i][j]);
	for(int i=0;i<n;++i)
		for(int j=0;j<=sum;++j)
			ans+=dp[i][j]*min(1.0*(sum-j)/(n-i),f[i]);
	printf("%.12lf",ans);
	flush();
	return 0;
}