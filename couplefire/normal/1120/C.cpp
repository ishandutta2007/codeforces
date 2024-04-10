#include<bits/stdc++.h>
#define maxn 5005
using namespace std;
int n,a,b;
char s[maxn];
int dp[maxn][maxn];
int dp2[maxn];
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(s[i]==s[j])
				dp[i][j]=dp[i-1][j-1]+1;
	for(int i=1;i<=n;i++)
	{
		dp2[i]=dp2[i-1]+a;
		for(int j=1;j<i;j++)
		{
			int x=min(i-j,dp[i][j]);
			dp2[i]=min(dp2[i],dp2[i-x]+b);
		}
	}
	printf("%d\n",dp2[n]);
}