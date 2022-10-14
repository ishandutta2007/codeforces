#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	lli heights[2][n+1];
	for(int i=0;i<n;i++){
		cin>>heights[0][i];
	}
	heights[0][n]=0;
	heights[1][n]=0;
	for(int i=0;i<n;i++){
		cin>>heights[1][i];
	}
	lli dp[2][n+1];
	dp[0][n]=0;
	dp[1][n]=0;
	for(int i=n-1;i>=0;i--){
		dp[0][i]=max(dp[0][i+1],heights[0][i]+dp[1][i+1]);
		dp[1][i]=max(dp[1][i+1],heights[1][i]+dp[0][i+1]);
	}
	printf("%lli\n",max(dp[0][0],dp[1][0]));
	return 0;
}