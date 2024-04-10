/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=100;
int n;
int a[N+1],b[N+1];
double dp[2][N+1][N*N+1];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int i=0;i<=n;i++)for(int j=0;j<=n*100;j++)dp[0][i][j]=-inf;
	dp[0][0][0]=0;
	for(int i=1;i<=n;i++)for(int j=0;j<=n;j++)for(int k=0;k<=n*100;k++){
		dp[i&1][j][k]=max(j&&k>=a[i]?dp[i-1&1][j-1][k-a[i]]+b[i]:-inf,
						  dp[i-1&1][j][k]+b[i]/2.);
	}
	for(int i=1;i<=n;i++){
		double ans=-inf;
		for(int j=0;j<=n*100;j++)ans=max(ans,min(1.*j,dp[n&1][i][j]));
		printf("%lf ",ans);
	}
	return 0;
}