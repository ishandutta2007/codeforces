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
int n,m,i,j;
char mp[15][15],mp2[15][15],mp3[15][15];
void zhuan()
{
	int i,j;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			mp3[i][j]=mp[j][n-i+1];
		}
	}
	memcpy(mp,mp3,sizeof(mp));
}
bool eq()
{
	int i,j;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (mp[i][j]!=mp2[i][j]) return 0;
		}
	}
	return 1;
}
bool check()
{
	if (eq()) return 1;
	int i,j;
	for (i=1;i<=n/2;i++)
	{
		for (j=1;j<=n;j++)
		{
			swap(mp[i][j],mp[n-i+1][j]);
		}
	}
	if (eq()) return 1;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n/2;j++)
		{
			swap(mp[i][j],mp[n-i+1][j]);
		}
	}
	if (eq()) return 1;
	for (i=1;i<=n/2;i++)
	{
		for (j=1;j<=n;j++)
		{
			swap(mp[i][j],mp[n-i+1][j]);
		}
	}
	if (eq()) return 1;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n/2;j++)
		{
			swap(mp[i][j],mp[n-i+1][j]);
		}
	}
	return 0;
}
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			cin>>mp[i][j];
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			cin>>mp2[i][j];
		}
	}
	for (i=1;i<=4;i++)
	{
		zhuan();
		if (check())
		{
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}