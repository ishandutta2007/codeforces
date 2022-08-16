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

const int N = 14, S = (1 << N) + 10;

vector<ll> dp[S][N];

int main() {
	fast_cin();
	int n; cin >> n;
	vector<vector<bool>> g(n, vector<bool>(n));
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < n; ++j) {
			g[i][j] = (s[j] == '1');
		}
	}
	int tot = (1 << n);
	for (int mask = 0; mask < tot; ++mask) {
		int sz = __builtin_popcount(mask);
		for (int i = 0; i < n; ++i) {
			if (!((mask >> i) & 1)) {
				continue;
			}
			dp[mask][i].resize(1 << (sz - 1), 0);
			if (sz == 1) {
				dp[mask][i][0] = 1;
			} else {
				for (int s = 0; s < (1 << (sz - 1)); ++s) {
					bool rel = s & 1;
					for (int j = 0; j < n; ++j) {
						if (i != j and ((mask >> j) & 1) and g[i][j] == rel) {
							dp[mask][i][s] += dp[mask - (1 << i)][j][s >> 1];
						}
					}
				}
			}
		}
	}
	vector<ll> ans(tot / 2, 0);
	for (int i = 0; i < n; ++i) {
		for (int s = 0; s < tot / 2; ++s) {
			ans[s] += dp[tot - 1][i][s];
		}
	}
	for (auto& i : ans) {
		cout << i << ' ';
	}
	cout << endl;
}