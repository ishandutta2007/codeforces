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

const int N = 5e5 + 10;

int a[N], tree[4 * N];

void build(int i, int l, int r);
void update(int i, int l, int r, int p, int x);
bool query(int i, int l, int r, int ql, int qr, int x, bool ch);
inline int gcd(int x, int y);

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	build(1, 1, n);
	int q;
	scanf("%d", &q);
	while (q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			if (query(1, 1, n, l, r, x, true)) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		} else {
			int i, y;
			scanf("%d%d", &i, &y);
			update(1, 1, n, i, y);
		}
	}
}

void build(int i, int l, int r) {
	if (l == r) {
		tree[i] = a[l];
		return;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		build(lc, l, mid);
		build(rc, mid + 1, r);
		tree[i] = gcd(tree[lc], tree[rc]);
	}
}

void update(int i, int l, int r, int p, int x) {
	if (l == r) {
		tree[i] = x;
		return;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		if (p <= mid) {
			update(lc, l, mid, p, x);
		} else {
			update(rc, mid + 1, r, p, x);
		}

		tree[i] = gcd(tree[lc], tree[rc]);
	}
}

bool query(int i, int l, int r, int ql, int qr, int x, bool ch) {
	if (l > qr or ql > r) {
		return true;
	} else if (l == r) {
		return !(tree[i] % x) or ch;
	}

	int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
	if (ql <= l and r <= qr) {
		if (!ch) {
			return !(tree[i] % x);
		} else if (tree[lc] % x and tree[rc] % x) {
			return false;
		} else if (tree[lc] % x) {
			return query(lc, l, mid, ql, qr, x, 1);
		} else if (tree[rc] % x) {
			return query(rc, mid + 1, r, ql, qr, x, 1);
		} else {
			return true;
		}
	} else if (!ch) {
		return query(lc, l, mid, ql, qr, x, 0) and query(rc, mid + 1, r, ql, qr, x, 0);
	} else if (query(lc, l, mid, ql, qr, x, 0)) {
		return query(rc, mid + 1, r, ql, qr, x, 1);
	} else if (query(rc, mid + 1, r, ql, qr, x, 0)) {
		return query(lc, l, mid, ql, qr, x, 1);
	} else {
		return false;
	}
}

inline int gcd(int x, int y) {
	while (y) {
		x %= y;
		swap(x, y);
	}

	return x;
}