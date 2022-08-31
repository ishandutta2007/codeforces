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

const int N = 1e6 + 10, M = 20, S = (1 << M) + 10;

int dp[S];

int main() {
	fast_cin();
	string s; cin >> s;
	int n = s.length();
	for (auto &c : s) {
		c -= 'a';
	}
	for (int i = 0; i < n; ++i) {
		int mask = 0;
		for (int j = i; j < n; ++j) {
			if (mask & (1 << s[j])) {
				break;
			} else {
				mask |= (1 << s[j]);
				dp[mask] = __builtin_popcount(mask);
			}
		}
	}
	int m = M, tot = (1 << m);
	for (int i = 0; i < m; ++i) {
		for (int mask = 0; mask < tot; ++mask) {
			if (mask & (1 << i)) {
				dp[mask] = max(dp[mask], dp[mask ^ (1 << i)]);
			}
		}
	}
	int ans = 0;
	for (int mask = 0; mask < tot; ++mask) {
		ans = max(ans, dp[mask] + dp[tot - 1 - mask]);
	}
	cout << ans << endl;
}