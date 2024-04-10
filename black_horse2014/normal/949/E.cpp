#include <bits/stdc++.h>
using namespace std;

const int N = 1<<18;
const int inf = 1e9;

int a[N], b[N], c[N], d[N];
int dp[19][N];
bool pr[19][N];

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = (a[i] % N + N) % N;
	}
	dp[0][0] = 0;
	for (int i = 1; i <= 18; i++) {
		int mod = 1<<i, _mod = 1<<i-1;
		for (int j = 1; j <= n; j++) {
			c[j] = b[j] % mod;
			d[j] = b[j] % _mod;
		}
		int L = _mod, R = -1;
		for (int j = 1; j <= n; j++) if (d[j] != c[j]) L = min(L, d[j]);
		for (int j = 1; j <= n; j++) if (d[j] == c[j]) R = max(R, d[j]);
		for (int s = 0; s < mod; s++) dp[i][s] = inf, pr[i][s] = 1;
		for (int s = 0; s < _mod; s++) {
			if (dp[i-1][s] < inf) {
				for (int j = 0; j < 2; j++) {
					int t = s + (_mod * j);
					if (dp[i-1][s] + 1 < dp[i][t]) {
						dp[i][t] = dp[i-1][s] + 1;
					}
					if (s == 0) {
						if (j == 0 && L == _mod) {
							if (dp[i-1][s] < dp[i][t]) {
								dp[i][t] = dp[i-1][s];
								pr[i][t] = 0;
							}
						}
					} else if (R < s && s <= L) {
						if (j) {
							if (dp[i-1][s] < dp[i][t]) {
								dp[i][t] = dp[i-1][s];
								pr[i][t] = 0;
							}
						}
					}
				}
			}
		}
	}
	int L = 1<<18, R = -1;
	for (int i = 1; i <= n; i++) {
		if (a[i] < 0) L = min(L, b[i]);
		else R = max(R, b[i]);
	}
	int s = -1;
	for (int t = 0; t < 1<<18; t++) {
		if (t == 0 && L != (1<<18)) continue;
		if (t && t > L) continue;
		if (t && t <= R) continue;
		if (s == -1 || dp[18][t] < dp[18][s]) s = t;


	}


	int ret = dp[18][s];
	vector<int> ans;
	for (int i = 18; i > 0; i--) {
		int x = 1<<i-1;
		if (s && s <= x) {
			ans.push_back(-x);
		} else {
			if (pr[i][s]) ans.push_back(x);
		}
		s %= x;
	}
	assert(ans.size() == ret);
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int x : ans) printf("%d ", x);
	puts("");
	return 0;
}