#include<bits/stdc++.h>
using namespace std;
int T,dp[100005][2];
char s[100005],t[100005];
const int inf=1e9;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int ok=0;
		scanf("%s%s",s,t);
		int n,m;
		n=strlen(s);m=strlen(t);
		for(int i=0;i<n/2;i++)swap(s[i],s[n-1-i]);
		for(int i=0;i<m/2;i++)swap(t[i],t[m-1-i]);
		for(int i=n-1;i>=0;i--)swap(s[i],s[i+1]);
		for(int i=m-1;i>=0;i--)swap(t[i],t[i+1]);
		dp[0][0]=0;dp[0][1]=-inf;
		for(int i=1;i<=n;i++)dp[i][0]=dp[i][1]=-inf;
		for(int i=0;i<=n;i++)
		{

			if(max(dp[i][0],dp[i][1])>=m)
			{
				ok=1;
				break;
			}
			if(i==n)continue;
			for(int j=0;j<2;j++)
			{
				if(dp[i][j]<0)continue;
				int res=(i+2-j)%2;
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
				if(res==0)
				{
					if(s[i+1]==t[dp[i][j]+1])dp[i+1][!j]=max(dp[i+1][!j],dp[i][j]+1);
				}
			}
		}
		if(ok)printf("yes\n");
		else printf("no\n");
	}
	return 0;
}