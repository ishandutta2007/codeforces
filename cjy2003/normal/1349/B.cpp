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
int T,n,k,a[100010],sum[100010];
int main()
{
	T=read();
	while(T--)
	{
		n=read(),k=read();
		for(int i=1;i<=n;++i)a[i]=read();
		bool flag=0;
		for(int i=1;i<=n;++i)flag|=a[i]==k;
		if(!flag)
		{
			printf("no\n");
			continue;
		}
		if(n==1)
		{
			printf("yes\n");
			continue;
		}
		flag=0;
		int mi=0x3f3f3f3f;
		for(int i=1;i<=n;++i)
		{
			sum[i]=sum[i-1];
			if(a[i]>=k)++sum[i];
			else --sum[i];
			if(sum[i]>mi)
			{
				flag=1;
				printf("yes\n");
				break;
			}
			mi=min(mi,sum[i-1]);
		}
		if(!flag)printf("no\n");
	}
	flush();
	return 0;
}