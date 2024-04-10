#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=105;
int n,m;

struct Dinic
{
	static const int _N=N*N,_M=N*N*N;
	
	int s,t,k,id[N],du[N],dis[_N],vis[_N],ans2;
	
	struct Edge
	{
		int v,w1,w2,ne;
	}e[_M*2];
	int head[_N],cur[_N],tot;
	
	inline void add(int u,int v,int w1,int w2)
	{
		e[++tot]=(Edge){v,w1,w2,head[u]};head[u]=tot;
		e[++tot]=(Edge){u,0,-w2,head[v]};head[v]=tot;
	}
	
	inline bool bfs()
	{
		for(int i=1;i<=k;++i)
			dis[i]=INF,vis[i]=0,cur[i]=head[i];
		queue<int> qu;
		dis[s]=0;qu.push(s);vis[s]=1;
		while(!qu.empty())
		{
			int u=qu.front();
			qu.pop();vis[u]=0;
			for(int i=head[u];i;i=e[i].ne)
			{
				int v=e[i].v;
				if(!e[i].w1) continue;
				if(dis[v]>dis[u]+e[i].w2)
				{
					dis[v]=dis[u]+e[i].w2;
					if(!vis[v])
					{
						vis[v]=1;
						qu.push(v);
					}
				}
			}
		}
		return dis[t]!=INF;
	}
	
	inline int dinic()
	{
		int res=0;
		while(bfs())
		{
			while(1)
			{
				int tmp=dfs(s,INF);
				res+=tmp;
				if(!tmp) break;
			}
		}
		return res;
	}
	
	int dfs(int u,int flow)
	{
		if(u==t) return flow;
		vis[u]=1;
		for(int &i=cur[u];i;i=e[i].ne)
		{
			int v=e[i].v;
			if(!e[i].w1||vis[v]||dis[v]!=dis[u]+e[i].w2)
				continue;
			int tmp=dfs(v,min(flow,e[i].w1));
			if(tmp)
			{
				ans2+=tmp*e[i].w2;
				e[i].w1-=tmp;
				e[fan(i)].w1+=tmp;
				vis[u]=0;
				return tmp;
			}
		}
		vis[u]=0;
		return 0;
	}
	inline void build()
	{
		s=++k;t=++k;
		for(int i=1;i<=n;++i)
			id[i]=++k;
		for(int i=1;i<=m;++i)
		{
			int u=read(),v=read();
			int c=read(),f=read();
			if(c>=f)
			{
				add(id[u],id[v],f,1);
				add(id[v],id[u],c-f,1);
				add(id[v],id[u],INF,2);
			}
			else
			{
				ans2+=f-c;
				add(id[u],id[v],c,1);
				add(id[u],id[v],f-c,0);
				add(id[v],id[u],INF,2);
			}
			du[u]+=f;du[v]-=f;
		}
		for(int i=1;i<=n;++i)
			if(du[i]>0) add(s,id[i],du[i],0);
			else add(id[i],t,-du[i],0);
		add(id[1],id[n],INF,0);dinic();
		write(ans2);puts("");
	}
}din;

signed main()
{
	n=read();m=read();
	din.build();
	return 0;
}