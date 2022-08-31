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
int n,m,i,j,dp[8005],a,b,c;
int main()
{
	cin>>n>>a>>b>>c;
	for (i=1;i<=n;i++)
	{
		dp[i]=-1<<25;
		if (i>=a) dp[i]=max(dp[i],dp[i-a]+1);
		if (i>=b) dp[i]=max(dp[i],dp[i-b]+1);
		if (i>=c) dp[i]=max(dp[i],dp[i-c]+1);
	}
	cout<<dp[n];
	return 0;
}