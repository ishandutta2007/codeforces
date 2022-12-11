#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<random>
#include<vector>
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
mt19937 myrand(time(0)+(unsigned long long)(new char));
struct edge
{
	int nxt,to;
}e[200020];
int T,n,m,head[100010],num;
inline void add(int from,int to){e[++num]=edge{head[from],to};head[from]=num;}
bool vis[100010],in[100010],unint[100010];
int rt,dep[100010],cnt[100010],stk[100010],tp;
int q[100010],h,t,f[100010],up[100010];
vector<int>E[100010];
bool check(int x)
{
	vis[x]=1;in[x]=1;
	for(int i=head[x],y;i;i=e[i].nxt)
	{
		y=e[i].to;
		if(!in[y]&&vis[y])return 0;
		if(vis[y])continue;
		if(!check(y))return 0;
	}
	in[x]=0;
	return 1;
}
void dfs(int v,int fa)
{
	dep[v]=dep[fa]+1;up[v]=fa;
	for(int i=head[v],u;i;i=e[i].nxt)
	{
		u=e[i].to;
		if(dep[u])++cnt[v],--cnt[u],E[u].emplace_back(v);
		else dfs(u,v);
	}
}
void dfs1(int v)
{
	for(int i=head[v],u;i;i=e[i].nxt)
	{
		u=e[i].to;
		if(dep[u]<dep[v])continue;
		dfs1(u);
		cnt[v]+=cnt[u];
	}
	if(cnt[v]>=2)unint[v]=1,q[++t]=v,f[v]=up[v];
	else f[v]=v;
}
int find(int x)
{
	if(x!=f[x])return f[x]=find(f[x]);
	return x;
}
int main()
{
	T=read();
	while(T--)
	{
		n=read(),m=read();
		for(int i=1,x,y;i<=m;++i)x=read(),y=read(),add(x,y);
		rt=0;
		for(int i=1,x;i<=50;++i)
		{
			x=myrand()%n+1;
			if(check(x)){memset(vis+1,0,n);rt=x;break;}
			memset(vis+1,0,n);
		}
		if(!rt)print(-1);
		else
		{
			dfs(rt,0);
			h=t=0;
			dfs1(rt);
			while(h<t)
			{
				int x=q[++h];
				for(auto y:E[x])
					while(dep[find(y)]>dep[x])unint[find(y)]=1,q[++t]=find(y),f[find(y)]=up[find(y)];
			}
			int ans=0;
			for(int i=1;i<=n;++i)ans+=!unint[i];
			if(5*ans<n)print(-1);
			else for(int i=1;i<=n;++i)if(!unint[i])print(i),putc(' ');
		}
		putc('\n');
		memset(head+1,0,n<<2);num=0;
		memset(unint+1,0,n);
		memset(dep+1,0,n<<2);
		memset(cnt+1,0,n<<2);
		for(int i=1;i<=n;++i)E[i].clear();
	}
	flush();
	return 0;
}