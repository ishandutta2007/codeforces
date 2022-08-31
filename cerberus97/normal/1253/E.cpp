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

const int N = 100, M = 1e5 + 10;
const int inf = 1e9 + 42;

vector<pii> intervals;
int dp[N][M];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int x, s;
		cin >> x >> s;
		intervals.pb({x - s, x + s});
	}
	sort(intervals.begin(), intervals.end());
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (dp[i][j] == inf) {
				continue;
			}
			// cout << i << ' ' << j << ' ' << dp[i][j] << endl;
			if (j) {
				smin(dp[i][j + 1], dp[i][j] + 1);
			}
			smin(dp[i + 1][j], dp[i][j]);
			if (i < n) {
				int cost = max(0, intervals[i].first - j - 1);
				int till = min(m, intervals[i].second + cost);
				smin(dp[i + 1][till], dp[i][j] + cost);
			}
		}
	}
	cout << dp[n][m] << '\n';
}