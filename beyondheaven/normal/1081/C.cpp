#include<bits/stdc++.h>
#define MaxN 2123
typedef long long LL;
const LL Mod=998244353;

LL dp[MaxN][MaxN];
int main()
{
	int n,m,k;scanf("%d%d%d",&n,&m,&k);++k;
	dp[1][1]=m;
	for(int i=1;i<n;++i)
	for(int j=1;j<=k;++j)
	{
		dp[i+1][j]=(dp[i+1][j]+dp[i][j])%Mod;
		dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j]*(m-1))%Mod;
	}
	printf("%lld\n",dp[n][k]);
	return 0;
}