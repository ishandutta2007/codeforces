#include<bits/stdc++.h>
using namespace std;
char c[52][52]={'#'};
bool vis[52][52];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
bool dfs(int x,int y,int xx,int yy)
{
	if(vis[x][y])return true;
	vis[x][y]=true;
	for(int i=0;i<4;i++)
	{
		int fx=x+dx[i],fy=y+dy[i];
		if(c[fx][fy]==c[x][y]&&(fx!=xx||fy!=yy))
			if(dfs(fx,fy,x,y))return true;
	}
	return false;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>c[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!vis[i][j])
				for(int k=0;k<4;k++){
					bool res2=false,res1=false;
					if(c[i][j]==c[i+dx[k]][j+dy[k]]&&c[i][j]!='#')
						res1=dfs(i,j,i+dx[k],j+dy[k]),
						memset(vis,false,sizeof vis),
						res2=dfs(i+dx[k],j+dy[k],i,j),
						memset(vis,false,sizeof vis);
					if(res1||res2){cout<<"Yes";return 0;}
				}
	cout<<"No";
}