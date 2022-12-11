#include<bits/stdc++.h>
#define MaxN 523
int dp[MaxN][MaxN];
bool flag[MaxN][MaxN];
int n,a[MaxN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	scanf("%d",a+i);
	for(int i=1;i<=n;++i)
	dp[i][i]=1;
	for(int len=2;len<=n;++len)
	for(int i=1,j=len;j<=n;++i,j=i+len-1)
	{
		if(j==i+1&&a[i]==a[j])dp[i][j]=1;
		else
		{
			dp[i][j]=0x3f3f3f3f;
			for(int k=i;k<j;++k)
			dp[i][j]=std::min(dp[i][j],dp[i][k]+dp[k+1][j]);
			if(i+1<=j-1&&a[i]==a[j])dp[i][j]=std::min(dp[i][j],dp[i+1][j-1]);
		}
	}
	printf("%d\n",dp[1][n]);
	return 0;
}