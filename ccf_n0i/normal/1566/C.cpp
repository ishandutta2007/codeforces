#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define rep0(i,n) for ((i)=0;(i)<(n);(i)++)
using namespace std;
const int v[4]={0,1,0,2};
string s,t;
int i,j,n,dp[100005][4];
void solve(){
	int ans=0;
	cin>>n>>s>>t;
	rep0(i,n+1) memset(dp[i],-0x3f,sizeof(dp[i]));
	dp[0][0]=0;
	rep0(i,n){
		int c=(1<<(s[i]-'0'))|(1<<(t[i]-'0'));
		rep0(j,4) dp[i][0]=max(dp[i][0],dp[i][j]+v[j]);
		rep0(j,4){
			dp[i+1][j|c]=max(dp[i+1][j|c],dp[i][j]); 
		}
	}
	rep0(j,4) ans=max(ans,dp[n][j]+v[j]);
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}