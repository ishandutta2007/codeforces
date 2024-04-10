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

const int N=3e5+5;
int n,a[N],dp[N],siz[N];

struct Edge
{
	int v,ne;
}e[N*2];
int head[N],tot;

inline void add(int u,int v);
void dfs1(int u,int fa);
void dfs2(int u,int fa);

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;++i)
		write(dp[i]),putchar(' ');
	return 0;
}

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

void dfs1(int u,int fa)
{
	if(a[u]) dp[u]=1;
	if(a[fa]) dp[u]=1;
	siz[u]=a[u];
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs1(v,u);siz[u]+=siz[v];
		if(a[v]) dp[u]=1;
		if(dp[v]&&siz[v]>1) dp[u]=1;
	}
}

void dfs2(int u,int fa)
{
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		if(dp[u]&&siz[1]-siz[v]>1) dp[v]=1;
		dfs2(v,u);
	}
}