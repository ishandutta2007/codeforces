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

const int N = 1e6 + 10;

int a[N], tree[4 * N];

void update(int i, int l, int r, int p, int x);
int query(int i, int l, int r, int ql, int qr);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += query(1, 1, n, a[i] + 1, n);
		update(1, 1, n, a[i], 1);
	}
	if ((n & 1) == (ans & 1)) {
		cout << "Petr";
	} else {
		cout << "Um_nik";
	}
}

void update(int i, int l, int r, int p, int x) {
	tree[i] += x;
	if (l == r) {
		return;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		if (p <= mid) {
			update(lc, l, mid, p, x);
		} else {
			update(rc, mid + 1, r, p, x);
		}
	}
}

int query(int i, int l, int r, int ql, int qr) {
	if (l > qr or ql > r) {
		return 0;
	} else if (ql <= l and r <= qr) {
		return tree[i];
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		return query(lc, l, mid, ql, qr) + query(rc, mid + 1, r, ql, qr);
	}
}