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

const int N = 510, M = 510, mod = 998244353;

int c[M];
ll dp[M][M];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> c[i];
		dp[i][i - 1] = 1;
	}
	dp[m + 1][m] = 1;
	for (int len = 1; len <= m; ++len) {
		for (int l = 1, r = l + len - 1; r <= m; ++l, ++r) {
			int p = l;
			for (int i = l + 1; i <= r; ++i) {
				if (c[i] < c[p]) {
					p = i;
				}
			}
			ll s1 = 0, s2 = 0;
			for (int i = l; i <= p; ++i) {
				s1 += dp[l][i - 1] * dp[i][p - 1];
				s1 %= mod;
			}
			for (int i = p; i <= r; ++i) {
				s2 += dp[p + 1][i] * dp[i + 1][r];
				s2 %= mod;
			}
			dp[l][r] = (s1 * s2) % mod;
		}
	}
	cout << dp[1][n] << endl;
}