#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, a, b) for(int i = a; i < (b); i++)
#define all(x) x.begin(), x..end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
const int N = 200100;
const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	int O = 0;
	int E = 0;
	rep(i, 0, n) {
		int x; cin >> x;
		if(x % 2) O++;
		else E++;
	}
	bool dp[O + 1][E + 1][2][2];
	memset(dp, false, sizeof(dp));
	// (odd left)(even left)(sum of alice's numbers)(whose move it is)
	dp[0][0][0][0] = dp[0][0][1][1] = true;
	dp[0][0][1][0] = dp[0][0][0][1] = false;
	for(int i = 0; i <= O; i++) {
		for(int j = 0; j <= E; j++) {
			if(i > 0) {
				// for(int k = 0; k < 2; k++) {
				// 	for(int l = 0; l < 2; l++) {
				// 		if(dp[i - 1][j][k][l] == false) dp[i][j][k^1][l^1] = true;
				// 	}
				// }
				if(dp[i - 1][j][1][1] == false) dp[i][j][0][0] = true;
				if(dp[i - 1][j][0][1] == false) dp[i][j][1][0] = true;
				if(dp[i - 1][j][0][0] == false) dp[i][j][0][1] = true;
				if(dp[i - 1][j][1][0] == false) dp[i][j][1][1] = true;
			}
			if(j > 0) {
				// for(int k = 0; k < 2; k++) {
				// 	for(int l = 0; l < 2; l++) {
				// 		if(dp[i][j - 1][k][l] == false) dp[i][j][k][l^1] = true;
				// 	}
				// }
				if(dp[i][j - 1][0][1] == false) dp[i][j][0][0] = true;
				if(dp[i][j - 1][1][1] == false) dp[i][j][1][0] = true;
				if(dp[i][j - 1][0][0] == false) dp[i][j][0][1] = true;
				if(dp[i][j - 1][1][0] == false) dp[i][j][1][1] = true;
			}
		}
	}
	// for(int i = 0; i <= O; i++) {
	// 	for(int j = 0; j <= E; j++) {
	// 		for(int k = 0; k < 2; k++) {
	// 			for(int l = 0; l < 2; l++) {
	// 				cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << dp[i][j][k][l] << '\n';
	// 			}
	// 		}
	// 	}
	// }
	cout << (dp[O][E][0][0] ? "Alice" : "Bob") << '\n';
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> t;
	while(t--) {
		solve();
	}
}