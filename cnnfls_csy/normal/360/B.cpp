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
long long n,m,i,j,num[2005],l,r,mid,ans,dp[2005];
bool check(long long x)
{
	int i,j;
//	memset(dp,0,sizeof(dp));
	for (i=1;i<=n;i++) dp[i]=i-1;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<i;j++) 
		{
			if (abs(num[i]-num[j])<=x*(i-j)) 
			{
				dp[i]=min(dp[i],dp[j]+i-j-1);
			}
		}
	}
	for (i=1;i<=n;i++) if (dp[i]+(n-i)<=m) return 1;
	return dp[n]<=m;
}
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	l=0;ans=r=2e9;
	while (l<r)
	{
		mid=(l+r)/2;
		if (check(mid))
		{
			r=mid;
			ans=mid;
		}
		else l=mid+1;
	}
	cout<<ans;
	return 0;
}