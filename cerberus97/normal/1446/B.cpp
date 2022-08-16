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

const int N = 1e5 + 10;

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	a = " " + a; b = " " + b;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	int ans = 0;
	for (int l = 1; l <= n; ++l) {
		for (int r = 1; r <= m; ++r) {
			if (a[l] == b[r]) {
				dp[l][r] = max(dp[l][r], dp[l - 1][r - 1] + 4 - 2);
			}
			dp[l][r] = max(dp[l][r], dp[l - 1][r] - 1);
			dp[l][r] = max(dp[l][r], dp[l][r - 1] - 1);
			ans = max(ans, dp[l][r]);
		}
	}
	cout << ans << '\n';
}