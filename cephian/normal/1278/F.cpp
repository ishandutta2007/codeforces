#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

const int M = 998244353;
const int K = 5005;
// [i, j] --> using first i pos, exactly j so far
ll dp[K][K] = {};

ll pw(ll a, ll b) {
	if(b == 0) return 1;
	if(b&1) return a * pw(a, b-1) % M;
	ll t = pw(a, b/2);
	return t * t % M;
}

ll inv(ll a) {
	return pw(a, M-2);
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	dp[0][0] = 1;
	for(int i = 1; i < K ; ++i) {
		for(int j = 1; j < K ; ++j) {
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]*j) % M;
		}
	}
	int n, m, k;
	cin >> n >> m >> k;
	ll nPr = 1;

	ll ans = 0;
	for(int r = 1; r <= k; ++r) {
		nPr = nPr * (n-r+1) % M;
		ll cont = 1;
		cont = cont * nPr % M;
		cont = cont * dp[k][r] % M;
		cont = cont * pw(inv(m), r);
		ans = (ans + cont) % M;
	}
	cout << ans << endl;
}