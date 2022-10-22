#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl

using namespace std;
using ll = long long;

const int N = 555;
const ll INF = 1e18;

int n, m;
ll d[N][N];

void solve() {
	cin >> n >> m;
	rep(i, 1, n) rep(j, 1, n) d[i][j] = INF;
	rep(i, 1, n) d[i][i] = 0;

	vector<tuple<int, int, int>> ed;
	rep(i, 1, m) {
		int a, b; ll c;
		cin >> a >> b >> c;
		d[a][b] = 1;
		d[b][a] = 1;
		ed.push_back({a, b, c});
		ed.push_back({b, a, c});
	}

	rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) {
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	}

	ll res = INF;
	for (auto [a, b, c] : ed) {
		res = min(res, c * (1 + d[1][a] + d[b][n]));
		rep(k, 1, n) {
			res = min(res, c * (1 + d[1][k] + d[k][a] + d[k][n] + 1));
		}
	}

	cout << res << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T = 1;
	cin >> T;
	while (T--) solve();

	return 0;
}