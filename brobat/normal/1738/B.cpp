#include <bits/stdc++.h>
using namespace std;

#define int long long
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
	int n, k;
	cin >> n >> k;
	vi v(k);
	rep(i, 0, k) cin >> v[i];
	if(k == 1) {
		cout << "Yes" << '\n';
		return;
	}
	reverse(v.begin(), v.end());
	vi ans(n);
	rep(i, 0, k - 1) {
		ans[n - i - 1] = v[i] - v[i + 1];
	}
	if((n - k + 1)*(ans[n - k + 1]) < v.back()) {
		cout << "No" << '\n';
		return;
	}
	for(int i = n - k + 2; i < n; i++) {
		if(ans[i] < ans[i - 1]) {
			cout << "No" << '\n';
			return;
		}
	}
	cout << "Yes" << '\n';
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