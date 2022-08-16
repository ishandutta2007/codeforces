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

const int N = 2e3 + 10, mod = 998244353;

ll dp[N][N];

int main() {
	fast_cin();
	int n, m, k;
	cin >> n >> m >> k;
	dp[1][0] = m;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!dp[i][j]) {
				continue;
			}
			dp[i + 1][j] += dp[i][j];
			dp[i + 1][j] %= mod;
			dp[i + 1][j + 1] += dp[i][j] * (m - 1);
			dp[i + 1][j + 1] %= mod;
		}
	}
	cout << dp[n][k] << endl;
}