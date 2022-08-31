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
int n,m,i,j,k;
char mp[2005][205],mp2[205][2005];
unsigned long long h[2005][205][2],h2[205][2005][2],e[2]={1000000007,1000000009},po[2005][2];
bool eq(int x,int y,int xx,int yy)
{
	int i;
	for (i=0;i<=1;i++)
	{
		if (!((h[x][y+m-1][i]-h[x][y-1][i]*po[m][i])==(h2[xx][yy+m-1][i]-h2[xx][yy-1][i]*po[m][i]))) return 0;
	}
	return 1;
}
bool check(int x,int y)
{
	int i;
	for (i=1;i<=m;i++)
	{
		if (!eq(x+i-1,1,i,y)) return 0;
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	po[0][0]=1;
	po[0][1]=1;
	for (i=1;i<=n;i++)
	{
		for (j=0;j<=1;j++)
		{
			po[i][j]=po[i-1][j]*e[j];
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			cin>>mp[i][j];
			for (k=0;k<=1;k++)
			{
				h[i][j][k]=h[i][j-1][k]*e[k]+mp[i][j];
			}
		}
	}
	for (i=1;i<=m;i++)
	{
		for (j=1;j<=n;j++)
		{
			cin>>mp2[i][j];
			for (k=0;k<=1;k++)
			{
				h2[i][j][k]=h2[i][j-1][k]*e[k]+mp2[i][j];
			}
		}
	}
	for (i=1;i+m-1<=n;i++)
	{
		for (j=1;j+m-1<=n;j++)
		{
			if (check(i,j))
			{
				cout<<i<<' '<<j<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}