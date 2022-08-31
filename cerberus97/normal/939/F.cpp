/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 30, K = 150, inf = 1e6;

int tree[4 * N][2], dp[N], lt[K], rt[K];

void build(int i, int l, int r);
int query(int i, int l, int r, int ql, int qr, int par);

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; ++i) {
		cin >> lt[i] >> rt[i];
	}
	for (int i = 0; i <= 2 * n; ++i) {
		dp[i] = inf;
	}
	dp[n] = 0;
	build(1, 0, 2 * n);
	for (int i = 1; i <= k; ++i) {
		int c = lt[i] - rt[i - 1];
		int len = rt[i] - lt[i];
		for (int d = -n; d <= n; ++d) {
			int p = d - c - len + n;
			dp[d + n] = query(1, 0, 2 * n, p, p, p & 1);
			int l = -d - c - len + n;
			int r = -d - c + len + n;
			dp[d + n] = min(dp[d + n], 1 + query(1, 0, 2 * n, l, r, l & 1));
			l = d - c - len + n;
			r = d - c + len + n;
			dp[d + n] = min(dp[d + n], 2 + query(1, 0, 2 * n, l, r, l & 1));
			// cout << d << ' ' << dp[d + n] << endl;
		}
		// cout << endl << endl;
		build(1, 0, 2 * n);
	}
	int ans = rt[k] - n;
	if (dp[ans] >= inf or ans < 0 or ans > 2 * n) {
		cout << "Hungry";
	} else {
		cout << "Full\n" << dp[ans];
	}
}

void build(int i, int l, int r) {
	if (l == r) {
		tree[i][l & 1] = dp[l];
		tree[i][!(l & 1)] = inf;
		return;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = 1 + lc;
		build(lc, l, mid);
		build(rc, mid + 1, r);
		tree[i][0] = min(tree[lc][0], tree[rc][0]);
		tree[i][1] = min(tree[lc][1], tree[rc][1]);
	}
}

int query(int i, int l, int r, int ql, int qr, int par) {
	if (l > qr or ql > r) {
		return inf;
	} else if (ql <= l and r <= qr) {
		return tree[i][par];
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = 1 + lc;
		return min(query(lc, l, mid, ql, qr, par), query(rc, mid + 1, r, ql, qr, par));
	}
}