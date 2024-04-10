#include<bits/stdc++.h>
#define N 500
const int dx[4]={1,0,0,-1},dy[4]={0,1,-1,0};
const int inf=2e9;
using namespace std;
int T,n,k,e[N+5][N+5][4],f[N+5][N+5];
bool vis[N+5][N+5];
inline int dijkstra()
{
	priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > q;
	for(int i=0;i<=k;++i) for(int j=0;j<=k;++j) f[i][j]=inf,vis[i][j]=0;f[0][0]=0,q.push({0,{0,0}});
	while(1)
	{
		int x=q.top().second.first,y=q.top().second.second;q.pop();
		if(vis[x][y]) continue;vis[x][y]=1;
		if(x==(k>>1) && y==(k>>1)) return f[x][y];
		for(int i=0;i<4;++i)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if(0<=nx && nx<=k && 0<=ny && ny<=k && f[nx][ny]>f[x][y]+e[x][y][i])
				f[nx][ny]=f[x][y]+e[x][y][i],q.push({f[nx][ny],{nx,ny}});
		}
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&k);
		memset(e,0,sizeof e);
		for(int i=1,r1,c1,r2,c2;i<=n;++i)
		{
			scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
			if(r1>r2) swap(r1,r2);if(c1>c2) swap(c1,c2);
			if(r1==r2) ++e[r1-1][c1][0],++e[r1][c1][3],++e[k-r1+1][k-c1][3],++e[k-r1][k-c1][0];
			else ++e[r1][c1-1][1],++e[r1][c1][2],++e[k-r1][k-c1+1][2],++e[k-r1][k-c1][1];
		}
		printf("%d\n",n-dijkstra());
	}
	return 0;
}