#include<bits/stdc++.h>
#define MaxN 200123
typedef long long LL;
const LL Mod=1e9+7;

LL dp[MaxN][3],g[3];
int main()
{
	int n,l,r;scanf("%d%d%d",&n,&l,&r);
	
	for(int i=0;i<3;++i)g[i]+=r/3;
	for(int i=1;i<=r%3;++i)++g[i];
	
	--l;
	for(int i=0;i<3;++i)g[i]-=l/3;
	for(int i=1;i<=l%3;++i)--g[i];
	
	dp[0][0]=1;
	for(int i=0;i<n;++i)
	for(int j=0;j<3;++j)
	for(int k=0;k<3;++k)
	dp[i+1][(j+k)%3]=(dp[i+1][(j+k)%3]+dp[i][j]*g[k])%Mod;
	
	printf("%lld\n",dp[n][0]);
	return 0;
}