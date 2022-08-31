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

const int N = 1e5 + 10, A = 210, M = 200, mod = 998244353;

int a[N];
ll dp[N][A][2];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int j = 0; j <= M; ++j) {
		dp[0][j][1] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (a[i] == -1 or a[i] == j) {
				dp[i][j][0] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1];
				dp[i][j][0] %= mod;
				dp[i][j][1] = dp[i - 1][M][1] - dp[i - 1][j - 1][1];
				dp[i][j][1] += dp[i - 1][j][0] - dp[i - 1][j - 1][0] + 2 * mod;
				dp[i][j][1] %= mod;
			}
			// cout << i << ' ' << j << ' ' << dp[i][j][0] << ' ' << dp[i][j][1] << endl;
			for (int t = 0; t < 2; ++t) {
				dp[i][j][t] += dp[i][j - 1][t];
				dp[i][j][t] %= mod;
			}
		}
	}
	cout << dp[n][M][1] << '\n';
}