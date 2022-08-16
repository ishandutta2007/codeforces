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

const int N = 1500 + 10;

int a[N], b[N], c[N], d[N], r[N], dp[N][N];

int main() {
	fast_cin();
	int n, s, m, k;
	cin >> n >> s >> m >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + 1 + n);
	for (int i = 1; i <= s; ++i) {
		int u, v;
		cin >> u >> v;
		r[u] = max(r[u], v);
	}
	for (int i = 1; i <= n; ++i) {
		r[i] = max(r[i], r[i - 1]);
	}
	int lo = 1, hi = n;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		ll x = b[mid];
		for (int i = 1; i <= n; ++i) {
			c[i] = (a[i] <= x);
			d[i] = d[i - 1] + c[i];
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= m; ++j) {
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
				if (r[i + 1] > i) {
					dp[r[i + 1]][j + 1] = max(dp[r[i + 1]][j + 1], dp[i][j] + d[r[i + 1]] - d[i]);
				}
			}
		}
		bool ok = false;
		for (int j = 0; j <= m; ++j) {
			if (dp[n][j] >= k) {
				ok = true;
				break;
			}
		}
		if (ok) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	b[n + 1] = -1;
	cout << b[hi + 1] << endl;
}