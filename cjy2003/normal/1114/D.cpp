#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[5050][5050],c[5050],n,a[5050],cnt;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&c[i]);
		if(c[i]!=c[i-1])a[++cnt]=c[i];
	}
//	for(int i=1;i<=cnt;++i)
//		printf("%d ",a[i]);
//	printf("\n");
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=cnt;++i)
		dp[i][i]=0;
	for(int i=1;i<cnt;++i)
		for(int j=1;j<=cnt-i+1;++j)
		{
			if(j>1)dp[j-1][j+i-1]=min(dp[j-1][j+i-1],dp[j][j+i-1]+1);
			if(j+i<=cnt)dp[j][j+i]=min(dp[j][j+i],dp[j][j+i-1]+1);
			if(j>1&&j+i<=cnt&&a[j-1]==a[j+i])dp[j-1][j+i]=min(dp[j-1][j+i],dp[j][j+i-1]+1);
		}
	printf("%d",dp[1][cnt]);
	return 0;
}