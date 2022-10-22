#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cerr << #x << ": " << x << endl

using ll = long long;
using namespace std;

const int N = 5050;

int n, p[N], a[N][N], b[N][N];

void solve() {
	cin >> n;
	rep(i, 1, n) cin >> p[i];
	rep(i, 1, n) {
		rep(j, 1, n)
			a[i][j] = a[i][j - 1] + (p[j] < p[i]);
		b[i][n + 1] = 0;
		per(j, 1, n)
			b[i][j] = b[i][j + 1] + (p[j] < p[i]);
	}
	ll res = 0;
	rep(i, 1, n)
		rep(j, i + 1, n)
			res += b[i][j + 1] * a[j][i - 1];
	cout << res << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}