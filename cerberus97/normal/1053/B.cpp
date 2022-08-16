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

const int N = 3e5 + 10, LG = 150;

ll a[N], c[N], p[N], dp[N][2];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		c[i] = __builtin_popcountll(a[i]);
	}
	dp[0][0] = 1;
	p[0] = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = dp[i - 1][0];
		dp[i][1] = dp[i - 1][1];
		p[i] = (p[i - 1] + c[i]) % 2;
		++dp[i][p[i]];
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ll sum = 0, mx = 0;
		for (int j = i; j <= n and j <= i + LG; ++j) {
			sum += c[j];
			mx = max(mx, c[j]);
			if (sum % 2 == 0 and 2 * mx <= sum) {
				++ans;
			}
		}
	}
	for (int j = LG + 2; j <= n; ++j) {
		ans += dp[j - LG - 2][p[j] & 1];
	}
	cout << ans << endl;
}