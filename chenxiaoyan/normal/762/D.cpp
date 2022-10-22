/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=100000;
int n;
int a[4][N+1];
int dp[N+1][4];
signed main(){
	cin>>n;
	for(int i=1;i<=3;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
	dp[0][2]=dp[0][3]=-inf;
	int now1=-inf,now3=-inf;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			dp[i][j]=-inf;
			for(int k=1;k<=3;k++){
				int l=min(j,k),r=max(j,k),sum=0;
				for(int o=l;o<=r;o++)sum+=a[o][i];
				dp[i][j]=max(dp[i][j],dp[i-1][k]+sum);
			}
		}
		now1+=a[1][i]+a[2][i]+a[3][i];
		now1=max(now1,a[1][i]+a[2][i]+a[3][i]+dp[i-1][3]);
		now3+=a[1][i]+a[2][i]+a[3][i];
		now3=max(now3,a[1][i]+a[2][i]+a[3][i]+dp[i-1][1]);
		dp[i][1]=max(dp[i][1],now1);
		dp[i][3]=max(dp[i][3],now3);
//		for(int j=1;j<=3;j++)printf("dp[%lld][%lld]=%lld\n",i,j,dp[i][j]);
	}
	cout<<dp[n][3];
	return 0;
}