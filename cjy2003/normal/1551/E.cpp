#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,k,a[2020];
int dp[2020][2020];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		dp[0][0]=0;
		for(int i=1;i<=n;++i)
		{
			dp[i][0]=0;
			for(int j=1;j<i;++j)dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+(a[i]==j));
			dp[i][i]=dp[i-1][i-1]+(a[i]==i);
		}
		int ans=0;
		for(int i=1;i<=n;++i)if(dp[n][i]>=k)ans=i;
		if(ans)printf("%d\n",n-ans);
		else printf("-1\n");
	}
	return 0;
}