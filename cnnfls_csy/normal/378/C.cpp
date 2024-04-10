#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
char mp[505][505];
int n,m,i,j,ned;
int dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1};
void dfs(int x,int y)
{
	int i;
	for (i=1;i<=4;i++)
	{
		if (mp[x+dx[i]][y+dy[i]]=='.')
		{
			mp[x+dx[i]][y+dy[i]]='@';
			dfs(x+dx[i],y+dy[i]);
		}
	}
	if (ned)
	{
		ned--;
		mp[x][y]='X';
	}
}
int main()
{
	cin>>n>>m>>ned;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			cin>>mp[i][j];
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (mp[i][j]=='.'&&ned)
			{
				dfs(i,j);
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (mp[i][j]=='@') mp[i][j]='.';
			cout<<mp[i][j];
		}
		cout<<endl;
	}
	return 0;
}