#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, b, a) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << " = " << x << "\n";
using ll = long long;
using namespace std;

const int N = 600;

int n, a[N][N];

void solve() {
	cin >> n;
	rep(i, 1, 2 * n)
		rep(j, 1, 2 * n)
			cin >> a[i][j];
	ll res = 0;
	rep(i, n + 1, 2 * n)
		rep(j, n + 1, 2 * n)
			res += a[i][j];
	cout << res + min({a[1][n + 1], a[1][2 * n], a[n][n + 1], a[n][2 * n], a[n + 1][1], a[n + 1][n], a[2 * n][1], a[2 * n][n]}) << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}