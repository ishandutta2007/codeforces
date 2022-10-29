#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define LIM 360360
typedef long long ll;
ll dp[LIM+1];
int main()
{
	ll num,mok,gen;
	scanf("%I64d%I64d%I64d",&num,&mok,&gen);
	fill(dp,dp+LIM+1,1000000000);
	dp[LIM]=0;
	for(int i=LIM;i>=1;i--)
	{
		for(int j=2;j<=gen;j++)
		{
			dp[(i/j)*j]=min(dp[(i/j)*j],dp[i]+1);
		}
		dp[i-1]=min(dp[i-1],dp[i]+1);
	}
	ll tim=num/360360-(mok-1)/360360-1;
	ll ret=0;
	if(tim==-1)
	{
		fill(dp,dp+360161,1000000000);
		dp[num%360360]=0;
		for(int i=num%360360;i>=1;i--)
		{
			for(int j=2;j<=gen;j++)
			{
				dp[i/j*j]=min(dp[i/j*j],dp[i]+1);
			}
			dp[i-1]=min(dp[i-1],dp[i]+1);
		}
		printf("%I64d\n",dp[mok%360360]);
	}
	else
	{
		ll ret=tim*dp[0]+dp[mok%360360];
		fill(dp,dp+360161,1000000000);
		dp[num%360360]=0;
		for(int i=num%360360;i>=1;i--)
		{
			for(int j=2;j<=gen;j++)
			{
				dp[i/j*j]=min(dp[i/j*j],dp[i]+1);
			}
			dp[i-1]=min(dp[i-1],dp[i]+1);
		}
		ret+=dp[0];
		printf("%I64d\n",ret);
	}
}