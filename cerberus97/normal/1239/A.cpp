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

const int N = 1e5 + 10, mod = 1e9 + 7;

ll dp[N][2][2];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	if (n < m) {
		swap(n, m);
	}
	dp[1][0][1] = dp[1][1][0] = 1;
	for (int i = 1; i < n; ++i) {	
		for (int p0 = 0; p0 < 2; ++p0) {
			for (int p1 = 0; p1 < 2; ++p1) {
				dp[i + 1][p1][!p1] += dp[i][p0][p1];
				dp[i + 1][p1][!p1] %= mod;
				if (p0 != p1) {
					dp[i + 1][p1][p1] += dp[i][p0][p1];
					dp[i + 1][p1][p1] %= mod;
				}
			}
		}
	}
	ll ans = 0;
	for (int p0 = 0; p0 < 2; ++p0) {
		for (int p1 = 0; p1 < 2; ++p1) {
			ans += dp[n][p0][p1];
			ans += dp[m][p0][p1];
		}
	}
	ans += mod - 2;
	cout << ans % mod << endl;
}