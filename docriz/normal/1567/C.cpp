#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[11][2][2],T,n[10];
int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		ll N;
		scanf("%lld",&N);
		for(int i=0;i<10;i++)n[i]=N%10,N/=10;
		memset(dp,0,sizeof(dp));
		dp[0][0][0]=1;
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<2;j++)
			{
				for(int k=0;k<2;k++)
				{
					if(!dp[i][j][k])continue;
					for(int u=0;u<10;u++)
					{
						int r;
						if(u+j<=n[i])r=0;
						else r=1;
						dp[i+1][k][r]+=dp[i][j][k];
					}
				}
			}
		}
		printf("%lld\n",dp[10][0][0]-2);
	}
	return 0;
}