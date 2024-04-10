#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,k,num[15],us[15],usn[15],co[15],dp[15][1005];
int main()
{
	cin>>m>>n;
	n++;
	cin>>usn[n]>>co[n];
	for (i=1;i<n;i++)
	{
		cin>>num[i]>>us[i]>>usn[i]>>co[i];
	}
	/*for (i=1;i<=n;i++)
	{
		cerr<<num[i]<<' '<<us[i]<<' '<<usn[i]<<' '<<co[i]<<endl;
	}*/
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			dp[i][j]=dp[i-1][j];
			for (k=1;k*us[i]<=num[i]&&k*usn[i]<=j;k++)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j-k*usn[i]]+co[i]*k);
			}
		}
	}
	cout<<dp[n][m];
	return 0;
}