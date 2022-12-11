#include<bits/stdc++.h>
#define MaxN 1123
typedef long long LL;
const LL Mod=998244353;

int n,a[MaxN];
LL dp[MaxN][MaxN];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	scanf("%d",a+i);
	
	dp[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=n;++j)
		dp[i][j]=(dp[i-1][j]+dp[i-1][j+1])%Mod;
		if(1<=a[i]&&a[i]<=n)
		dp[i][a[i]]=(dp[i][a[i]]+dp[i-1][0])%Mod;
	}
	
	printf("%lld\n",(dp[n][0]+Mod-1)%Mod);
	return 0;
}