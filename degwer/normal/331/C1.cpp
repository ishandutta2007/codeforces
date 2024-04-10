#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dp[1000001];
int main()
{
	int num;
	scanf("%d",&num);
	fill(dp,dp+num+1,1000000000);
	dp[0]=0;
	for(int i=1;i<=num;i++)
	{
		int z=i;
		for(;;)
		{
			if(z==0)
			{
				break;
			}
			dp[i]=min(dp[i],dp[i-z%10]+1);
			z/=10;
		}
	}
	printf("%d\n",dp[num]);
}