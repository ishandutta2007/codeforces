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
#define smin(a, b) a = min(a, b)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e2 + 10, inf = 1e5 + 42;

int p[N], blanks[N], dp[N][N][2];

int main() {
	fast_cin();
	int n; cin >> n;
	vector<int> have(2);
	have[0] = n / 2;
	have[1] = (n + 1) / 2;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		if (p[i]) {
			--have[p[i] % 2];
		}
		blanks[i] = blanks[i - 1] + (p[i] == 0);
	}
	for (int i = 0; i <= n; ++i) {
		for (int odd = 0; odd <= n; ++odd) {
			for (int last = 0; last < 2; ++last) {
				dp[i][odd][last] = inf;
			}
		}
	}
	dp[0][0][0] = dp[0][0][1] = 0;
	for (int i = 0; i < n; ++i) {
		for (int odd = 0; odd <= n; ++odd) {
			for (int last = 0; last < 2; ++last) {
				if (dp[i][odd][last] == inf) {
					continue;
				}
				int even = blanks[i] - odd;
				if (p[i + 1] != 0) {
					smin(dp[i + 1][odd][p[i + 1] % 2], dp[i][odd][last] + (last != (p[i + 1] % 2)));
				} else {
					if (odd < have[1]) {
						smin(dp[i + 1][odd + 1][1], dp[i][odd][last] + (last != 1));
					}
					if (even < have[0]) {
						smin(dp[i + 1][odd][0], dp[i][odd][last] + (last != 0));
					}
				}
			}
		}
	}
	int ans = n;
	for (int odd = 0; odd <= n; ++odd) {
		for (int last = 0; last < 2; ++last) {
			smin(ans, dp[n][odd][last]);
		}
	}
	cout << ans << '\n';
}