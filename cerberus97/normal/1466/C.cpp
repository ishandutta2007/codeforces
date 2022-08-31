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

#define smin(a, b) a = min(a, b)

const int N = 1e5 + 10, inf = 1e9 + 42;

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = s.length();
		vector<vector<int>> dp(n + 1, vector<int>(4, inf));
		dp[0][3] = 0;
		for (int i = 0; i < n; ++i) {
			for (int m = 0; m < 4; ++m) {
				if (dp[i][m] == inf) {
					continue;
				}
				smin(dp[i + 1][((m << 1) | 1) & 3], dp[i][m] + 1);
				if (((m & 1) or s[i] != s[i - 1]) and ((m & 2) or s[i] != s[i - 2])) {
					smin(dp[i + 1][((m << 1) & 3)], dp[i][m]);
				}
			}
		}
		int ans = inf;
		for (int m = 0; m < 4; ++m) {
			smin(ans, dp[n][m]);
		}
		cout << ans << '\n';
	}
}