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
int T,n;
int a[200020],l[200020],r[200020],u[200020],cnt[200020];
int qmin(int x,int y)
{
	int s=0x3f3f3f3f;
	for(int i=x;i<=y;++i)s=min(s,cnt[i]);
	return s;
}
int main()
{
	for(int i=0;(1<<i)<=200000;++i)u[1<<i]=i;
	u[200000]=18;
	for(int i=200000;i>1;--i)if(!u[i])u[i]=u[i+1];
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i)a[i]=read(),++cnt[a[i]];
		sort(a+1,a+1+n);
		for(int i=1;i<=n;++i)l[i]=a[i]!=a[i-1]?i:l[i-1];
		l[n+1]=n+1;
		a[n+1]=0;
		for(int i=n;i;--i)r[i]=a[i]!=a[i+1]?i:r[i+1];
		int ans=(1<<u[n])+2;
		for(int i=0;(1<<i)<n;++i)
		{
			int cl=l[(1<<i)+1]-1;
			ans=min(ans,(1<<i)+(1<<u[n-cl])+1);
			for(int j=0;(1<<j)<n;++j)
			{
				int cr=r[n-(1<<j)]+1;
				if(cl+1<cr)ans=min(ans,(1<<i)+(1<<j)+(1<<u[cr-cl-1]));
				else ans=min(ans,(1<<i)+(1<<j)+(1<<u[qmin(a[cr-1],a[cl+1])]));
			}
		}
		for(int j=0;(1<<j)<n;++j)
		{
			int cr=r[n-(1<<j)]+1;
			ans=min(ans,1+(1<<u[cr-1])+(1<<j));
		}
		printf("%d\n",ans-n);
		memset(cnt+1,0,n<<2);
	}
	flush();
	return 0;
}