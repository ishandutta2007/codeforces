#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian
{
	int nxt,to,w;
}bi[1000010];
int q,n,k,head[500050],num,bw[500050];
long long dp[500050][2];
inline void add(int from,int to,int w)
{
	bi[++num]=bian{head[from],to,w};
	head[from]=num;
}
void dfs(int v,int fa)
{
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		dfs(u,v);
	}
	static pair<long long,int>st[500050];
	static int tp;
	dp[v][0]=dp[v][1]=0;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		if(dp[u][0]>=dp[u][1]+bi[i].w)dp[v][0]+=dp[u][0],dp[v][1]+=dp[u][0];
		else st[++tp]=make_pair(dp[u][0]-dp[u][1]-bi[i].w,u);
		bw[u]=bi[i].w;
	}
	sort(st+1,st+1+tp);
	for(int i=1;i<=k&&i<=tp;++i)dp[v][0]+=dp[st[i].second][1]+bw[st[i].second];
	for(int i=k+1;i<=tp;++i)dp[v][0]+=dp[st[i].second][0];
	for(int i=1;i<k&&i<=tp;++i)dp[v][1]+=dp[st[i].second][1]+bw[st[i].second];
	for(int i=k;i<=tp;++i)dp[v][1]+=dp[st[i].second][0];
	tp=0;
}
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d",&n,&k);
		int x,y,w;
		for(int i=1;i<n;++i)
		{
			scanf("%d %d %d",&x,&y,&w);
			add(x,y,w),add(y,x,w);
		}
		dfs(1,0);
		printf("%lld\n",dp[1][0]);
		memset(head+1,0,n<<2);num=0;
	}
	return 0;
}