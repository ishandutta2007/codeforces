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
const int S=0,T=1,inf=0x3f3f3f3f;
struct edge
{
	int nxt,to,f;
}e[1500000];
int head[304000],cur[304000],num=1,dep[304000],tot;
void add(int from,int to,int f){e[++num]=edge{head[from],to,f};head[from]=num;}
void ADD(int from,int to,int f){add(from,to,f),add(to,from,0);}
bool bfs()
{
	static int q[304000],h,t;
	memset(dep,0,tot<<2);
	memcpy(cur,head,tot<<2);
	h=0,t=1;q[1]=0;dep[0]=1;
	while(h<t)
	{
		int x=q[++h];
		for(int i=head[x],y;i;i=e[i].nxt)
		{
			y=e[i].to;
			if(e[i].f&&!dep[y])dep[y]=dep[x]+1,q[++t]=y;
		}
	}
	return dep[T]!=0;
}
int flow;
int dfs(int v,int last)
{
	if(v==T)return flow+=last,last;
	int now=0;
	for(int &i=cur[v],u;i;i=e[i].nxt)
	{
		u=e[i].to;
		if(!e[i].f||dep[u]!=dep[v]+1)continue;
		int dmin=dfs(u,min(last,e[i].f));
		e[i].f-=dmin,e[i^1].f+=dmin;
		last-=dmin,now+=dmin;
		if(!last)break;
	}
	return now;
}
int n,a[3030],b[3030];
int last[3030];
int main()
{
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	int ans=0;
	for(int i=1;i<=n;++i)
		if(b[i]<0)ADD(S,i+1,-b[i]);
		else ans+=b[i],ADD(i+1,T,b[i]);
	tot=n+2;
	for(int i=1;i<=n;++i)
		if(b[i]<0)
		{
			if(last[a[i]])ADD(last[a[i]],tot,0x3f3f3f3f);
			last[a[i]]=tot;
			ADD(i+1,tot,0x3f3f3f3f);++tot;
		}
		else 
		{
			for(int j=1;j<=a[i];++j)
				if(a[i]%j==0&&last[j])ADD(last[j],i+1,0x3f3f3f3f);
		}
	while(bfs())
		while(dfs(S,inf));
	printf("%d",ans-flow);
	flush();
	return 0;
}