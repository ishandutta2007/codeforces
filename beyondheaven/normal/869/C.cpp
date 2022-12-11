#include<bits/stdc++.h>
#define MaxN 5123
const int Mod=998244353;

int dp[MaxN];
inline int DP(int n,int m)
{
	memset(dp,0,sizeof(dp));
	dp[n]=1;
	for(int i=1;i<=m;++i)
	for(int j=0;j<=n;++j)
	dp[j]=(dp[j]+1LL*(j+1)*dp[j+1])%Mod;
	int ans=0;
	for(int j=0;j<=n;++j)ans=(ans+dp[j])%Mod; 
	return ans;
}

int main()
{
	int a,b,c;scanf("%d%d%d",&a,&b,&c);
	printf("%d\n",static_cast<int>(1LL*DP(a,b)*DP(a,c)%Mod*DP(b,c)%Mod));
	return 0;
}