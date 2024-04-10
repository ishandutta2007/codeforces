/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=200000;
int n,m;
int a[N+3];
int dp[N+1][4];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dp[0][0]=dp[0][1]=dp[0][3]=1;
	for(int i=1;i<=n;i++){
		dp[i][0]=1ll*m*dp[i-1][1]%mod;
		dp[i][1]=(1ll*(m-1)*dp[i-1][3]%mod+dp[i-1][2])%mod;
		dp[i][2]=1ll*(m-1)*dp[i-1][3]%mod;
		dp[i][3]=(1ll*(m-2)*dp[i-1][3]%mod+dp[i-1][2])%mod;
	}
	int ans=1;
	int las=0,now=0;
	for(int i=1;i<=n+2;i+=2)
		if(~a[i])ans=1ll*ans*dp[now][!las&&!a[i]?0:!las&&a[i]||las&&!a[i]?1:las==a[i]?2:3]%mod,las=a[i],now=0;
		else now++;
	for(int i=2;i<=n+2;i+=2)
		if(~a[i])ans=1ll*ans*dp[now][!las&&!a[i]?0:!las&&a[i]||las&&!a[i]?1:las==a[i]?2:3]%mod,las=a[i],now=0;
		else now++;
	cout<<ans<<"\n";
	return 0;
}
/*1
2 3
-1 -1
*/
/*2
5 2
1 -1 -1 1 2
*/
/*3
5 3
1 -1 -1 1 2
*/
/*4
4 200000
-1 -1 12345 -1
*/