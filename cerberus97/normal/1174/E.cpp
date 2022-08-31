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

const int N = 1e6 + 10, LOG = 21, mod = 1e9 + 7;

int dp[N][LOG][2];

int main() {
	fast_cin();
	int n; cin >> n;
	int x = 0, p = 1;
	while (2 * p <= n) {
		p *= 2;
		++x;
	}
	dp[1][x][0] = 1;
	if ((p * 3) / 2 <= n) {
		dp[1][x - 1][1] = 1;
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < LOG; ++j) {
			for (int k = 0; k < 2; ++k) {
				if (!dp[i][j][k]) {
					continue;
				}
				ll cur = dp[i][j][k];
				int num = (1 << j) * (k ? 3 : 1);
				ll mul = n / num - i;
				dp[i + 1][j][k] += (cur * mul) % mod;
				dp[i + 1][j][k] %= mod;
				if (j) {
					ll temp = (n / (num / 2)) - (n / num);
					dp[i + 1][j - 1][k] += (cur * temp) % mod;
					dp[i + 1][j - 1][k] %= mod;
				}
				if (k) {
					ll temp = (n / (num / 3)) - (n / num);
					dp[i + 1][j][k - 1] += (cur * temp) % mod;
					dp[i + 1][j][k - 1] %= mod;
				}
			}
		}
	}
	cout << dp[n][0][0] << '\n';
}