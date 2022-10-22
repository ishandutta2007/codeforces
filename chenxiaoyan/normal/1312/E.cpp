/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n;
int a[N+1];
int dp[N+1][N+1],dp0[N+1][N+1];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i;i--)for(int j=i;j<=n;j++){
		if(i==j){dp[i][j]=a[i];continue;}
		for(int k=i;k<j;k++)if(dp[i][k]&&dp[i][k]==dp[k+1][j])dp[i][j]=dp[i][k]+1;
	}
	for(int i=n;i;i--)for(int j=i;j<=n;j++){
		if(dp[i][j]){dp0[i][j]=1;continue;}
		dp0[i][j]=j-i+1;
		for(int k=i;k<j;k++)dp0[i][j]=min(dp0[i][j],dp0[i][k]+dp0[k+1][j]);
	}
	cout<<dp0[1][n];
	return 0;
}