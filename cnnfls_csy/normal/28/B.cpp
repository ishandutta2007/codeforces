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
int n,m,i,j,k,dis,num[105];
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		can[i][i]=1;
		cin>>num[i];
	}
	for (i=1;i<=n;i++)
	{
		cin>>dis;
		if (i+dis<=n) can[i][i+dis]=can[i+dis][i]=1;
		if (i-dis>=1) can[i][i-dis]=can[i-dis][i]=1;
	}
	for (k=1;k<=n;k++)
	{
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			{
				if (k!=i&&i!=j&&j!=k&&can[i][k]&&can[k][j])
				{
					can[i][j]=1;
				}
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		if (!can[i][num[i]])
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}