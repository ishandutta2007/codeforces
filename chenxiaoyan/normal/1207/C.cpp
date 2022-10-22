/*








 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=200000;
int n,a,b;
char s[N+5];
int dp[N+1][2];
void mian(){
	cin>>n>>a>>b>>s+1;
	dp[1][0]=a+2*b;dp[1][1]=2*a+3*b;
	for(int i=2;i<=n;i++)
		if(s[i]=='1')
			dp[i][0]=inf,
			dp[i][1]=dp[i-1][1]+a+2*b;
		else
			dp[i][0]=min(dp[i-1][0]+a+b,dp[i-1][1]+2*a+b),
			dp[i][1]=min(dp[i-1][0]+2*a+2*b,dp[i-1][1]+a+2*b);
	cout<<dp[n][0]<<"\n";
}
signed main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}