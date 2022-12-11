#include<cstdio>
#include<algorithm>
using namespace std;

int n; int X,c[110];
double dp[110][10010];
double C[110][110];
int main()
{
	scanf("%d%d",&n,&X);
	for (int i=1;i<=n;i++) scanf("%d",c+i);
	dp[0][0]=1; int S=0;
	for (int i=1;i<=n;i++){
		for (int j=i-1;j>=0;j--)
			for (int k=0;k<=S;k++)
				dp[j+1][k+c[i]]+=dp[j][k];
		S+=c[i];
	}
	for (int i=0;i<=n;i++){
		C[i][0]=1; for (int j=1;j<=i;j++) C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	double ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=S;j++)
			ans+=dp[i][j]/C[n][i]*min((1.0*n/i+1)*X/2,1.0*j/i);
	printf("%.11lf\n",ans);
	return 0;
}