#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
int n,m,i,j,s,a[55][55],d[55];
char ch;
vector<int> c[4];
int zf(int x,int j)
{
	int i;
	for (i=2;i<=m;i++)
	if (a[j][i]==x) return i-1;
	return 2147480000;
}
int ff(int x,int j)
{
	int i;
	for (i=m;i>=1;i--)
	if (a[j][i]==x) return m-i+1;
	return 2147480000;
}
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	for (j=1;j<=m;j++)
	{
		cin>>ch;
		if (ch>='0'&&ch<='9') a[i][j]=1;
		if (ch>='a'&&ch<='z') a[i][j]=2;
		if (ch=='*'||ch=='&'||ch=='#') a[i][j]=3;
	}
	for (j=1;j<=3;j++) c[j].push_back(0);
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=3;j++)
		if (a[i][1]==j){c[j].push_back(i);c[j][0]++;}
	}
/*	for (i=1;i<=3;i++)
	{
		cout<<c[i][0]<<' ';
	}*/
	int Min,ms;
	for (i=1;i<=3;i++)
	if (!c[i][0])
	{
		Min=2147480000;
		for (j=1;j<=n;j++)
		if (a[j][1]!=i&&!d[j])
		{
			if (c[a[j][1]][0]>1)
			{
				int xx=min(zf(i,j),ff(i,j));
				if (xx<Min)
				{
					Min=xx;
					ms=j;
				}
			}
		}
		if (Min==2147480000) {cout<<-1;return 0;} 
		c[a[ms][1]][0]--;
		d[ms]=1;
		c[i][0]++;
		s+=Min;
	}
	cout<<s;
	return 0;
}