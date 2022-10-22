#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << " = " << x << "\n";
using ll = long long;
using namespace std;

const int N = 200200;
const int P = 1e9 + 7;

ll add(ll a, ll b) {
	return (a + b + P) % P;
}

int n, a[N], c[N];
ll L[N], R[N], f[N], dp[N];
pair<int, int> b[N];
vector<int> e[N];

void upd(int x, int d) {
	for (;x <= n; x += x & -x)
		f[x] = add(f[x], d);
}

int sum(int x) {
	int res = 0;
	for (; x > 0; x -= x & -x)
		res = add(res, f[x]);
	return res;
}

void work(int m, bool first) {
	rep(i, 1, m) {
		dp[i] = add((first ? i == 1 : 1), sum(c[i]));
		upd(c[i], dp[i]);
	}
	rep(i, 1, m) upd(c[i], P - dp[i]);
}

void solve() {
	cin >> n;
	rep(i, 1, n) {
		cin >> a[i];
		b[i] = {a[i], -i};
		e[i].clear();
	}
	sort(b + 1, b + n + 1);
	rep(i, 1, n) a[i] = lower_bound(b + 1, b + n + 1, make_pair(a[i], -i)) - b;

	vector<pair<int, int>> suf = {{0, 0}};
	per(i, 1, n)
		if (a[i] > suf.back().first)
			suf.push_back({a[i], i});
	rep(i, 1, n)
		e[lower_bound(suf.begin(), suf.end(), make_pair(a[i], 0))->second].push_back(i);

	rep(i, 1, n) c[i] = a[i];
	work(n, 0);
	rep(i, 1, n) L[i] = dp[i];

	rep(i, 1, n) c[n - i + 1] = n - a[i] + 1;
	work(n, 0);
	rep(i, 1, n) R[i] = dp[n - i + 1];

	ll res = 0;
	rep(i, 1, n) {
		int m = e[i].size();
		rep(j, 0, m - 1) c[m - j] = n - a[e[i][j]] + 1;
		work(e[i].size(), 1);
		rep(j, 0, m - 1) res = add(res, P - L[e[i][j]] * dp[m - j] % P);
	}
	rep(i, 1, n) res = add(res, L[i] * R[i] % P);
	cout << res << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}