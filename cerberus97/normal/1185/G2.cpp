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

const int N = 55, mod = 1e9 + 7;

map<pair<vector<int>, int>, int> mp;
int t[N], g[N], ctr[3];
ll dp1[N][N][N * N], dp2[N][N * N];

ll solve(vector<int> &ctr, int last);

int main() {
	fast_cin();
	int n, T;
	cin >> n >> T;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i] >> g[i];
		--g[i];
		++ctr[g[i]];
	}
	dp1[0][0][0] = 1;
	dp2[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		if (g[i] == 2) {
			for (int c2 = ctr[2] - 1; c2 >= 0; --c2) {
				for (int t2 = 0; t2 <= T - t[i]; ++t2) {
					dp2[c2 + 1][t2 + t[i]] += dp2[c2][t2];
					dp2[c2 + 1][t2 + t[i]] %= mod;
				}
			}
		} else {
			for (int c0 = ctr[0]; c0 >= 0; --c0) {
				for (int c1 = ctr[1]; c1 >= 0; --c1) {
					for (int t12 = 0; t12 <= T - t[i]; ++t12) {
						dp1[c0 + (g[i] == 0)][c1 + (g[i] == 1)][t12 + t[i]] += dp1[c0][c1][t12];
						dp1[c0 + (g[i] == 0)][c1 + (g[i] == 1)][t12 + t[i]] %= mod;
					}
				}
			}
		}
	}
	ll ans = 0;
	for (int c0 = 0; c0 <= ctr[0]; ++c0) {
		for (int c1 = 0; c1 <= ctr[1]; ++c1) {
			for (int c2 = 0; c2 <= ctr[2]; ++c2) {
				vector<int> temp = {c0, c1, c2};
				ll permute = solve(temp, -1);
				if (!permute) {
					continue;
				}
				ll pick = 0;
				for (int t12 = 0; t12 <= T; ++t12) {
					pick += dp1[c0][c1][t12] * dp2[c2][T - t12];
					pick %= mod;
				}
				ans += permute * pick;
				ans %= mod;
			}
		}
	}
	cout << ans << endl;
}

ll solve(vector<int> &v, int last) {
	if (mp.count({v, last})) {
		return mp[{v, last}];
	} else {
		ll ans = 0;
		if (v[0] + v[1] + v[2] == 0) {
			ans = 1;
		} else {
			for (int i = 0; i < 3; ++i) {
				if (i == last) {
					continue;
				}
				ll temp = v[i];
				--v[i];
				temp *= solve(v, i);
				temp %= mod;
				++v[i];
				ans += temp;
			}
			ans %= mod;
		}
		mp[{v, last}] = ans;
		return ans;
	}
}