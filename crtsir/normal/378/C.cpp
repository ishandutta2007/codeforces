#include<bits/stdc++.h>
using namespace std;
char c[1003][1003];
int n,m,k,a,b,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
vector<pair<int,int> >v;
bool vis[1003][1003];
void dfs(int x,int y){
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx<0||xx>=n||yy<0||yy>=m||vis[xx][yy]||c[xx][yy]=='#')continue;
		dfs(xx,yy);
	}
	v.push_back(make_pair(x,y));
}
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>c[i][j];
			if(c[i][j]=='.')
				a=i,
				b=j;
		}
	dfs(a,b);
	for(int i=0;i<k;i++)
		c[v[i].first][v[i].second]='X';
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<c[i][j];
		cout<<endl;
	}
}