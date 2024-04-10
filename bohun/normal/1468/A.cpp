#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

const int N = 500500;

int n, f[N], dp[N], a[N];

void upd(int x, int y) {
	for (x++; x < N; x += x & -x)
		f[x] = max(f[x], y);
}

int qry(int x) {
	int res = 0;
	for (x++; x > 0; x -= x & -x)
		res = max(res, f[x]);
	return res;
}

void solve() {
	cin >> n;

	rep(i, 0, n + 2)
		f[i] = 0;

	vector<pair<int, int>> v;
	v.emplace_back(0, 0);
	dp[0] = 0;

	rep(i, 1, n + 1) {
		cin >> a[i];
		dp[i] = 1 + qry(a[i]);
		while (!v.empty() && v.back().first <= a[i]) {
			int id = v.back().second;
			upd(a[id], ++dp[id]);
			v.pop_back();
		}
		upd(a[i], dp[i]);
		v.emplace_back(a[i], i);
	}

	cout << *max_element(dp, dp + n + 1) << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}