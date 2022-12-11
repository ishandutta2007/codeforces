#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;

int n,m,k;
struct Node{
	int w,d,id;
}node[100010];
bool operator<(const Node x,const Node y)
{
	if (x.w!=y.w) return x.w<y.w;
	return x.d<y.d;
}
priority_queue<Node> que;
struct Edge{
	int to,nxt;
	bool sgn;
}edge[200010];
int cnt,last[100010];
inline void addedge(int x,int y,bool s)
{
	edge[++cnt]=(Edge){y,last[x],s},last[x]=cnt;
}

int chc[100010];
bool inq[100010];

ll dp[2][100010]; bool dpcur=false;

ll ans=0x7f7f7f7f7f7f7f7fLL;
int main()
{
	memset(chc,-1,sizeof chc);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1,x,y;i<=k;i++)
	{
		scanf("%d%d%d%d",&x,&y,&node[i].d,&node[i].w); node[i].id=i;
		addedge(x,i,false); addedge(y+1,i,true);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=last[i];j;j=edge[j].nxt)
		{
			inq[edge[j].to]^=1;
			if (!edge[j].sgn) que.push(node[edge[j].to]);
		}
		while (!que.empty()&&!inq[que.top().id]) que.pop();
		if (!que.empty()) chc[i]=que.top().id;
	}
	memset(dp[dpcur^1],0x7f,sizeof dp[dpcur^1]); dp[dpcur^1][1]=0;
	for (int j=0;j<=m;j++)
	{
		dpcur^=1;
		memset(dp[dpcur^1],0x7f,sizeof dp[dpcur^1]); dp[dpcur^1][1]=0;
		for (int i=1;i<=n;i++)
		{
			if (dp[dpcur][i]==0x7f7f7f7f7f7f7f7fLL) continue;
			dp[dpcur^1][i+1]=min(dp[dpcur^1][i+1],dp[dpcur][i]);
			if (chc[i]==-1)
			{
				dp[dpcur][i+1]=min(dp[dpcur][i+1],dp[dpcur][i]);
				continue;
			}
			dp[dpcur][node[chc[i]].d+1]=min(dp[dpcur][node[chc[i]].d+1],dp[dpcur][i]+node[chc[i]].w);
		}
		ans=min(ans,dp[dpcur][n+1]);
	}
	printf("%I64d\n",ans);
	return 0;
}