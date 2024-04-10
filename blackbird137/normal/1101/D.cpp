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

const int N=4e5+5;
int n,a[N],vis[N],sum[N],ans;

struct Edge
{
	int v,ne;
}e[N*2];
int head[N],tot;

vector<pair<int,int> > in;
vector<int> prim[N];

inline void add(int u,int v);
inline int getpos(int x);
void dfs1(int u,int fa);
void dfs3(int u,int fa);
void dfs2(int u,int fa,int s,int dep);
void solve(int u);

signed main()
{
	//freopen("yangli.in","r",stdin);
	for(int i=2;i<=200000;++i)
	{
		int tmp=i;
		for(int j=2;j*j<=tmp;++j)
			if(tmp%j==0)
			{
				prim[i].push_back(tmp);
				while(tmp%j==0) tmp/=j;
			}
		if(tmp!=1) prim[i].push_back(tmp);
	}
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=1;i<=n-1;++i)
	{
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	solve(getpos(1));
	printf("%lld\n",ans);
	return 0;
}

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
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

void dfs2(int u,int fa,int s,int dep)
{
	in.push_back(mp(s,dep));
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa||vis[v]) continue;
		dfs2(v,u,__gcd(s,a[v]),dep+1);
	}
}

void solve(int u)
{
	if(a[u]!=1) ans=max(ans,1);
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(vis[v]) continue;
		in.clear();
		dfs2(v,u,__gcd(a[u],a[v]),2);
		for(int j=0;j<in.size();++j)
			if(in[j].fi!=1)
			{
				ans=max(ans,in[j].se);
				for(int k=0;k<prim[in[j].fi].size();++k)
					ans=max(ans,in[j].se+sum[prim[in[j].fi][k]]);
			}
				
		for(int j=0;j<in.size();++j)
			if(in[j].fi!=1)
				for(int k=0;k<prim[in[j].fi].size();++k)
					sum[prim[in[j].fi][k]]=max(sum[prim[in[j].fi][k]],in[j].se-1);
	}
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(vis[v]) continue;
		in.clear();
		dfs2(v,u,__gcd(a[u],a[v]),2);
		for(int j=0;j<in.size();++j)
			if(in[j].fi!=1)
				for(int k=0;k<prim[in[j].fi].size();++k)
					sum[prim[in[j].fi][k]]=0;
	}
	vis[u]=1;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(vis[v]) continue;
		solve(getpos(v));
	}
}