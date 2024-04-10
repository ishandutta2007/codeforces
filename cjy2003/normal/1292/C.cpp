#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct bian
{
	int nxt,to;
}bi[6060];
vector<pair<int,int> >S[3030];
int n,head[3030],num;
inline void add(int from,int to)
{
	bi[++num]=bian{head[from],to};
	head[from]=num;
}
long long dp[3030][3030];
int dis[3030][3030],siz[3030][3030];
void dfs1(int v,int fa,int *d,int *s)
{
	s[v]=1;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		d[u]=d[v]+1;
		dfs1(u,v,d,s);
		s[v]+=s[u];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		add(x,y),add(y,x);
	}
	for(int i=1;i<=n;++i)dfs1(i,0,dis[i],siz[i]);
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			S[dis[i][j]].emplace_back(make_pair(i,j));
	for(int i=1;i<n;++i)
	{
		for(auto p:S[i])
		{
			int x=p.first,y=p.second;
			dp[x][y]+=siz[x][y]*siz[y][x];
			for(int j=head[x];j;j=bi[j].nxt)
			{
				if(dis[bi[j].to][y]!=i+1)continue;
				if(bi[j].to<y)dp[bi[j].to][y]=max(dp[bi[j].to][y],dp[x][y]);
				else dp[y][bi[j].to]=max(dp[y][bi[j].to],dp[x][y]);
			}
			for(int j=head[y];j;j=bi[j].nxt)
			{
				if(dis[bi[j].to][x]!=i+1)continue;
				if(bi[j].to<x)dp[bi[j].to][x]=max(dp[bi[j].to][x],dp[x][y]);
				else dp[x][bi[j].to]=max(dp[x][bi[j].to],dp[x][y]);
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			ans=max(ans,dp[i][j]);
	printf("%lld",ans);
	return 0;
}