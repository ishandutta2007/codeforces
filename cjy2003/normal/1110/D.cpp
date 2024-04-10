#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,f,t[1000100],x,ans,dp[2][3][3],op,mx;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		++t[x];
	}
	for(int i=1;i<=m+2;++i)
	{
		op^=1;
		memset(dp[op],0,sizeof(dp[op]));
		for(int j=0;j<=2;++j)
			for(int k=0;k<=2;++k)
				for(int l=0;l<=2;++l)
					if(j+k+l<=t[i-2]&&k+l<=t[i-1]&&l<=t[i])
						dp[op][k][l]=max(dp[op][k][l],dp[op^1][j][k]+l+(t[i-2]-j-k-l)/3);
	}
	printf("%d",dp[op][0][0]);
	return 0;
}