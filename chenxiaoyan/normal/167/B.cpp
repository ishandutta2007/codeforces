#include<bits/stdc++.h>
using namespace std;
#define N 200
double p[N+1],dp[N+1][N+1][2*N+1];
int a[N+1];
int main(){
	int n,lim,m,i,j,k;scanf("%d%d%d",&n,&lim,&m);
	for(i=1;i<=n;i++)scanf("%lf",p+i),p[i]/=100.;
	for(i=1;i<=n;i++)scanf("%d",a+i);
	dp[0][0][min(n,m)+n]=1.;
	for(i=1;i<=n;i++)for(j=0;j<=i;j++){
		for(k=-j;k<n;k++)
			dp[i][j][k+n]=(1.-p[i])*dp[i-1][j][k+n]+p[i]*(j&&k-a[i]>=-n?dp[i-1][j-1][k-a[i]+
			n]:0.);
		dp[i][j][2*n]=(1.-p[i])*dp[i-1][j][2*n];
		for(k=max(n-a[i],-n);k<=n;k++)dp[i][j][2*n]+=p[i]*(j?dp[i-1][j-1][k+n]:0.);
	}
//	for(i=0;i<=n;i++)for(j=0;j<=i;j++)for(k=-n;k<=n;k++)
//		printf("dp[%d][%d][%d]=%.5lf\n",i,j,k,dp[i][j][k+n]);
	double ans=0.;
	for(i=lim;i<=n;i++)for(j=n;j<=2*n;j++)ans+=dp[n][i][j];
	printf("%.100lf\n",ans);
	return 0;
}
/*1
3 1 0
10 20 30
-1 -1 2
*/
/*2
1 1 1
100
123
*/