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

const int N = 5, M = 110, S = (1 << 4) + 10;

int a[N][M];
ll f[M][S], dp[M][S];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> a[i][j];
			}
		}
		int tot = (1 << n);
		memset(f, 0, sizeof(f));
		for (int j = 0; j < m; ++j) {
			for (int mask = 0; mask < tot; ++mask) {
				for (int s = 0; s < n; ++s) {
					ll sum = 0;
					for (int i = 0; i < n; ++i) {
						if ((mask & (1 << i))) {
							sum += a[(i + s) % n][j];
						}
					}
					f[j][mask] = max(f[j][mask], sum);
				}
			}
		}
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for (int j = 0; j < m; ++j) {
			for (int mask = 0; mask < tot; ++mask) {
				if (dp[j][mask] == -1) {
					continue;
				}
				for (int oth = 0; oth < tot; ++oth) {
					if ((mask & oth) == 0) {
						dp[j + 1][mask + oth] = max(dp[j + 1][mask + oth], dp[j][mask] + f[j][oth]);
					}
				}
			}
		}
		cout << dp[m][tot - 1] << '\n';
	}
}