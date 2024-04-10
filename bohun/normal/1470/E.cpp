#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;

const int N = 1 << 17;

int n, c, q, p[N];
ll dp[N][5], L[N][5];
vector<int> per[N][5];

void solve() {
	scanf("%d%d%d", &n, &c, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d", p + i);
	fill(dp[n + 1], dp[n + 1] + c + 1, 1);
	for (int i = n; i >= 1; --i)
		for (int j = 0; j <= c; ++j) {
			dp[i][j] = 0;
			for (int k = 0; k <= j && i + k <= n; ++k)
				dp[i][j] = dp[i][j] + dp[i + k + 1][j - k];
		}
	for (int i = 1; i <= n + 1; ++i) fill(L[i], L[i] + c + 1, 0);
	for (int i = n; i >= 1; --i) 
		for (int j = 0; j <= c; ++j) {
			vector<int> &P = per[i][j];
			P.resize(min(j, n - i) + 1);
			iota(P.begin(), P.end(), 0);
			sort(P.begin(), P.end(), [&](int a, int b) {
				return p[i + a] < p[i + b];
			});
			for (int k = 0; k < P.size(); ++k) {
				if (P[k] == 0) {
					L[i][j] += L[i + 1][j];
					break;
				}
				L[i][j] += dp[i + P[k] + 1][j - P[k]];
			}
			assert(L[i][j] >= 0);
		}
	while (q--) {
		int pos; ll k;
		scanf("%d%lld", &pos, &k);
		if (k > dp[1][c]) {
			printf("-1\n");
			continue;
		}
		int v = 1, cc = c;
		while (true) {
			for (int i = __lg(n); i >= 0; --i) {
				int u = v + (1 << i);
				if (u > n + 1) continue;
				ll cnt = L[v][cc] - L[u][cc];
				if (cnt >= k || cnt + dp[u][cc] < k) continue;
				k -= cnt;
				v = u;
			}
			if (pos < v) {
				printf("%d\n", p[pos]);
				break;
			}
			bool done = false;
			for (auto j : per[v][cc]) {
				if (dp[v + j + 1][cc - j] < k) {
					k -= dp[v + j + 1][cc - j];
					continue;
				}
				if (v <= pos && pos <= v + j) {
					done = true;
					printf("%d\n", p[v + j - (pos - v)]);
				}
				cc -= j;
				v += j + 1;
				break;
			}
			if (done) break;
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)		
		solve();
	return 0;
}