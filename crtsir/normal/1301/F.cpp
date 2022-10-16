#include<bits/stdc++.h>
using namespace std;
int dis[43][1003][1003],n,m,k,c[1003][1003],dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
bool vis[1003][1003],used[43][43];
vector<pair<int,int> >v[43];
void BFS(int co){
	queue<pair<pair<int,int>,int> >Q;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(c[i][j]==co)
				vis[i][j]=1,
				Q.push(make_pair(make_pair(i,j),0));
	while(Q.size()){
		int x=Q.front().first.first,y=Q.front().first.second,cst=Q.front().second;Q.pop();
		cst++;
		if(!used[co][c[x][y]]){
			for(int i=0;i<v[c[x][y]].size();i++)
				if(!vis[v[c[x][y]][i].first][v[c[x][y]][i].second])
					vis[v[c[x][y]][i].first][v[c[x][y]][i].second]=1,
					dis[co][v[c[x][y]][i].first][v[c[x][y]][i].second]=cst,
					Q.push(make_pair(make_pair(v[c[x][y]][i].first,v[c[x][y]][i].second),cst));
			used[co][c[x][y]]=1;
		}
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx<0||nx>=n||ny<0||ny>=m)continue;
			if(!vis[nx][ny])
				vis[nx][ny]=1,
				dis[co][nx][ny]=cst,
				Q.push(make_pair(make_pair(nx,ny),cst));
		}
	}
} 
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			scanf("%d",&c[i][j]);c[i][j]--;
			v[c[i][j]].push_back(make_pair(i,j));
		}
	for(int i=0;i<k;i++)BFS(i);
	int T;
	cin>>T;
	while(T--){
		int a1,b1,a2,b2;
		cin>>a1>>b1>>a2>>b2;a1--;b1--;a2--;b2--;
		int ret=fabs(a1-a2)+fabs(b1-b2);
		for(int i=0;i<k;i++)ret=min(ret,dis[i][a1][b1]+dis[i][a2][b2]+1);//,cout<<dis[i][a1][b1]<<' '<<dis[i][a2][b2]<<endl;
		cout<<ret<<endl;
	}
}