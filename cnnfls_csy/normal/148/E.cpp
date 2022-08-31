#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#define llx(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,k,l,sum,num[105][105],f[105][105],dp[105][10005],cnt[105];
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&cnt[i]);
		for (j=1;j<=cnt[i];j++)
		{
			scanf("%d",&num[i][j]);
		}
		for (j=0;j<=cnt[i];j++)
		{
			for (k=0;j+k<=cnt[i];k++)
			{
				sum=0;
				for (l=1;l<=j;l++) sum+=num[i][l];
				for (l=cnt[i]-k+1;l<=cnt[i];l++) sum+=num[i][l];
				f[i][j+k]=max(f[i][j+k],sum);
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=0;j<=m;j++)
		{
			for (k=0;k<=j&&k<=cnt[i];k++)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j-k]+f[i][k]);
			}
		}
	}
	printf("%d\n",dp[n][m]);
	return 0;
}