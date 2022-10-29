#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dp[5001];
ll rui[5001];
ll mod=1000000007;
int main()
{
	int num,beg,fbd,kai;
	scanf("%d%d%d%d",&num,&beg,&fbd,&kai);
	dp[beg]=1;
	for(int i=1;i<=kai;i++)
	{
		for(int j=1;j<=num;j++)
		{
			rui[j]=(rui[j-1]+dp[j])%mod;
		}
		for(int j=1;j<=num;j++)
		{
			if(j==fbd)dp[j]=0;
			if(j<fbd)
			{
				dp[j]=(rui[(j+fbd-1)/2]-dp[j]+mod)%mod;
			}
			if(j>fbd)
			{
				dp[j]=(rui[num]-rui[(j+fbd)/2]-dp[j]+mod+mod)%mod;
			}
		}
	}
	ll sum=0;
	for(int i=1;i<=num;i++)
	{
		sum+=dp[i];
		sum%=mod;
	}
	printf("%I64d\n",sum);
}