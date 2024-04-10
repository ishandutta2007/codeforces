#include<bits/stdc++.h>
using namespace std;
int dp[3][103],n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		dp[0][i]=min(dp[0][i-1],min(dp[1][i-1],dp[2][i-1]))+1;
		if(a&1)dp[1][i]=min(dp[0][i-1],dp[2][i-1]);else dp[1][i]=1000003;
		if(a&2)dp[2][i]=min(dp[0][i-1],dp[1][i-1]);else dp[2][i]=1000003;
	}
	cout<<min(dp[0][n],min(dp[1][n],dp[2][n]));
}