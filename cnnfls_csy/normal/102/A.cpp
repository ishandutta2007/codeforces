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
bool can[105][105];
int n,m,i,j,k,x,y,pri[105],ma=1<<25;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>pri[i];
	for (i=1;i<=m;i++)
	{
		cin>>x>>y;
		can[x][y]=can[y][x]=1;
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			for (k=1;k<=n;k++)
			{
				if (can[i][j]&&can[j][k]&&can[i][k]&&pri[i]+pri[j]+pri[k]<ma) ma=pri[i]+pri[j]+pri[k];
			}
		}
	}
	if (ma<(1<<25)) cout<<ma;
	else cout<<-1;
	return 0;
}