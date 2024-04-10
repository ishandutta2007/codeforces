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
int n,m,i,j,mii=1005,mij=1005,mai,maj;
char a[1005][1005];
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if (a[i][j]=='X')
			{
				mii=min(mii,i);
				mij=min(mij,j);
				mai=max(mai,i);
				maj=max(maj,j);
			}
		}
	}
	for (i=mii;i<=mai;i++)
	{
		for (j=mij;j<=maj;j++)
		{
			if (a[i][j]=='.') {cout<<"NO";return 0;}
		}
	}
	cout<<"YES";
	return 0;
}