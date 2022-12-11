#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
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
namespace mcmf
{
	const int S=0,T=1;
	struct edge
	{
		int nxt,to,f;
		double w;
	}e[500010];
	int head[1010],num=1,fb[1010],tot=1;
	double dis[1010];
	inline void add(int from,int to,int f,double w){e[++num]=edge{head[from],to,f,w};head[from]=num;}
	inline void ADD(int from,int to,int f,double w){add(from,to,f,w),add(to,from,0,-w);}
	bool spfa()
	{
		queue<int>q;
		static bool in[1010];
		for(int i=0;i<tot;++i)dis[i]=1e18;
		q.push(S);dis[S]=0;
		while(!q.empty())
		{
			int x=q.front();q.pop();in[x]=0;
			for(int i=head[x],y;i;i=e[i].nxt)
				if(e[i].f&&dis[x]+e[i].w<dis[y=e[i].to])
				{
					dis[y]=dis[x]+e[i].w,fb[y]=i;
					if(!in[y])in[y]=1,q.push(y);
				}
		}
		return dis[T]!=1e18;
	}
}using namespace mcmf;
struct point
{
	int x,y;
}p[410];
double qdis(point x,point y){return sqrt(1ll*(x.x-y.x)*(x.x-y.x)+1ll*(x.y-y.y)*(x.y-y.y));}
int n;
int main()
{
	n=read();
	for(int i=1;i<=n;++i)p[i].x=read(),p[i].y=read();
	int mx=1,cnt=1;
	for(int i=2;i<=n;++i)
	{
		if(p[i].y>p[mx].y)mx=i,cnt=1;
		else if(p[i].y==p[mx].y)++cnt;
	}
	if(cnt>=2)return printf("-1"),0;
	for(int i=1;i<=n;++i)
	{
		ADD(S,i+1,2,0);
		ADD(i+1+n,T,1,0);
		for(int j=1;j<=n;++j)if(p[j].y<p[i].y)ADD(i+1,j+n+1,1,qdis(p[i],p[j]));
	}
	ADD(S,mx+1+n,1,0);
	tot=2*n+2;
	int flow=0;
	double cost=0;
	while(spfa())
	{
		++flow;cost+=dis[T];
		int x=T;
		while(x!=S)--e[fb[x]].f,++e[fb[x]^1].f,x=e[fb[x]^1].to;
	}
	if(flow!=n)printf("-1");
	else printf("%.12lf",cost);
	flush();
	return 0;
}