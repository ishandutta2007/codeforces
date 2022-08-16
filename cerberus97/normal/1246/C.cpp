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

const int N = 2e3 + 10, mod = 1e9 + 7;
const int inf = 1e9 + 42;

char a[N][N];
int back[N][N][2], rocks[N][N][2];
ll dp[N][N][2], dp_sum[N][N][2];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	if (n == 1 and m == 1) {
		cout << 1 << endl;
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> (a[i] + 1);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = m; j >= 1; --j) {
			back[i][j][0] = inf;
			rocks[i][j][0] = rocks[i][j + 1][0] + (a[i][j] == 'R');
			int reach = m - rocks[i][j + 1][0];
			back[i][reach][0] = min(back[i][reach][0], j);
		}
		for (int j = m - 1; j >= 1; --j) {
			back[i][j][0] = min(back[i][j][0], back[i][j + 1][0]);
		}
	}
	for (int j = 1; j <= m; ++j) {
		for (int i = n; i >= 1; --i) {
			back[i][j][1] = inf;
			rocks[i][j][1] = rocks[i + 1][j][1] + (a[i][j] == 'R');
			int reach = n - rocks[i + 1][j][1];
			back[reach][j][1] = min(back[reach][j][1], i);
		}
		for (int i = n - 1; i >= 1; --i) {
			back[i][j][1] = min(back[i][j][1], back[i + 1][j][1]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i == 1 and j == 1) {
				dp[i][j][0] = dp[i][j][1] = 1;
			}
			if (j > 1) {
				int b = back[i][j][0];
				dp[i][j][0] = dp_sum[i][j - 1][1] - dp_sum[i][b - 1][1] + mod;
				dp[i][j][0] %= mod;
			}
			if (i > 1) {
				int b = back[i][j][1];
				dp[i][j][1] = dp_sum[i - 1][j][0] - dp_sum[b - 1][j][0] + mod;
				dp[i][j][1] %= mod;
			}
			dp_sum[i][j][0] = (dp_sum[i - 1][j][0] + dp[i][j][0]) % mod;
			dp_sum[i][j][1] = (dp_sum[i][j - 1][1] + dp[i][j][1]) % mod;
		}
	}
	cout << (dp[n][m][0] + dp[n][m][1]) % mod << endl;
}