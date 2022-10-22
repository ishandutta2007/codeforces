/*








*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=100000;
int n;
int a[N+1];
int dp[N+1][2];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dp[0][1]=inf;
	for(int i=1;i<=n;i++)for(int j=0;j<=1;j++)
		dp[i][j]=min(dp[i-1][j]+abs(a[i]-1),dp[i-1][!j]+abs(a[i]+1));
	cout<<dp[n][0];
	return 0;
}