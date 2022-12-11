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
const int S=0,T=1;
const long long inf=0x3f3f3f3f3f3f3f3f;
struct edge
{
	int nxt,to;
	long long f;
}e[200020];
int head[100010],num=1,dep[100010],cur[100010],tot=2;
inline void add(int from,int to,long long f){e[++num]=edge{head[from],to,f};head[from]=num;}
inline void ADD(int from,int to,long long f){add(from,to,f),add(to,from,0);}
bool bfs()
{
	static int q[100010],h,t;
	memset(dep,0,tot<<2);
	memcpy(cur,head,tot<<2);
	h=0,t=1,q[t]=S,dep[S]=1;
	int x,y;
	while(h<t)
	{
		x=q[++h];
		for(int i=head[x];i;i=e[i].nxt)if(e[i].f&&!dep[y=e[i].to])dep[y]=dep[x]+1,q[++t]=y;
	}
	return dep[T]!=0;
}
long long dfs(int v,long long last)
{
	if(v==T)return last;
	long long now=0;
	for(int &i=cur[v],u;i;i=e[i].nxt)
		if(e[i].f&&dep[u=e[i].to]==dep[v]+1)
		{
			long long dmin=dfs(u,min(last,e[i].f));
			e[i].f-=dmin,e[i^1].f+=dmin;
			last-=dmin,now+=dmin;
			if(!last)break;
		}
	return now;
}
int n,x[1010],y[1010],w[1010],label[1010],in[1010],out[1010];
int b[2][2]={{1,2},{0,3}};
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		x[i]=read(),y[i]=read(),w[i]=read();
		label[i]=b[x[i]&1][y[i]&1];
		in[i]=tot++,out[i]=tot++;
		ADD(in[i],out[i],w[i]);
		if(label[i]==0)ADD(S,in[i],inf);
		if(label[i]==3)ADD(out[i],T,inf);
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(abs(x[i]-x[j])+abs(y[i]-y[j])==1&&label[j]==label[i]+1)
				ADD(out[i],in[j],inf);
	long long ans=0;
	for(int i=1;i<=n;++i)ans+=w[i];
	while(bfs())ans-=dfs(S,inf);
	printf("%lld",ans);
	return 0;
}