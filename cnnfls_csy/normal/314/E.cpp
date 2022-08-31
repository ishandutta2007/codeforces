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
unsigned int n,m,i,j,dp[100005],cnt;
string st;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>st;
	if (n&1)
	{
		cout<<0;
		return 0;
	}
	st=" "+st;
	for (i=1;i<=n;i++)
	{
		if (st[i]=='?') cnt++;
	}
	if (cnt<n/2)
	{
		cout<<0;
		return 0;
	}
	dp[0]=1;
	for (i=1;i<=n;i++)
	{
		unsigned int mi=max(1,(int)(i-n/2)),mx=(i)/2;
		if (st[i]=='?') for (j=mx;j>=mi;j--)
		{
			dp[j]+=dp[j-1];
		}
	}
	for (i=1;i<=cnt-n/2;i++)
	{
		dp[n/2]*=25;
	}
	cout<<dp[n/2];
	return 0;
}