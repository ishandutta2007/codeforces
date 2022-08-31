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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 3e3 + 10, mod = 998244353;

void add(int& a, int b) {
	a += b;
	if (a > mod) a -= mod;
}

int dp[N][N];

int main() {
	fast_cin();
	string s, t;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	for (int i = 0; i < n; ++i) {
		if (i < m) {
			dp[1][i] = 2 * (t[i] == s[0]);
		} else {
			dp[1][i] = 2;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int l = 0; l + i - 1 < n; ++l) {
			if (!dp[i][l]) {
				continue;
			}
			int r = l + i - 1;
			if (i >= m and l == 0) {
				add(ans, dp[i][l]);
			}
			if ((l - 1 >= m) or (l > 0 and t[l - 1] == s[i])) {
				add(dp[i + 1][l - 1], dp[i][l]);
			}
			if ((r + 1 >= m and r + 1 < n) or (r + 1 < m and t[r + 1] == s[i])) {
				add(dp[i + 1][l], dp[i][l]);
			}
		}
	}
	cout << ans << endl;
}