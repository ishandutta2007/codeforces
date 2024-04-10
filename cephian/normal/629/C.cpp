#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;


const int N = 3005;
// len, offset
ll dp[N][N] = {};
const ll mod = 1e9+7;


int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m;
	string s;

	cin >> n >> m;
	cin >> s;

	int mn = 0, tot = 0;
	for(char c : s) {
		if(c == '(') ++tot;
		else --tot;
		mn = min(mn, tot);
	}

	dp[0][0] = 1;
	for(int i = 1; i < N; ++i) {
		for(int j = 0; j <= i; ++j) {
			if(j-1 >= 0) {
				dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
			}
			if(j+1 <= i-1) {
				dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % mod;
			}
		}
	}


	ll ans = 0;
	for(int l1 = 0; l1 <= n-m; ++l1) {
		const int l2 = n-m-l1;
		for(int o1 = -mn; o1 <= l1; ++o1) {
			const int o2 = o1 + tot;
			if(o2 > l2) break;
			ans = (ans + dp[l1][o1] * dp[l2][o2]) % mod;
		}
	}
	cout << ans << '\n';
}