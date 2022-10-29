#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod=1000000007;
int com[4001][4001];
ll dp[4001][4001];
int main()
{
	com[0][0]=1;
	for(int i=1;i<=4000;i++)
	{
		com[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			com[i][j]=(com[i-1][j-1]+com[i-1][j])%mod;
		}
	}
	dp[0][0]=1;
	for(int i=1;i<=4000;i++)
	{
		for(ll j=1;j<=4000;j++)
		{
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]*j)%mod;
		}
	}
	int num;
	scanf("%d",&num);
	ll ret=0;
	for(int i=0;i<=num-1;i++)
	{
		for(int j=0;j<=num-1;j++)
		{
			ret+=dp[i][j]*(ll)com[num][num-i];
			ret%=mod;
		}
	}
	printf("%I64d\n",ret);
}