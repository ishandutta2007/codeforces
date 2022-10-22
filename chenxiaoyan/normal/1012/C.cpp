/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int n;
int a[N+2];
int dp[N+1][N/2+1][2][2]; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0][0]=0;// 
	for(int i=1;i<=n;i++)for(int j=0;j<=n+1>>1;j++){// 
		dp[i][j][0][0]=min(dp[i-1][j][0][0],dp[i-1][j][1][0]);
		if(j){
			dp[i][j][0][1]=dp[i-1][j-1][0][0]+max(0,a[i-1]-(a[i]-1))+max(0,a[i+1]-(a[i]-1));
//			cout<<dp[i-1][j-1][0][0]<<" "<<max(0,a[i-1]-(a[i]-1))<<" "<<max(0,a[i+1]-(a[i]-1))<<" "<<dp[i][j][0][1]<<"\n";
			if(i>2)dp[i][j][0][1]=min(dp[i][j][0][1],dp[i-1][j-1][1][0]+max(0,a[i-1]-(min(a[i],a[i-2])-1))-max(0,a[i-1]-(a[i-2]-1))+max(0,a[i+1]-(a[i]-1)));
//			cout<<dp[i][j][0][1]<<"\n";
		}
		dp[i][j][1][0]=dp[i-1][j][0][1];
//		printf("dp[%d][%d]=%d %d %d\n",i,j,dp[i][j][0][0],dp[i][j][0][1],dp[i][j][1][0]);
	}
	for(int i=1;i<=n+1>>1;i++)cout<<min(min(dp[n][i][0][0],dp[n][i][0][1]),dp[n][i][1][0])<<" ";// 
	return 0;
}
/*1
10
2 2 4 4 3 1 1 2 3 2
*/