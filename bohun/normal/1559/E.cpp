#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

const int P = 998244353;
const int N = 200200;

int n, m, l[N], r[N], dp[N], a[N], b[N];
int f[55][N];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;
	rep(i, 1, n + 1) cin >> l[i] >> r[i];
	fill(f[0], f[0] + N, 1);
	per(i, 1, m) {
		int M = m / i;
		rep(j, 1, n + 1) {
			a[j] = (l[j] + i - 1) / i;
			b[j] = r[j] / i;
			M -= a[j];
			b[j] -= a[j];
		}
		if (M < 0)
			continue;
		rep(id, 1, n + 1) {
			rep(j, 0, M + 1) {
				int x = j - b[id];
				f[id][j] = (f[id - 1][j] - (x > 0 ? f[id - 1][x - 1] : 0) + P) % P;
				if (j > 0)
					f[id][j] = (f[id][j] + f[id][j - 1]) % P;
			}
		}
		dp[i] = f[n][M];
		rep(j, 2, m / i + 1)
			dp[i] = (dp[i] - dp[i * j] + P) % P;
	}
	cout << dp[1] << "\n";
	return 0;
}