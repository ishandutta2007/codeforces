#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cassert>
using namespace std;
const int mod=1000000007;
vector<int>son[100010];
int n,q,k,m,r,dp[310],p[100010],dis[100010],cnt[100010];
int depth[100010],f[100010],tp[100010],siz[100010],id[100010],idnum,zson[100010];
int sum[100010];
void add(int x,int w)
{
	while(x<=n)
	{
		sum[x]+=w;
		x+=x&-x;
	}
}
int query(int x)
{
	int s=0;
	while(x)
	{
		s+=sum[x];
		x-=x&-x;
	}
	return s;
}
void dfs1(int v,int fa)
{
	siz[v]=1,depth[v]=depth[fa]+1,f[v]=fa;
	for(auto u:son[v])
	{
		if(u==fa)continue;
		dfs1(u,v);
		siz[v]+=siz[u];
		if(siz[u]>siz[zson[v]])zson[v]=u;
	}
}
void dfs2(int v,int topp)
{
	tp[v]=topp,id[v]=++idnum;
	if(zson[v])dfs2(zson[v],topp);
	for(auto u:son[v])
	{
		if(u==f[v]||u==zson[v])continue;
		dfs2(u,u);
	}
}
int qlca(int x,int y)
{
	while(tp[x]!=tp[y])
	{
		if(depth[tp[x]]<depth[tp[y]])y=f[tp[y]];
		else x=f[tp[x]];
	}
	return depth[x]<depth[y]?x:y;
}
int qnum(int x,int y)
{
	int s=0;
	while(tp[x]!=tp[y])
	{
		if(depth[tp[x]]<depth[tp[y]])
		{
			s+=query(id[y])-query(id[tp[y]]-1);
			y=f[tp[y]];
		}
		else
		{
			s+=query(id[x])-query(id[tp[x]]-1);
			x=f[tp[x]];
		}
	}
	if(id[x]<id[y])s+=query(id[y])-query(id[x]-1);
	else s+=query(id[x])-query(id[y]-1);
	return s;
}
bool cmp(int x,int y)
{
	return dis[x]<dis[y];
}
int main()
{
	scanf("%d %d",&n,&q);
	int x,y,ans;
	for(int i=1;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		son[x].push_back(y);
		son[y].push_back(x); 
	}
	dfs1(1,0);
	dfs2(1,1);
	while(q--)
	{
		scanf("%d %d %d",&k,&m,&r);
		for(int i=1;i<=k;++i)
			scanf("%d",&p[i]),dis[p[i]]=depth[p[i]]+depth[r]-2*depth[qlca(p[i],r)],add(id[p[i]],1);
		sort(p+1,p+1+k,cmp);
		for(int i=1;i<=k;++i)
			cnt[i]=qnum(p[i],r)-1;
		for(int i=1;i<=m;++i)dp[i]=0;
		dp[0]=1;
		for(int i=1;i<=k;++i)
			for(int j=m;j>=0;--j)
			{
				if(j<=cnt[i])dp[j]=0;
				else dp[j]=(dp[j-1]+1ll*dp[j]*(j-cnt[i])%mod)%mod;
			}
	//	for(int i=1;i<=m;++i)
	//		printf("%d ",dp[i]);
	//	printf("\n!");
		ans=0;
		for(int i=1;i<=m;++i)
			(ans+=dp[i])%=mod;
		for(int i=1;i<=k;++i)
			add(id[p[i]],-1);
		printf("%d\n",ans);
	}
	return 0;
}