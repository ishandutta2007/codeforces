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

const int N = 13, M = 2010, S = (1 << 12) + 10;

int a[N][M], mx[M];
ll f[N][S], dp[N][S];

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		memset(mx, 0, sizeof(mx));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> a[i][j];
				mx[j] = max(mx[j], a[i][j]);
			}
		}
		vector<int> ids(m);
		iota(ids.begin(), ids.end(), 0);
		sort(ids.begin(), ids.end(), [&](int i, int j) {
			return mx[i] > mx[j];
		});
		m = min(m, n);
		int tot = (1 << n);
		memset(f, 0, sizeof(f));
		for (int j = 0; j < m; ++j) {
			for (int mask = 0; mask < tot; ++mask) {
				for (int s = 0; s < n; ++s) {
					ll sum = 0;
					for (int i = 0; i < n; ++i) {
						if ((mask & (1 << i))) {
							sum += a[(i + s) % n][ids[j]];
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
				int complement = tot - 1 - mask, oth = complement;
				while (true) {
					if ((mask & oth) == 0) {
						dp[j + 1][mask + oth] = max(dp[j + 1][mask + oth], dp[j][mask] + f[j][oth]);
					}
					if (!oth) {
						break;
					}
					oth = (oth - 1) & complement;
				}
			}
		}
		cout << dp[m][tot - 1] << '\n';
	}
}