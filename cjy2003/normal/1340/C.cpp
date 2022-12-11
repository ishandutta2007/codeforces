#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,d[10010],g,r,dp[10010][1010],ans=0x3f3f3f3f;
bool vis[10010][1010];
deque<pair<int,int> >q;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i)scanf("%d",&d[i]);
	sort(d+1,d+1+m);
	scanf("%d %d",&g,&r);
	memset(dp,0x3f,sizeof(dp));
	dp[1][0]=0;
	q.push_back(make_pair(1,0));
	int x,t;
	while(!q.empty())
	{
		x=q.front().first,t=q.front().second;
		q.pop_front();
		if(vis[x][t])continue;
		vis[x][t]=1;
		if(x>1&&g-t>=d[x]-d[x-1])
		{
			if(g-t>d[x]-d[x-1])
			{
				if(dp[x-1][t+d[x]-d[x-1]]>dp[x][t])
				{
					dp[x-1][t+d[x]-d[x-1]]=dp[x][t];
					q.push_front(make_pair(x-1,t+d[x]-d[x-1]));
				}
			}
			else
			{
				if(dp[x-1][0]>dp[x][t]+1)
				{
					dp[x-1][0]=dp[x][t]+1;
					q.push_back(make_pair(x-1,0));
				}
			}
		}
		if(x<m&&g-t>=d[x+1]-d[x])
		{
			if(g-t>d[x+1]-d[x])
			{
				if(dp[x+1][t+d[x+1]-d[x]]>dp[x][t])
				{
					dp[x+1][t+d[x+1]-d[x]]=dp[x][t];
					q.push_front(make_pair(x+1,t+d[x+1]-d[x]));
				}
			}
			else
			{
				if(dp[x+1][0]>dp[x][t]+1)
				{
					dp[x+1][0]=dp[x][t]+1;
					q.push_back(make_pair(x+1,0));
				}
			}
		}
	}
	if(dp[m][0]!=0x3f3f3f3f)ans=dp[m][0]*(g+r)-r;
	for(int i=1;i<g;++i)if(dp[m][i]!=0x3f3f3f3f)ans=min(ans,dp[m][i]*(g+r)+i);
	if(ans==0x3f3f3f3f)printf("-1");
	else printf("%d",ans);
	return 0;
}