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

const int B = 31;

ll dp[B][2][2];

ll solve(int x, int y);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		ll ans = solve(r, r) - 2 * solve(l - 1, r) + solve(l - 1, l - 1);
		cout << ans << '\n';
	}
}

ll solve(int x, int y) {
	if (x < 0 or y < 0) {
		return 0;
	}
	memset(dp, 0, sizeof(dp));
	dp[B - 1][1][1] = 1;
	for (int b = B - 1; b > 0; --b) {
		bool b1 = (x >> (b - 1)) & 1;
		bool b2 = (y >> (b - 1)) & 1;
		for (int e1 = 0; e1 < 2; ++e1) {
			for (int e2 = 0; e2 < 2; ++e2) {
				if (!dp[b][e1][e2]) {
					continue;
				}
				for (int n1 = 0; n1 < 2; ++n1) {
					for (int n2 = 0; n2 < 2; ++n2) {
						if (n1 and n2) {
							continue;
						} else if (n1 > b1 and e1) {
							continue;
						} else if (n2 > b2 and e2) {
							continue;
						}
						dp[b - 1][e1 and (n1 == b1)][e2 and (n2 == b2)] += dp[b][e1][e2];
					}
				}
			}
		}
	}
	ll ans = 0;
	for (int e1 = 0; e1 < 2; ++e1) {
		for (int e2 = 0; e2 < 2; ++e2) {
			ans += dp[0][e1][e2];
		}
	}
	return ans;
}