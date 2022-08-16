/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e3 + 10, LOG = log2(N) + 2, inf = 1e9 + 42;

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	vector<int> l(n), s(n), c(n + m + 1, 0);
	for (auto& i : l) {
		cin >> i;
	}
	for (auto& i : s) {
		cin >> i;
	}
	for (int i = 1; i <= n + m; ++i) {
		cin >> c[i];
		c[i] += c[i - 1];
	}
	vector<vector<int>> prv(n + 1, vector<int>(m + 1, -1));
	vector<int> ctz(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		prv[i] = prv[i - 1];
		prv[i][l[i - 1]] = i - 1;
		ctz[i] = __builtin_ctz(i);
	}
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, -inf));
	l.pb(1);
	dp[n][0] = 0;
	int ans = 0;
	for (int i = n; i > 0; --i) {
		int mx = -inf;
		for (int j = 0; j <= n; ++j) {
			if (dp[i][j] == -inf) {
				continue;
			}
			mx = max(mx, dp[i][j]);
			for (int v = l[i]; v <= min(m, l[i] + LOG - 1); ++v) {
				int ni = prv[i][v];
				if (ni == -1) {
					continue;
				}
				int nj = (j >> (v - l[i]));
				dp[ni][nj] = max(dp[ni][nj], dp[i][j]);
				int nrank = ctz[nj + 1] + v;
				int gain = c[nrank] - c[v - 1] - s[ni];
				dp[ni][nj + 1] = max(dp[ni][nj + 1], dp[i][j] + gain);
			}
		}
		ans = max(ans, mx);
		for (int v = l[i] + LOG; v <= m; ++v) {
			int ni = prv[i][v];
			if (ni == -1) {
				continue;
			}
			dp[ni][0] = max(dp[ni][0], mx);
			dp[ni][1] = max(dp[ni][1], mx + c[v] - c[v - 1] - s[ni]);
		}
	}
	for (int j = 0; j <= n; ++j) {
		ans = max(ans, dp[0][j]);
	}
	cout << ans << endl;
}