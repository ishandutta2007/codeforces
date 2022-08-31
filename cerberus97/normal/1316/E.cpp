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
#define smax(a, b) a = max(a, b)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

struct player {
	int x;
	vector<int> s;
	player(int p) : s(p) {}
	bool operator<(const player& o) const {
		return x > o.x;
	}
};

int main() {
	fast_cin();
	int n, p, k;
	cin >> n >> p >> k;
	vector<player> a(n, player(p));
	for (int i = 0; i < n; ++i) {
		cin >> a[i].x;
	}
	for (int i = 0; i < n; ++i) {
		for (auto& j : a[i].s) {
			cin >> j;
		}
	}
	sort(a.begin(), a.end());
	int tot = (1 << p);
	vector<vector<ll>> dp(n + 1, vector<ll>(tot, -1));
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int mask = 0; mask < tot; ++mask) {
			if (dp[i][mask] == -1) {
				continue;
			}
			int in_aud = i - __builtin_popcount(mask);
			if (in_aud < k) {
				smax(dp[i + 1][mask], dp[i][mask] + a[i].x);
			} else {
				smax(dp[i + 1][mask], dp[i][mask]);
			}
			for (int j = 0; j < p; ++j) {
				if (!((mask >> j) & 1)) {
					smax(dp[i + 1][mask | (1 << j)], dp[i][mask] + a[i].s[j]);
				}
			}
		}
	}
	cout << dp[n][tot - 1] << endl;
}