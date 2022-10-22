//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,a[51][51],b[51][51],cnt;
struct d{
	int x,y;
}d[2501];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<n;++i)
	{
		for(int j=1;j<m;++j)
		{
			if(a[i][j]&&a[i][j+1]&&a[i+1][j]&&a[i+1][j+1])
			{
				++cnt;
				d[cnt].x=i;
				d[cnt].y=j;
				b[i][j]=b[i][j+1]=b[i+1][j]=b[i+1][j+1]=1;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(b[i][j]!=a[i][j])
			{
				cout<<"-1"<<endl;
				return 0;
			}
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;++i)
	{
		cout<<d[i].x<<" "<<d[i].y<<endl;
	}
	return 0;
}