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
long long dp[5],n,i,j,s;
int main()
{
	cin>>n;
	dp[4]=1;
	for (i=1;i<=n;i++)
	{
		s=0;
		for (j=1;j<=4;j++)
		{
			s+=dp[j];
		}
		for (j=1;j<=4;j++)
		{
			dp[j]=(s-dp[j])%((long long)1e9+7);
		}
	}
	cout<<dp[4];
	return 0;
}