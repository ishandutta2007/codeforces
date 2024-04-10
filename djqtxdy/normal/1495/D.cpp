#include<cstdio>
#include<vector>

using namespace std;

const int INF=1e9;

vector<int> ed[1000];
int dis[1000][1000];

const long long MOD=998244353;

int main()
{
	int n=0,m=0;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)dis[i][j]=INF;
	for(int i=1,x=0,y=0;i<=m;i++)
	{
		scanf("%d%d",&x,&y);ed[x].push_back(y),ed[y].push_back(x);dis[x][y]=dis[y][x]=min(dis[x][y],1);
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=n;y++)
		{
			int d=dis[x][y],cnt=0;
			for(int k=1;k<=n;k++)if(d==dis[x][k]+dis[k][y])cnt++;
			if(cnt>d+1){printf("0 ");continue;}
			long long ans=1;
			for(int k=1;k<=n;k++)
			{
				if(dis[x][k]+dis[k][y]==d)continue;
				int cnt=0;
				for(int i=0;i<ed[k].size();i++)
					if(dis[x][k]==dis[x][ed[k][i]]+1&&dis[y][k]==dis[y][ed[k][i]]+1)cnt++;
				ans=ans*cnt%MOD;
			}
			printf("%lld ",ans);
		}
		puts("");
	}
}