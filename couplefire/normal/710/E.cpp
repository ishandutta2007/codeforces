#include <bits/stdc++.h>
using namespace std;
long long n,x,y,i,dp[10000007];

int main(){
	cin>>n>>x>>y;
	for(dp[1]=x,i=2;i<=n;i++)dp[i]=min(dp[i-1]+x,dp[(i+1)/2]+y+(i%2)*x);
	cout<<dp[n];
	return 0;
}