//vsp
#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

const ll inf = 1e18;
template<class T>
struct qq_segment_tree {
	int n;
	vector<T> mn, tag;
	qq_segment_tree(int n) : n(n) {
		mn.resize(4 * n, inf);
		tag.resize(4 * n, 0);
	}
	void range_add(int u, int l, int r, int x, int y, T z) {
		if (y < l || r < x) 
			return;
		if (x <= l && r <= y) {
			tag[u] += z;
			mn[u] += z;
			return;
		}
		int m = (l + r) / 2;
		range_add(2 * u, l, m, x, y, z);
		range_add(2 * u + 1, m + 1, r, x, y, z);
		mn[u] = min(mn[2 * u], mn[2 * u + 1]) + tag[u];
	}
	void range_add(int x, int y, T z) {
		range_add(1, 0, n - 1, x, y, z);
	}
};

int n, k, a[35001];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> k;
	rep(i, 1, n + 1)
		cin >> a[i];

	vector<ll> dp(n + 1, inf);
	dp[0] = 0;

	while (k--) {
		qq_segment_tree<ll> T(n + 1);
		vector<ll> ndp(n + 1, inf);
		vector<int> last(n + 1, 0);

		rep(i, 1, n + 1) {
			T.range_add(i, i, dp[i - 1] - inf);
			if (last[a[i]] > 0) 
				T.range_add(1, last[a[i]], i - last[a[i]]);
			last[a[i]] = i;
			ndp[i] = T.mn[1];
		}

		dp = ndp;
	}
	cout << dp[n] << '\n';
	return 0;
}