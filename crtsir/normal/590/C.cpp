#include<bits/stdc++.h>
using namespace std;
int dis[1003][1003][4],dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},n,m;
pair<int,int>w[4];
char c[1003][1003];
bool vis[1003][1003];
void bfs(int a){
	deque<pair<int,int> >q;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(c[i][j]==char(a+'0')){
				dis[i][j][a]=0;
				vis[i][j]=1;
				q.push_back(make_pair(i,j));
				w[a]=make_pair(i,j);
			}
			else
				dis[i][j][a]=2000000;
	while(!q.empty()){//nero 
		int x=q[0].first,y=q[0].second;
		q.pop_front();
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i],yy=y+dy[i];
			if(xx>=0&&xx<n&&yy>=0&&yy<m)
				if(!vis[xx][yy]&&c[xx][yy]!='#')
				{
					vis[xx][yy]=1;
					if(isdigit(c[xx][yy]))
						q.push_front(make_pair(xx,yy)),
						dis[xx][yy][a]=dis[x][y][a];
					else
						q.push_back(make_pair(xx,yy)),
						dis[xx][yy][a]=dis[x][y][a]+1;
				}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>c[i][j];
	bfs(1);bfs(2);bfs(3);
	int ans=2000000;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(c[i][j]=='.')
				ans=min(ans,dis[i][j][1]+dis[i][j][2]+dis[i][j][3]-2);
	int dist[3]={dis[w[2].first][w[2].second][1],
	dis[w[3].first][w[3].second][1],
	dis[w[3].first][w[3].second][2]};
	sort(dist,dist+3);
	ans=min(ans,dist[0]+dist[1]);
	if(ans==2000000)
		cout<<-1;
	else
		cout<<ans;
}