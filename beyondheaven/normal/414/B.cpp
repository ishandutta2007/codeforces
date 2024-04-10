#include<bits/stdc++.h>
#define MaxN 2123
const int Mod=1e9+7;
int dp[MaxN][MaxN];
int main()
{
	int n,k;std::cin>>n>>k;
	dp[0][1]=1;
	for(int i=0;i<k;++i)
	{
		for(int _=1;_<=n;++_)
		for(int j=_;j<=n;j+=_)
		dp[i+1][j]=(dp[i+1][j]+dp[i][_])%Mod;
	}
	int ans=0;
	for(int _=1;_<=n;++_)
	ans=(ans+dp[k][_])%Mod;
	std::cout<<ans<<std::endl;
	return 0;
}