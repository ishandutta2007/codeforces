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

const int N = 1e3 + 10, B = 1e5 + 10, mod = 998244353;

int a[N], last[B];
ll dp[N][N];

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	last[B - 1] = n;
	for (int i = B - 2; i >= 0; --i) {
		last[i] = last[i + 1];
		while (a[last[i]] > i) {
			--last[i];
		}
	}
	ll ans = 0;
	int max_b = B / (k - 1);
	for (int b = 1; b <= max_b; ++b) {
		for (int j = 1; j <= n; ++j) {
			dp[1][j] = j;
		}
		for (int i = 2; i <= k; ++i) {
			for (int j = 1; j <= n; ++j) {
				dp[i][j] = dp[i][j - 1];
				if (a[j] >= b) {
					dp[i][j] += dp[i - 1][min(last[a[j] - b], j - 1)];
					dp[i][j] %= mod;
				}
			}
		}
		ans += dp[k][n];
		ans %= mod;
	}
	cout << ans << endl;
}