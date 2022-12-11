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
namespace flow
{
	const int S=0,T=1,inf=0x3f3f3f3f;
	struct edge
	{
		int nxt,to,f;
	}e[200020];
	int head[100010],num=1,dep[100010],cur[100010],tot=1;
	inline void add(int from,int to,int f){e[++num]=edge{head[from],to,f};head[from]=num;}
	inline void ADD(int from,int to,int f){add(from,to,f),add(to,from,0);}
	bool bfs()
	{
		static int q[100010],h,t;
		memset(dep,0,tot+1<<2);
		memcpy(cur,head,tot+1<<2);
		h=0,t=1,q[t]=S,dep[S]=1;
		int x,y;
		while(h<t)
		{
			x=q[++h];
			for(int i=head[x];i;i=e[i].nxt)if(e[i].f&&!dep[y=e[i].to])dep[y]=dep[x]+1,q[++t]=y;
		}
		return dep[T]!=0;
	}
	int dfs(int v,int last)
	{
		if(v==T)return last;
		int now=0;
		for(int &i=cur[v],u;i;i=e[i].nxt)
			if(e[i].f&&dep[u=e[i].to]==dep[v]+1)
			{
				int dmin=dfs(u,min(last,e[i].f));
				e[i].f-=dmin,e[i^1].f+=dmin;
				last-=dmin,now+=dmin;
				if(!last)break;
			}
		return now;
	}
	int work(int s)
	{
		tot=s;
	//	for(int i=0;i<=tot;++i)
	//		for(int j=head[i];j;j=e[j].nxt)
	//			if(e[j].f)printf("%d %d %d\n",i,e[j].to,e[j].f);
		int res=0;
		while(bfs())res+=dfs(S,0x3f3f3f3f);
		return res;
	}
}
int n,m,g,a[10010],v[10010],ans;
int main()
{
	n=read(),m=read(),g=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)v[i]=read();
	for(int i=1;i<=n;++i)
		if(!a[i])flow::ADD(0,i+1,v[i]);
		else flow::ADD(i+1,1,v[i]);
	int op,w,k,x;
	for(int i=1;i<=m;++i)
	{
		op=read(),w=read(),k=read();
		ans+=w;
		if(!op)while(k--)x=read(),flow::ADD(i+n+1,x+1,flow::inf);
		else while(k--)x=read(),flow::ADD(x+1,i+n+1,flow::inf);
		if(read())w+=g;
		if(!op)flow::ADD(0,i+n+1,w);
		else flow::ADD(i+n+1,1,w);
	}
	ans-=flow::work(n+m+1);
	printf("%d",ans);
	return 0;
}