#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
int dx[5]={0,0,0,-1,1},dy[5]={0,1,-1,0,0};
int n,m,k,i,j,cnt,ans[1000005],cul[1005][1005],x,y;
char mp[1005][1005];
bool used[1005][1005];
void dfs1(int x,int y,int cu)
{
	cul[x][y]=cu;
	used[x][y]=1;
	int i;
	for (i=1;i<=4;i++)
	{
		if (!cul[x+dx[i]][y+dy[i]]&&mp[x+dx[i]][y+dy[i]]=='.')
		{
			dfs1(x+dx[i],y+dy[i],cu);
		}
		if (!used[x+dx[i]][y+dy[i]]&&mp[x+dx[i]][y+dy[i]]=='*')
		{
			ans[cu]++;
		}
	}
}
int main()
{
	cin>>n>>m>>k;
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
			if (!cul[i][j]&&mp[i][j]=='.')
			{
				dfs1(i,j,++cnt);
			}
		}
	}
	for (i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",ans[cul[x][y]]);
	}
}