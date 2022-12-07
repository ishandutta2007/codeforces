#include <bits/stdc++.h>
using namespace std;

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
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector <int> dp(n);
	dp[0] = 1;
	for(int i = 1; i < n; i++) {
		dp[i] = min(dp[i - 1] + 1, v[i]);
	}
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		ans += dp[i];
	}
	cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}