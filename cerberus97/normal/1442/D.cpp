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
#include <functional>

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
	int n, k;
	cin >> n >> k;
	vector<vector<ll>> a(n), pref(n);
	for (int i = 0; i < n; ++i) {
		int sz; cin >> sz;
		a[i].resize(sz);
		for (auto& j : a[i]) {
			cin >> j;
		}
		a[i].resize(min(sz, k));
		pref[i] = a[i];
		for (int j = 1; j < a[i].size(); ++j) {
			pref[i][j] += pref[i][j - 1];
		}
	}
	ll ans = 0;
	function<void(int, int, vector<ll>&)> solve = [&](int l, int r, vector<ll>& dp) {
		if (l == r) {
			ans = max(ans, dp[k]);
			int sz = a[l].size();
			for (int w = 1; w <= sz; ++w) {
				ans = max(ans, pref[l][w - 1] + dp[k - w]);
			}
		} else {
			int mid = (l + r) / 2;
			auto bak = dp;
			for (int i = l; i <= mid; ++i) {
				int sz = a[i].size();
				for (int j = k - sz; j >= 0; --j) {
					dp[j + sz] = max(dp[j + sz], dp[j] + pref[i][sz - 1]);
				}
			}
			solve(mid + 1, r, dp);
			dp = bak;
			for (int i = mid + 1; i <= r; ++i) {
				int sz = a[i].size();
				for (int j = k - sz; j >= 0; --j) {
					dp[j + sz] = max(dp[j + sz], dp[j] + pref[i][sz - 1]);
				}
			}
			solve(l, mid, dp);
		}
	};
	vector<ll> dp(k + 1, 0);
	solve(0, n - 1, dp);
	cout << ans << '\n';
}