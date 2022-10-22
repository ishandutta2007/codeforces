#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f

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

const int N=1e6+5;
int n,m,du[N],vis[N],tg;

struct edge
{
	int u,v;
}ee[N];

struct Edge
{
	int v,w,ne;
}e[N*2];
int head[N],tot;

inline void add(int u,int v,int w)
{
	e[++tot]=(Edge){v,w,head[u]};
	head[u]=tot;
}

void dfs(int u)
{
	for(int &i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(vis[e[i].w])
			continue;
		int I=i;vis[e[i].w]=1;dfs(v);tg^=1;
		if((tg&&u!=ee[e[I].w].u)||(!tg&&u==ee[e[I].w].u))
			swap(ee[e[I].w].u,ee[e[I].w].v);
	}
}

signed main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		ee[i]=(edge){u,v};
		add(u,v,i);add(v,u,i);
		du[u]^=1;du[v]^=1;	
	}
	int ls=-1;
	for(int i=1;i<=n;++i)
		if(du[i])
		{
			if(ls!=-1)
			{
				ee[++m]=(edge){ls,i};
				add(ls,i,m);add(i,ls,m);
				ls=-1;
			}
			else ls=i;
		}
	if(m%2==1)
	{
		ee[++m]=(edge){1,1};
		add(1,1,m);add(1,1,m);
	}
	dfs(1);
	write(m);puts("");
	for(int i=1;i<=m;++i)
		write(ee[i].u),putchar(' '),write(ee[i].v),puts("");
	return 0;
}