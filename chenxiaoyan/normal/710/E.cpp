/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10000000;
int n,a,b;
int dp[N+1];
signed main(){
	cin>>n>>a>>b;
	dp[0]=0;
	for(int i=1;i<=n;i++)
		if(i&1)dp[i]=min(dp[i-1]+a,dp[i+1>>1]+a+b);
		else dp[i]=min(dp[i-1]+a,dp[i>>1]+b);
	cout<<dp[n];
	return 0;
}