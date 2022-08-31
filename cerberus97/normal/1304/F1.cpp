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

const int N = 50 + 10, M = 2e4 + 10;

int a[N][M], tree[4 * M], lazy[4 * M], dp[N][M];

void update(int i, int l, int r, int ql, int qr, int x);
void propagate(int i, int lc, int rc);

int main() {
	fast_cin();
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = m; j >= 1; --j) {
			a[i][j] += a[i][j + 1];
		}
	}
	m = m - k + 1;
	for (int i = 1; i <= n; ++i) {
		memset(tree, 0, sizeof(tree));
		memset(lazy, 0, sizeof(lazy));
		for (int j = 1; j <= m; ++j) {
			int intersection = ((i == 1 or (j > k)) ? 0 : a[i][j] - a[i][k + 1]);
			update(1, 1, m, j, j, dp[i - 1][j] - intersection);
		}
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = tree[1];
			dp[i][j] += (a[i][j] - a[i][j + k]) + (a[i + 1][j] - a[i + 1][j + k]);
			if (i > 1) {
				update(1, 1, m, j - k + 1, j, a[i][j] - a[i][j + 1]);
				update(1, 1, m, j + 1, j + k, -(a[i][j + k] - a[i][j + k + 1]));
			}
		}
	}
	int ans = 0;
	for (int j = 1; j <= m; ++j) {
		ans = max(ans, dp[n][j]);
	}
	cout << ans << endl;
}

void update(int i, int l, int r, int ql, int qr, int x) {
	if (l > qr or ql > r) {
		return;
	} else if (ql <= l and r <= qr) {
		tree[i] += x;
		lazy[i] += x;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		propagate(i, lc, rc);
		update(lc, l, mid, ql, qr, x);
		update(rc, mid + 1, r, ql, qr, x);
		tree[i] = max(tree[lc], tree[rc]);
	}
}

void propagate(int i, int lc, int rc) {
	tree[lc] += lazy[i];
	tree[rc] += lazy[i];
	lazy[lc] += lazy[i];
	lazy[rc] += lazy[i];
	lazy[i] = 0;
}