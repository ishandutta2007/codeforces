//vsp
#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

using ld = long double;
const ld eps = 1e-9;
const int N = 105;
const int M = 10 * N;
const ld inf = 1e18;
int n, a[N], p[N], ord[N];
ld C, T, dp[N][M], power[N];

void solve() {
	rep(i, 0, N)
		rep(j, 0, M)
			dp[i][j] = inf;

	cin >> n >> C >> T;
	rep(i, 0, n) {
		cin >> a[i] >> p[i];
		ord[i] = i;
	}

	sort(ord, ord + n, [&](int x, int y) {
		return a[x] > a[y];
	});

	dp[0][0] = 0;
	FOR(k, n) {
		int i = ord[k];
		per(c, 0, k + 1)
			rep(pro, 0, 10 * k + 1) {
				int npro = pro + p[i];
				dp[c + 1][npro] = min(dp[c + 1][npro], dp[c][pro] + a[i] / power[c]);
			}
	}

	int res = 0;
	rep(cnt, 1, n + 1)
		rep(p, 0, 10 * cnt + 1) {
			ld a = -C;
			ld b = C * (T - 10 * cnt) - 1;
			ld c = T - 10 * cnt - dp[cnt][p];
			ld delta = b * b - 4 * a * c;
			if (delta > -eps) {
				ld x = (-b - sqrt(delta)) / (2 * a);
				if (x > -eps)
					res = max(res, p);
			}
		}
	cout << res << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//that was painful

	power[0] = 0.9;
	rep(i, 1, N)
		power[i] = 0.9 * power[i - 1];

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}