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

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 100 + 10;
const ld inf = 1e20, eps = 1e-9;

struct prob {
	int a, v;
	bool operator<(const prob &o) {
		return a > o.a;
	}
};

prob p[N];
ld dp[N][N][10 * N], pw_c[N];

int main() {
	fast_cin();
	int tc; cin >> tc;
	while (tc--) {
		int n; ld C, T;
		cin >> n >> C >> T;
		for (int i = 1; i <= n; ++i) {
			cin >> p[i].a >> p[i].v;
		}
		sort(p + 1, p + 1 + n);
		ld c = 1;
		for (int i = 0; i <= n; ++i) {
			pw_c[i] = c;
			c *= 10;
			c /= 9.0;
		}
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= n; ++j) {
				for (int k = 0; k <= 10 * n; ++k) {
					dp[i][j][k] = inf;
				}
			}
		}
		dp[0][0][0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= n; ++j) {
				for (int k = 0; k <= 10 * n; ++k) {
					if (k < p[i].v or j < 1) {
						dp[i][j][k] = dp[i - 1][j][k];
						continue;
					}
					dp[i][j][k] = min(dp[i - 1][j][k], dp[i - 1][j - 1][k - p[i].v] + p[i].a * pw_c[j]);
				}
			}
		}
		int lo = 1, hi = 10 * n;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			bool done = false;
			for (int j = 1; j <= n; ++j) {
				ld cost = inf;
				for (int k = mid; k <= 10 * n; ++k) {
					cost = min(cost, dp[n][j][k]);
				}
				ld T_temp = T - 10 * j;
				if (cost <= T_temp) {
					done = true;
					break;
				}
				if (C > 0) {
					ld t = (T_temp * C - 1) / (2 * C);
					if (t >= 0) {
						if (C * t * t + t - T_temp * C * t + cost - T_temp <= 0) {
							done = true;
							break;
						}
					}
				}
			}
			if (done) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		cout << lo - 1 << '\n';
	}
}