#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << ": " << x << endl

using ll = long long;
using namespace std;

const int N = 1 << 20;

struct Tree {
	ll t[2 * N];
	Tree() {
		rep(i, 1, 2 * N - 1) t[i] = -1e18;
	}
	void update(int u, ll y) {
		for (u += N; u > 0; u /= 2) {
			t[u] = max(t[u], y);
		}
	}
	ll query(int l, int r) {
		ll res = -1e18;
		for (l += N, r += N + 1; l < r; l /= 2, r /= 2) {
			if (l & 1) res = max(res, t[l++]);
			if (r & 1) res = max(res, t[--r]);
		}
		return res;
	}
	void clear(int u = 1) {
		if (u >= 2 * N || t[u] == -1e18) {
			return;
		}
		t[u] = -1e18;
		clear(2 * u);
		clear(2 * u + 1);
	}
} T[3];

int n;
ll a[N], b[N], dp[N];

void add(int i) {
	int id = lower_bound(b, b + n + 1, a[i]) - b;
	T[0].update(id, dp[i] + i);
	T[1].update(id, dp[i]);
	T[2].update(id, dp[i] - i);
}

void solve() {
	cin >> n;
	b[0] = 0;
	rep(i, 1, n) {
		cin >> a[i];
		a[i] += a[i - 1];
		b[i] = a[i];
	}
	sort(b, b + n + 1);
	add(0);

	rep(i, 1, n) {
		ll &res = dp[i];
		res = -1e18;
		int id = lower_bound(b, b + n + 1, a[i]) - b;
		res = max(res, T[0].query(id + 1, N - 1) - i);
		res = max(res, T[1].query(id, id));
		res = max(res, T[2].query(0, id - 1) + i);
		add(i);
	}

	cout << dp[n] << endl;

	rep(i, 0, 2) {
		T[i].clear();
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T = 1;
	cin >> T;
	while (T--) solve();

	return 0;
}