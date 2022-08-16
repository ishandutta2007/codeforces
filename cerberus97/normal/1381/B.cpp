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

const int N = 2e3 + 10;

int dp[2 * N][N];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> p(2 * n);
		for (auto& i : p) {
			cin >> i;
		}
		reverse(p.begin(), p.end());
		for (int i = 0; i <= 2 * n; ++i) {
			for (int len = 0; len <= n; ++len) {
				dp[i][len] = 0;
			}
		}
		int inf = 2 * n + 1;
		dp[1][1] = inf;
		for (int i = 1; i < 2 * n; ++i) {
			for (int len = 0; len <= n and len <= i; ++len) {
				if (i - len > n or !dp[i][len]) {
					continue;
				}
				if (len < n and p[i] < dp[i][len]) {
					dp[i + 1][len + 1] = max(dp[i + 1][len + 1], dp[i][len]);
				}
				if (i - len < n and p[i] < p[i - 1]) {
					dp[i + 1][i - len + 1] = max(dp[i + 1][i - len + 1], p[i - 1]);
				}
			}
		}
		if (dp[2 * n][n]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}