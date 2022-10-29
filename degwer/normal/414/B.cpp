#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dp[2001][2001];
ll mod=1000000007;
int main()
{
	int gen,num;
	scanf("%d%d",&gen,&num);
	dp[0][1]=1;
	for(int i=0;i<num;i++)
	{
		for(int k=1;k<=gen;k++)
		{
			for(int j=k;j<=gen;j+=k)
			{
				dp[i+1][j]+=dp[i][k];
				dp[i+1][j]%=mod;
			}
		}
	}
	ll ret=0;
	for(int i=0;i<=gen;i++)
	{
		ret+=dp[num][i];
	}
	printf("%I64d\n",ret%mod);
}