//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[1001][1001],suml[1001],sumh[1001],ans;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	a[1][1]=8;a[1][2]=9; a[1][3]=1; a[1][4]=13;
	a[2][1]=3;a[2][2]=12;a[2][3]=7; a[2][4]=5;
	a[3][1]=0;a[3][2]=2; a[3][3]=4; a[3][4]=11;
	a[4][1]=6;a[4][2]=10;a[4][3]=15;a[4][4]=14;
	for(int i=1;i<=n>>2;++i)
	{
		for(int j=1;j<=n>>2;++j)
		{
			for(int x=1;x<=4;++x)
			{
				for(int y=1;y<=4;++y)
				{
					a[x+i*4-4][y+j*4-4]=a[x][y]+16*(i*n/4+j-1-n/4);
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}