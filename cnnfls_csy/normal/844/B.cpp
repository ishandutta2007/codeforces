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
long long n,m,i,j,ans,x,cx[56][2],cy[56][2],ss,c[56][56];
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++) 
		{
			cin>>x;
			cx[i][x]++;
			cy[j][x]++;
		}
	}
	ans=n*m;
	c[0][0]=1;
	for (i=1;i<=50;i++)
	{
		c[i][0]=1;
		for (j=1;j<=50;j++)
		{
			c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=2;j<=cx[i][0];j++) ans+=c[cx[i][0]][j];
		for (j=2;j<=cx[i][1];j++) ans+=c[cx[i][1]][j];
	}
	for (i=1;i<=m;i++)
	{
		for (j=2;j<=cy[i][0];j++) ans+=c[cy[i][0]][j];
		for (j=2;j<=cy[i][1];j++) ans+=c[cy[i][1]][j];
	}
	cout<<ans;
	return 0;
}