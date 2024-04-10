#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
 
using ll = long long;
using namespace std;

const int N = 1 << 20;

struct TreeMax {
	int t[2 * N];
	void set(int x, int val) {
		x += N;
		t[x] = val;
		for (x /= 2; x; x /= 2)
			t[x] = max(t[2 * x], t[2 * x + 1]);
	}
	int query(int l, int r) {
		int ans = -1e9;
		for (l += N, r += N + 1; l < r; l /= 2, r /= 2) {
			if (l & 1) ans = max(ans, t[l++]);
			if (r & 1) ans = max(ans, t[--r]);
		}
		return ans;
	}
} T;

int n, p[N];
pair<int, int> dp[N];
char ans[N];

void solve() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", p + i), T.set(i, i + p[i]);
	set<pair<int, int>> s;
	s.insert({0, 0});
	rep(i, 1, n) {
		dp[i] = {-1e9, 0};
		if (dp[i - 1].fi > i - 1)
			dp[i] = {max(dp[i - 1].fi, i + p[i]), -1};
		auto it = s.lower_bound({i - p[i] - 1, 0});
		if (it != s.end()) {
			int x = it->se;
			int y = max(i - 1, T.query(x + 1, i - 1));
			dp[i] = max(dp[i], {y, x});
		}
		if (s.rbegin()->fi < dp[i].fi)
			s.insert({dp[i].fi, i});
	}
	if (dp[n].fi < n) return printf("NO\n"), void(0);
	printf("YES\n");
	int m = n;
	while (m > 0) {
		if (dp[m].se == -1) {
			ans[m--] = 'R';
			continue;
		}
		ans[m] = 'L';
		rep(i, dp[m].se + 1, m - 1)
			ans[i] = 'R';
		m = dp[m].se;
	}
	rep(i, 1, n) printf("%c", ans[i]);
	puts("");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}