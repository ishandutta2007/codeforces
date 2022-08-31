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
long long n,m,i,j,k,num[5][205][205],ans,mi=1<<25,p[5];
int main()
{
	cin>>n;
	for (k=1;k<=4;k++)
	{
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			{
				char ch;
				cin>>ch;
				num[k][i][j]=ch-'0';
			}
		}
		p[k]=k;
	}
	do
	{
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			{
				num[0][i][j]=num[p[1]][i][j];
			}
		}
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			{
				num[0][i][j+n]=num[p[2]][i][j];
			}
		}
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			{
				num[0][i+n][j]=num[p[3]][i][j];
			}
		}
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			{
				num[0][i+n][j+n]=num[p[4]][i][j];
			}
		}
		ans=0;
		for (i=1;i<=n+n;i++)
		{
			for (j=1;j<=n+n;j++)
			{
				ans+=(num[0][i][j]!=((i+j)%2));
			}
		}
		mi=min(mi,ans);
		ans=0;
		for (i=1;i<=n+n;i++)
		{
			for (j=1;j<=n+n;j++)
			{
				ans+=(num[0][i][j]==((i+j)%2));
			}
		}
		mi=min(mi,ans);
	}
	while (next_permutation(p+1,p+4+1));
	cout<<mi;
	return 0;
}