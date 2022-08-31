#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

const ll INF = 1e18;

ll n,s,e,x[5001],a[5001],b[5001],c[5001],d[5001];
ll dp[5001][5001], ans = INF;

void init() {
	F0R(i,5001) F0R(j,5001) dp[i][j] = INF;	
	cin >> n >> s >> e;
	FOR(i,1,n+1) cin >> x[i];
	FOR(i,1,n+1) cin >> a[i];
	FOR(i,1,n+1) cin >> b[i];
	FOR(i,1,n+1) cin >> c[i];
	FOR(i,1,n+1) cin >> d[i];
}

ll solve() {
	F0R(i,5001) F0R(j,5001) dp[i][j] = INF;
	dp[0][0] = 0;
	FOR(i,1,n+1) F0R(j,5001) {
		if (i != n && j == 0) continue;
		if (i == s) { 
			dp[i][j] = min(dp[i][j],dp[i-1][j+1]+x[i]+c[i]);
			dp[i][j] = min(dp[i][j],dp[i-1][j-1]-x[i]+d[i]);
		} else if (i == e) {
			dp[i][j] = min(dp[i][j],dp[i-1][j-1]+b[i]-x[i]);
			dp[i][j] = min(dp[i][j],dp[i-1][j+1]+a[i]+x[i]);
		} else {
			if (j >= 2) dp[i][j] = min(dp[i][j],dp[i-1][j-2]+b[i]+d[i]-2*x[i]);
			if (j > 1 || s<e) dp[i][j] = min(dp[i][j], dp[i-1][j]+a[i]+d[i]); // going right // fix
			if (j > 1 || s>e) dp[i][j] = min(dp[i][j], dp[i-1][j]+c[i]+b[i]); // going left // fix
			if (j+2 <= 5000) dp[i][j] = min(dp[i][j],dp[i-1][j+2]+a[i]+c[i]+2*x[i]);
		}
		// if (dp[i][j] < INF) cout << i << " " << j << " " << dp[i][j] << "\n";
	}
	return dp[n][0];
}

int main() {
	init();
	ans = min(ans,solve());
	cout << ans;
}