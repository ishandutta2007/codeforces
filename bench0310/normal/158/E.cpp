#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int t[n+1],d[n+1];
	for(int i=1;i<=n;i++) scanf("%d%d",&t[i],&d[i]);
	int dp[n+1][k+1];
	for(int i=0;i<=k;i++) dp[0][i]=1;
	for(int o=1;o<=n;o++)
    {
        dp[o][0]=max(dp[o-1][0],t[o])+d[o];
        for(int i=1;i<=k;i++) dp[o][i]=min(dp[o-1][i-1],max(dp[o-1][i],t[o])+d[o]);
    }
    int res=86401-dp[n][k];
    for(int i=1;i<=n;i++) res=max(res,t[i]-dp[i-1][k]);
    printf("%d\n",res);
	return 0;
}