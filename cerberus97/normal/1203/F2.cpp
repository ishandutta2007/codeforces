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

const int N = 1e2 + 10, R = 6e4 + 10, inf = 1e9 + 42;

struct project_t {
	int a, b;
	bool operator<(const project_t &o) const {
		if (b >= 0 and o.b >= 0) {
			return a < o.a;
		} else if (b < 0 and o.b < 0) {
			return a + b > o.a + o.b;
		} else {
			return b >= 0;
		}
	}
};

project_t p[N];
int dp[N][R];

int main() {
	fast_cin();
	int n, r;
	cin >> n >> r;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i].a >> p[i].b;
	}
	sort(p + 1, p + 1 + n);
	for (int j = 0; j < R; ++j) {
		dp[0][j] = -inf;
	}
	dp[0][r] = 0;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < R; ++j) {
			dp[i][j] = dp[i - 1][j];
			if (j - p[i].b >= p[i].a and j - p[i].b < R) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - p[i].b] + 1);
				ans = max(ans, dp[i][j]);
			}
		}
	}
	cout << ans << '\n';
}