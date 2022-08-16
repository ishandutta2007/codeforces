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

const int N = 2e5 + 10;

struct node {
	ll sum = 0;
	int mx = 0, mn = 0, lazy = 0;
} tree[4 * N];

void update(int i, int l, int r, int ql, int qr, int y);
void query(int i, int l, int r, int x, int& y, int& ans);
void propagate(int i, int l, int mid, int r, int lc, int rc);
void merge(int i, int lc, int rc);

int main() {
	fast_cin();
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	for (int i = 0; i < n; ++i) {
		update(1, 0, n - 1, i, i, a[i]);
	}
	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			update(1, 0, n - 1, 0, x - 1, y);
		} else {
			--x;
			int ans = 0;
			query(1, 0, n - 1, x, y, ans);
			cout << ans << '\n';
		}
	}
}

void update(int i, int l, int r, int ql, int qr, int y) {
	if (l > qr or ql > r or tree[i].mn >= y) {
		return;
	} else if (ql <= l and r <= qr and tree[i].mx <= y) {
		tree[i] = {(r - l + 1) * ll(y), y, y, y};
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		propagate(i, l, mid, r, lc, rc);
		update(lc, l, mid, ql, qr, y);
		update(rc, mid + 1, r, ql, qr, y);
		merge(i, lc, rc);
	}
}

void query(int i, int l, int r, int x, int& y, int& ans) {
	if (x > r) {
		return;
	} else if (x == l) {
		if (tree[i].sum <= y) {
			y -= tree[i].sum;
			ans += (r - l + 1);
			return;
		} else if (tree[i].mn > y) {
			return;
		}
	}
	int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
	propagate(i, l, mid, r, lc, rc);
	query(lc, l, mid, x, y, ans);
	query(rc, mid + 1, r, max(x, mid + 1), y, ans);
}

void propagate(int i, int l, int mid, int r, int lc, int rc) {
	if (tree[i].lazy) {
		tree[lc] = {(mid - l + 1) * ll(tree[i].lazy), tree[i].lazy, tree[i].lazy, tree[i].lazy};
		tree[rc] = {(r - mid) * ll(tree[i].lazy), tree[i].lazy, tree[i].lazy, tree[i].lazy};
		tree[i].lazy = 0;
	}
}

void merge(int i, int lc, int rc) {
	tree[i].sum = tree[lc].sum + tree[rc].sum;
	tree[i].mn = tree[rc].mn;
	tree[i].mx = tree[lc].mx;
}