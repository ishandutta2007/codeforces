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

const int N = 3e5 + 10;
const ll inf = 1e18 + 42;

ll a[N], b[N], dp[N][3];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i] >> b[i];
		}
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j < 3; ++j) {
				dp[i][j] = inf;
			}
		}
		dp[0][0] = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 3; ++j) {
				for (int k = 0; k < 3; ++k) {
					if (a[i] + j != a[i + 1] + k) {
						dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + k * b[i + 1]);
					}
				}
			}
		}
		ll ans = inf;
		for (int j = 0; j < 3; ++j) {
			ans = min(ans, dp[n][j]);
		}
		cout << ans << '\n';
	}
}