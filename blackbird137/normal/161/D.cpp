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

#define int long long
#define lowbit(x) (x&(-x))
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define mid ((l+r)>>1)
#define fan(x) (((x-1)^1)+1)
#define max Max
#define min Min
#define abs Abs

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
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=4e5+5,M=2e6+5;
int n,k,vis[N],sum[M],ans;

struct Edge
{
	int v,w,ne;
}e[M*2];
int head[N],tot;

vector<int> in;

inline void add(int u,int v,int w);
inline int getpos(int x);
void dfs1(int u,int fa);
void dfs3(int u,int fa);
void dfs2(int u,int fa,int s);
void solve(int u);

signed main()
{
	//freopen("yangli.in","r",stdin);
	n=read();k=read();
	for(int i=1;i<=n-1;++i)
	{
		int u=read(),v=read();
		add(u,v,1);add(v,u,1);
	}
	solve(getpos(1));
	printf("%lld\n",ans);
	return 0;
}

inline void add(int u,int v,int w)
{
	e[++tot]=(Edge){v,w,head[u]};
	head[u]=tot;
}

int siz[N],dp[N],res,num;

inline int getpos(int x)
{
	dp[0]=1e18;res=0;num=0;
	dfs1(x,0);dfs3(x,0);
	return res;
}

void dfs1(int u,int fa)
{
	siz[u]=1;dp[u]=0;num++;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa||vis[v]) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		dp[u]=max(dp[u],siz[v]);
	}
}

void dfs3(int u,int fa)
{
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa||vis[v]) continue;
		dfs3(v,u);
	}
	dp[u]=max(dp[u],num-dp[u]);
	if(dp[u]<dp[res]) res=u;
}

void dfs2(int u,int fa,int s)
{
	if(s>k) return;
	in.push_back(s);
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa||vis[v]) continue;
		dfs2(v,u,s+e[i].w);
	}
}

void solve(int u)
{
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(vis[v]) continue;
		in.clear();
		dfs2(v,u,e[i].w);
		for(int j=0;j<in.size();++j)
			if(in[j]<=k)
			{
				if(in[j]==k) ans++;
				else ans+=sum[k-in[j]];
			}
		for(int j=0;j<in.size();++j)
			sum[in[j]]++;
	}
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(vis[v]) continue;
		in.clear();
		dfs2(v,u,e[i].w);
		for(int j=0;j<in.size();++j)
			sum[in[j]]=0;
	}
	vis[u]=1;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(vis[v]) continue;
		solve(getpos(v));
	}
}