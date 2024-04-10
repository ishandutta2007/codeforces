#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(ll i=0; i<a; i++)
#define pll pair<ll,ll>
 
using namespace std;

const ll mod=1e9+7;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n,c;
	cin >> n >> c;
	int a[n-1],b[n-1];
	loop(n-1) cin >> a[i];
	loop(n-1) cin >> b[i];
	ll dp[n][2];
	dp[0][0]=dp[0][1]=0;
	loop(n-1){
		dp[i+1][0]=min(dp[i][0],dp[i][1])+a[i];
		if(i>0) dp[i+1][1]=min(dp[i][0]+c,dp[i][1])+b[i];
		else dp[i+1][1]=min(dp[i][0],dp[i][1])+b[i]+c;
	}
	loop(n) cout << min(dp[i][0],dp[i][1]) << " ";
	cout << "\n";
	return 0;
}