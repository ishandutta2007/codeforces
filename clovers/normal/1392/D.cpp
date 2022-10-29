#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(1e9);
const ll INF=(ll)(5e18);
const int N=300010;

int t,n;
char s[N];
int dp[N][2][2];//0L 1R

int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		int ans=inf;//1:L 2:R
		for(int i=1;i<=n;i++)
			dp[i][0][0]=dp[i][0][1]=dp[i][1][0]=dp[i][1][1]=inf;
		if(s[1]=='R') dp[1][0][0]=1;//n:L 1:L
		else dp[1][0][0]=0;
		for(int i=2;i<=n;i++)
		{
			int L=0,R=0;
			if(s[i]=='L') R++;
			else L++;
			dp[i][0][0]=dp[i-1][1][0]+L;
			dp[i][0][1]=min(dp[i-1][1][0],dp[i-1][0][0])+R;
			dp[i][1][0]=min(dp[i-1][1][1],dp[i-1][0][1])+L;
			dp[i][1][1]=dp[i-1][0][1]+R;
		}
		ans=min(ans,dp[n][1][0]);
		
		for(int i=1;i<=n;i++)
			dp[i][0][0]=dp[i][0][1]=dp[i][1][0]=dp[i][1][1]=inf;
		if(s[1]=='R') dp[1][1][0]=1;//n:R 1:L
		else dp[1][1][0]=0;
		for(int i=2;i<=n;i++)
		{
			int L=0,R=0;
			if(s[i]=='L') R++;
			else L++;
			dp[i][0][0]=dp[i-1][1][0]+L;
			dp[i][0][1]=min(dp[i-1][1][0],dp[i-1][0][0])+R;
			dp[i][1][0]=min(dp[i-1][1][1],dp[i-1][0][1])+L;
			dp[i][1][1]=dp[i-1][0][1]+R;
		}
		ans=min(ans,min(dp[n][1][1],dp[n][0][1]));
		
		for(int i=1;i<=n;i++)
			dp[i][0][0]=dp[i][0][1]=dp[i][1][0]=dp[i][1][1]=inf;
		if(s[1]=='L') dp[1][0][1]=1;//n:L 1:R
		else dp[1][0][1]=0;
		for(int i=2;i<=n;i++)
		{
			int L=0,R=0;
			if(s[i]=='L') R++;
			else L++;
			dp[i][0][0]=dp[i-1][1][0]+L;
			dp[i][0][1]=min(dp[i-1][1][0],dp[i-1][0][0])+R;
			dp[i][1][0]=min(dp[i-1][1][1],dp[i-1][0][1])+L;
			dp[i][1][1]=dp[i-1][0][1]+R;
		}
		ans=min(ans,min(dp[n][1][0],dp[n][0][0]));
		
		for(int i=1;i<=n;i++)
			dp[i][0][0]=dp[i][0][1]=dp[i][1][0]=dp[i][1][1]=inf;
		if(s[1]=='L') dp[1][1][1]=1;//n:R 1:R
		else dp[1][1][1]=0;
		for(int i=2;i<=n;i++)
		{
			int L=0,R=0;
			if(s[i]=='L') R++;
			else L++;
			dp[i][0][0]=dp[i-1][1][0]+L;
			dp[i][0][1]=min(dp[i-1][1][0],dp[i-1][0][0])+R;
			dp[i][1][0]=min(dp[i-1][1][1],dp[i-1][0][1])+L;
			dp[i][1][1]=dp[i-1][0][1]+R;
		}
		ans=min(ans,dp[n][0][1]);
		printf("%d\n",ans);
	}
	return 0;
}