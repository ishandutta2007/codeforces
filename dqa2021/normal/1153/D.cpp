#include<cstdio>
#include<algorithm>
using namespace std;

int n,w[300010];
struct Edge{
	int to,nxt;
}edge[300010];
int cnt,last[300010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
}
int dp[300010],tot;
void dfs(int cur)
{
	if (!last[cur]) return dp[cur]=1,tot++,void();
	if (w[cur])
	{
		dp[cur]=0x7fffffff;
		for (int i=last[cur];i;i=edge[i].nxt)
		{
			dfs(edge[i].to);
			dp[cur]=min(dp[cur],dp[edge[i].to]);
		}
		return;
	}
	for (int i=last[cur];i;i=edge[i].nxt)
	{
		dfs(edge[i].to);
		dp[cur]+=dp[edge[i].to];
	}
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",w+i);
	for (int i=2,x;i<=n;i++)
	{
		scanf("%d",&x); addedge(x,i);
	}
	dfs(1);
	printf("%d\n",tot-dp[1]+1);
	return 0;
}