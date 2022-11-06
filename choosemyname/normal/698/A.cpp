#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int dp[1000010][3];
int main()
{
	dp[0][0]=0;
	dp[0][1]=dp[0][2]=-inf;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int t1;
		cin>>t1;
		if(t1==1||t1==3)
			dp[i][1]=max(dp[i-1][0],dp[i-1][2])+1;
		else
			dp[i][1]=-inf;
		if(t1==2||t1==3)
			dp[i][2]=max(dp[i-1][0],dp[i-1][1])+1;
		else
			dp[i][2]=-inf;
		dp[i][0]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
	}
	cout<<n-max(max(dp[n][0],dp[n][1]),dp[n][2]);
}