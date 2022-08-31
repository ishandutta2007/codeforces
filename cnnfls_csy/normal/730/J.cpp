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
struct bottle
{
	int mx,now;
}bot[105];
int n,m,i,j,k,ans,sum,now,dp[105][105][10005],sum2;
bool cmp(bottle x,bottle y)
{
	if (x.mx>y.mx) return 1;
	return 0;
}
int main()
{
	cin>>n;
	for (i=1;i<=n;i++) 
	{
		cin>>bot[i].now;
		sum+=bot[i].now;
	}
	for (i=1;i<=n;i++) cin>>bot[i].mx;
	sort(bot+1,bot+n+1,cmp);
	for (i=1;i<=n;i++)
	{
		now+=bot[i].mx;
		ans++;
		//cerr<<now<<' '<<ans<<endl;
		if (now>=sum) break;
	}
	cout<<ans<<' ';
	/*sum2=now;
	//cerr<<i<<endl;
	for (i++;i<=n;i++)
	{
		sum2+=bot[i].mx;
	//	cerr<<i<<' '<<sum2<<endl;
	}*/
	for (i=0;i<=n;i++)
	{
		for (j=0;j<=ans;j++)
		{
			for (k=1;k<=sum;k++)
			{
				dp[i][j][k]=-(1<<25);
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=ans;j++)
		{
			for (k=1;k<=sum;k++)
			{
				dp[i][j][k]=max(dp[i-1][j][k],dp[i-1][j-1][max(0,k-bot[i].mx)]+bot[i].now);
			}
		}
	}
	/*for (i=1;i<=n;i++)
	{
		for (j=1;j<=ans;j++)
		{
			for (k=1;k<=sum;k++)
			{
				cerr<<dp[i][j][k]<<' ';
			}
			cerr<<endl;
		}
		cerr<<endl;
	}*/
	cout<<sum-dp[n][ans][sum];
	return 0;
}