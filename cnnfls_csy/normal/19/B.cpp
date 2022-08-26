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
long long n,ti[2005],co[2005],dp[2005][2005],i,j;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>ti[i]>>co[i];
		ti[i]++;
	}
	for (i=0;i<=n;i++) 
	{
		for (j=1;j<=n;j++) dp[i][j]=1e16;
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			dp[i][j]=min(dp[i-1][j],dp[i-1][max(0ll,j-ti[i])]+co[i]);
		}
	}
	cout<<dp[n][n];
	return 0;
}