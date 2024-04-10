#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, b, a) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << " = " << x << "\n";
using ll = long long;
using namespace std;

const int N = 1 << 17;

int n, m, cnt[N], a[N];
ll s[N], f[2 * N], g[2 * N];
vector<int> e[N];

void add(int u, int x, int y, int d, int l, int r) {
	if (x <= l && r <= y) {
		f[u] += d;
		g[u] += d;
		return;
	}
	if (l > y || x > r) return;
	int m = (l + r) / 2;
	add(2 * u, x, y, d, l, m);
	add(2 * u + 1, x, y, d, m + 1, r);
	f[u] = min(f[2 * u], f[2 * u + 1]) + g[u];
}

void add(int x, int d) {
	add(1, 0, x, d, 0, N - 1);
}

void solve() {
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, m) {
		s[i] = 0;
		e[i].clear();
	}
	rep(i, 1, m) {
		cin >> cnt[i];
		rep(j, 1, cnt[i]) {
			int x;
			cin >> x;
			s[i] += x;
			e[i].push_back(x);
		}
	}

	sort(a + 1, a + n + 1, greater<int>());
	rep(i, 1, m) add(a[i], 1);
	auto cdiv = [](ll a, int b) {
		return (a + b - 1) / b;
	};
	rep(i, 1, m) add(cdiv(s[i], cnt[i]), -1);
	rep(i, 1, m) {
		add(cdiv(s[i], cnt[i]), 1);
		for (auto x : e[i]) {
			add(cdiv(s[i] - x, cnt[i] - 1), -1);
			cout << (f[1] >= 0 ? 1 : 0);
			add(cdiv(s[i] - x, cnt[i] - 1), 1);
		}
		add(cdiv(s[i], cnt[i]), -1);
	}
	cout << endl;
	rep(i, 1, m) add(a[i], -1);
	rep(i, 1, m) add(cdiv(s[i], cnt[i]), 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}