#include<bits/stdc++.h>
#define MaxN 5123
char A[MaxN],B[MaxN];
int dp[MaxN][MaxN];
int main()
{
	int n,m,ans=0;
	scanf("%d%d%s%s",&n,&m,A+1,B+1);
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	{
		dp[i][j]=std::max(dp[i][j],dp[i-1][j]-1);
		dp[i][j]=std::max(dp[i][j],dp[i][j-1]-1);
		if(A[i]==B[j])dp[i][j]=std::max(dp[i][j],dp[i-1][j-1]+2);
		ans=std::max(ans,dp[i][j]);
	}
	printf("%d\n",ans);
	return 0;
}