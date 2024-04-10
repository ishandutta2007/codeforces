#include<iostream>
using namespace std;
int n,m,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char str[1003][1003];
bool vis[1003][1003][4][3];
inline bool dfs(int x,int y,int d,int c)
{
	if(x<0||x>=n||y<0||y>=m||str[x][y]=='*')return false;
	if(str[x][y]=='T')return true;
	if(vis[x][y][d][c])return false;
	vis[x][y][d][c]=true;
	if(dfs(x+dx[d],y+dy[d],d,c))return true;
	for(int i=0;i<4;i++)
	{
		if(i==d)continue;
		if(c>0&&dfs(x+dx[i],y+dy[i],i,c-1))return true;
	}
	return false;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		scanf("%s",str[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(str[i][j]=='S')
			{
				for(int k=0;k<4;k++)
					if(dfs(i,j,k,2))
					{
						puts("YES");
						return 0;
					}
				puts("NO");
				return 0;
			}
}