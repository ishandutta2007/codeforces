#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
int vis[1234][1234];
char mp[1234][1234];
int pos[123456];
int ans;
int x,y;
void dfs(int x,int y,int i)
{
	if(x==0 || y==0 || x == n+1 || y==m+1)return ;
	if(mp[x][y]=='*')
	{
		ans++;return;
	}
	if(vis[x][y]!=0)return;
	vis[x][y] = i;
	dfs(x+1,y,i);
	dfs(x,y+1,i);
	dfs(x-1,y,i);
	dfs(x,y-1,i);
	return;
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>mp[i][j]; 
		}
	}
	for(int i=1;i<=k;i++)
	{
		cin>>x>>y;
		ans = 0;
		if(vis[x][y]==0)dfs(x,y,i);
		else ans = pos[vis[x][y]];
		pos[i] = ans;
		cout<<ans<<endl; 
	}
	return 0;
 }