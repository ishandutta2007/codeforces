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
bool upmax(long long &x,long long y){return x<y?x=y,1:0;}
int n,x[5050],y[5050];
long long qdis(int a,int b){return 1ll*(x[a]-x[b])*(x[a]-x[b])+1ll*(y[a]-y[b])*(y[a]-y[b]);}
bool used[5050];
int main()
{
	n=read();
	for(int i=1;i<=n;++i)x[i]=read(),y[i]=read();
	long long maxd=0;
	int px=0,py=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(upmax(maxd,qdis(i,j)))px=i,py=j;
	print(px),putc(' '),print(py),putc(' ');
	used[px]=used[py]=1;
	int p=py;
	for(int i=3;i<=n;++i)
	{
		int q=0;maxd=0;
		for(int j=1;j<=n;++j)if(!used[j]&&upmax(maxd,qdis(p,j)))q=j;
		print(q),putc(' '),used[q]=1,p=q;
	}
	flush();
	return 0;
}