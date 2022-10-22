/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=200000;
int n,c;
int a[N+1],b[N+1];
int dp[N+1];
signed main(){
	cin>>n>>c;
	for(int i=1;i<n;i++)cin>>a[i];
	for(int i=1;i<n;i++)cin>>b[i];
	int now=b[1];
	for(int i=2;i<=n;i++)dp[i]=min(dp[i-1]+a[i-1],now+c),now=min(now,dp[i])+b[i];
	for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
	return 0;
}