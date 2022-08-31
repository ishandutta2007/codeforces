#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
#define sqr(x) (x)*(x)
using namespace std;
int dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1};
int n,m,i,j,ex,ey,sx,sy,x,y;
char mp[505][505];
queue<int> qx,qy;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			cin>>mp[i][j];
		}
	}
	cin>>sx>>sy>>ex>>ey;
	qx.push(sx);
	qy.push(sy);
	while (!qx.empty())
	{
		x=qx.front();
		y=qy.front();
		qx.pop();
		qy.pop();
		for (i=1;i<=4;i++)
		{
			if (mp[x+dx[i]][y+dy[i]]=='.')
			{
				mp[x+dx[i]][y+dy[i]]='X';
				qx.push(x+dx[i]);
				qy.push(y+dy[i]);
			}
			else if (mp[x+dx[i]][y+dy[i]]=='X'&&x+dx[i]==ex&&y+dy[i]==ey)
			{
				cout<<"YES";
				return 0;
			}
		}
	}
	cout<<"NO";
	return 0;
}