#include<bits/stdc++.h>
using namespace std;
int n,m;

char mp[1000][1000];
int dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
int ans;
int vis[1000][1000];
int mark[1000];
void dfs(int x,int y,char c)
{
	vis[x][y]=1;
	if(mp[x][y]!=c)
	{
		if(mark[mp[x][y]]==0){
			ans++;
		}
		mark[mp[x][y]]=1;
		return;
	}
	
	for(int i=0;i<4;i++)
	{
		int nx=x+dir[i][0];
		int ny=y+dir[i][1];
		
		if(nx<0||nx>=n||ny<0||ny>=m||mp[nx][ny]=='.'||mark[mp[nx][ny]]==1) continue;
		if(vis[nx][ny]==0){
			dfs(nx,ny,c);
		}
	}
}
void gao(char x)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mp[i][j]==x){
				dfs(i,j,x); return;
			}
		}
	}
}
int main()
{
	char c;
	ans=0;
	cin>>n>>m>>c;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
		scanf(" %c",&mp[i][j]);
	}
    gao(c);
    cout<<ans<<endl;
	return 0;
}