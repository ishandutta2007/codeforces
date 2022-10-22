#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define cat(x) cout << #x << ": " << x << endl

using ll = long long;
using namespace std;

const int N = 2020;

int a[N][N], b[N];
ll n, c[N][N], d[N][N];

ll work() {
	rep(i, 1, n) b[i] = i;
	rep(i, 1, n) {
		sort(b + 1, b + n + 1, [&](int x, int y) { return a[i][x] < a[i][y]; });
		rep(j, 1, n) c[i][b[j]] = j;
	}
	rep(j, 1, n) {
		sort(b + 1, b + n + 1, [&](int x, int y) { return a[x][j] < a[y][j]; });
		rep(i, 1, n) d[b[i]][j] = i;
	}
	ll res = 0;
	rep(i, 1, n) rep(j, 1, n) res += (c[i][j] - 1) * (d[i][j] - 1);
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	rep(i, 1, n) rep(j, 1, n) cin >> a[i][j];
	ll s = n * (n - 1) / 2 * n * (n - 1) / 2;
	ll w = work();
	cout << 2 * s - w << "\n";
	return 0;
}