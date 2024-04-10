#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
vector<int>E1[300030],E2[300030];
int n,c[300030],cnt[300030],tot;
bool vis[300030];
void dfs(int v,int fa)
{
	cnt[v]=c[v];
	for(auto u:E1[v])
	{
		if(u==fa)continue;
		dfs(u,v);
		cnt[v]+=cnt[u];
		if(cnt[u]>=2)E2[u].emplace_back(v);
		if(tot-cnt[u]>=2)E2[v].emplace_back(u);
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)c[i]=read(),tot+=c[i];
	for(int i=1,x,y;i<n;++i)
	{
		x=read(),y=read();
		E1[x].emplace_back(y);
		E1[y].emplace_back(x);
	}
	dfs(1,0);
	queue<int>q;
	for(int i=1;i<=n;++i)
		if(c[i])
		{
			if(!vis[i])vis[i]=1,q.push(i);
			for(auto x:E1[i])
				if(!vis[x])vis[x]=1,q.push(x);
		}
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(auto y:E2[x])
			if(!vis[y])vis[y]=1,q.push(y);
	}
	for(int i=1;i<=n;++i)print(int(vis[i])),putc(' ');
	flush();
	return 0;
}