#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n,m;
int c[1000010];
int dp[1000001][3][5];
int main()
{
	memset(dp,-1,sizeof dp);
	scanf("%d%d",&n,&m);
	for (int i=1,x;i<=n;i++)
	{
		scanf("%d",&x); c[x]++;
	}
	if (m==1){printf("%d\n",c[1]/3);return 0;}
	for (int i=0;i<3&&i<=c[1];i++)
		for (int j=0;j<5&&j<=c[2];j++)
			dp[2][i][j]=(c[1]-i)/3+(c[2]-j)/3;
	for (int i=3;i<=m;i++)
	{
		for (int j=0;j<3;j++)
			for (int k=0;k<5;k++)
			{
				if (dp[i-1][j][k]==-1) continue;
				for (int u=0;u<=j&&u<=k&&u<=c[i];u++)
					for (int v=0;v<5&&u+v<=c[i];v++)
						dp[i][min(k-u,2)][v]=max(dp[i][min(k-u,2)][v],dp[i-1][j][k]+u+(c[i]-u-v)/3);
			}
	}
	int ans=0;
	for (int i=0;i<3&&i<=c[m-1];i++)
		for (int j=0;j<5&&j<=c[m];j++)
			ans=max(ans,dp[m][i][j]);
	printf("%d\n",ans);
	return 0;
}