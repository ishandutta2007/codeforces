/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
const int N=100000;
int dp[N+1][2];
int main(){
	int n,m;
	cin>>n>>m;//
	dp[1][1]=2;
	for(int i=2;i<=100000;i++)dp[i][0]=dp[i-1][1],dp[i][1]=(dp[i-1][0]+dp[i-1][1])%mod;
	cout<<(((dp[n][0]+dp[n][1])%mod+(dp[m][0]+dp[m][1])%mod)%mod-2+mod)%mod;
	return 0;
}