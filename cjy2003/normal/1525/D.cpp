#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[5050],dp[5050][10010];
inline void upmin(int &x,int y){x>y?x=y:0;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	memset(dp,0x3f,sizeof(dp));
	dp[0][n]=0;
	for(int i=1;i<=n;++i)
		for(int j=-n;j<=n;++j)
			if(dp[i-1][j+n]!=0x3f3f3f3f)
			{
				if(a[i]==0)
				{
					upmin(dp[i][j+n],dp[i-1][j+n]+abs(j));
					upmin(dp[i][j+n-1],dp[i-1][j+n]+abs(j));
				}
				else upmin(dp[i][j+n+1],dp[i-1][j+n]+abs(j));
			}
	printf("%d",dp[n][n]);
	return 0;
}