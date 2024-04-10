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
int dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1};
int n,m,i,j,x,used[45][45],ans=1<<25;
void dfs(int dep)
{
	if (dep>ans) return;
	int i,j,k,l,x,y,xx,yy;
	bool fnd=0;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (!used[i][j])
			{
				fnd=1;
				break;
			}
		}
		if (fnd) break;
	}
	if (!fnd)
	{
		ans=min(ans,dep);
		return;
	}
	for (k=0;k<=4;k++)
	{
		x=i+dx[k];
		y=j+dy[k];
		if (x<1||x>n||y<1||y>m) continue;
		for (l=0;l<=4;l++)
		{
			xx=x+dx[l];
			yy=y+dy[l];
			if (xx<1||xx>n||yy<1||yy>m) continue;
			used[xx][yy]++;
		}
		dfs(dep+1);
		for (l=0;l<=4;l++)
		{
			xx=x+dx[l];
			yy=y+dy[l];
			if (xx<1||xx>n||yy<1||yy>m) continue;
			used[xx][yy]--;
		}
	}
}
int main()
{
	cin>>n>>m;
	dfs(0);
	cout<<n*m-ans;
	return 0;
}