#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct bian
{
	int nxt,to,w;
}bi[200020];
int n,m,s,t,p[2020],head[2020],num,cnt[2],S[2020][2020],nx[2020],ny[2020];
long long ans,dis[2][2020],d[2020],sum[2020][2020],dp[2020][2020][2],mix[2020],mxy[2020];
inline void add(int from,int to,int w){bi[++num]=bian{head[from],to,w};head[from]=num;}
void dijkstra(int st,int T)
{
	static bool vis[2020];
	priority_queue<pair<long long,int> >q;
	memset(vis+1,0,n);memset(dis[T]+1,0x3f,n<<3);
	q.push(make_pair(dis[T][st]=0,st));
	int x,y;
	while(!q.empty())
	{
		x=q.top().second;q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=bi[i].nxt)
		{
			y=bi[i].to;
			if(dis[T][x]+bi[i].w<dis[T][y])
			{
				dis[T][y]=dis[T][x]+bi[i].w;
				q.push(make_pair(-dis[T][y],y));
			}
		}
	}
}
int main()
{
	scanf("%d %d %d %d",&n,&m,&s,&t);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	int x,y,w;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d %d",&x,&y,&w);
		add(x,y,w),add(y,x,w);
	}
	dijkstra(s,0);
	dijkstra(t,1);
	for(int T=0;T<=1;++T)
	{
		cnt[T]=0;
		for(int i=1;i<=n;++i)d[++cnt[T]]=dis[T][i];
		sort(d+1,d+1+cnt[T]);
		cnt[T]=unique(d+1,d+1+cnt[T])-d-1;
		for(int i=1;i<=n;++i)dis[T][i]=lower_bound(d+1,d+1+cnt[T],dis[T][i])-d;		
	}
	for(int i=1;i<=n;++i)sum[dis[0][i]][dis[1][i]]+=p[i],++S[dis[0][i]][dis[1][i]];
	for(int i=cnt[0];i;--i)
		for(int j=cnt[1];j;--j)
			sum[i][j]+=sum[i][j+1],S[i][j]+=S[i][j+1];
	for(int i=cnt[0];i;--i)
		for(int j=cnt[1];j;--j)
			sum[i][j]+=sum[i+1][j],S[i][j]+=S[i+1][j];
	for(int i=1;i<=cnt[0];++i)nx[i]=cnt[1]+1;
	for(int i=1;i<=cnt[1];++i)ny[i]=cnt[0]+1;
	for(int i=cnt[0];i;--i)
		for(int j=cnt[1];j;--j)
		{
			if(S[i][j]==0)dp[i][j][0]=dp[i][j][1]=0;
			else
			{
				while(S[i][j]-S[ny[j]-1][j]>0)
				{
					--ny[j];
					mxy[j]=max(mxy[j],dp[ny[j]][j][1]-sum[ny[j]][j]);
				}
				while(S[i][j]-S[i][nx[i]-1]>0)
				{
					--nx[i];
					mix[i]=min(mix[i],dp[i][nx[i]][0]+sum[i][nx[i]]);
				}
				dp[i][j][0]=mxy[j]+sum[i][j];
				dp[i][j][1]=mix[i]-sum[i][j];
			}
		}
/*	for(int i=1;i<=cnt[0];++i)
	{
		for(int j=1;j<=cnt[1];++j)printf("%lld ",dp[i][j][0]);
		printf("\n");
	}
	printf("\n");
	for(int i=1;i<=cnt[0];++i)
	{
		for(int j=1;j<=cnt[1];++j)printf("%lld ",dp[i][j][1]);
		printf("\n");
	}	*/
	if(dp[1][1][0]>0)printf("Break a heart");
	else if(dp[1][1][0]==0)printf("Flowers");
	else printf("Cry");
	return 0;
}