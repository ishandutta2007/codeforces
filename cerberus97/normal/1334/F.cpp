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

const int N = 5e5 + 10;
const ll inf = 1e18 + 42;

ll tree[4 * N];

void update_add(int i, int l, int r, int ql, int qr, ll x);
void update_min(int i, int l, int r, int p, ll x);
ll query(int i, int l, int r, int p);

int main() {
	fast_cin();
	int n; cin >> n;
	vector<int> a(n), p(n);
	for (auto& i : a) {
		cin >> i;
	}
	for (auto& i : p) {
		cin >> i;
	}
	int m; cin >> m;
	vector<int> b(m);
	for (auto& i : b) {
		cin >> i;
	}
	vector<ll> psum(n, 0);
	psum[0] = 0;
	for (int i = 1; i < n; ++i) {
		psum[i] = psum[i - 1] + p[i - 1];
	}
	update_add(1, 0, m, 0, m - 1, inf);
	// ll ans = inf;
	int cur = m;
	for (int i = n - 1; i >= 0; --i) {
		auto it = lower_bound(b.begin(), b.end(), a[i]);
		if (it != b.end() and *it == a[i]) {
			int j = (it - b.begin());
			if (j >= cur - 1) {
				cur = min(cur, j);
				ll dp = query(1, 0, m, j + 1);
				update_min(1, 0, m, j, dp - p[i]);
			}
		}
		if (p[i] < 0) {
			update_add(1, 0, m, cur, m, p[i]);
		} else {
			int j = (it - b.begin());
			update_add(1, 0, m, 0, j, p[i]);
		}
	}
	if (cur > 0) {
		cout << "NO\n";
	} else {
		cout << "YES\n" << query(1, 0, m, 0) << '\n';
	}
}

void update_add(int i, int l, int r, int ql, int qr, ll x) {
	if (l > qr or ql > r) {
		return;
	} else if (ql <= l and r <= qr) {
		tree[i] += x;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		update_add(lc, l, mid, ql, qr, x);
		update_add(rc, mid + 1, r, ql, qr, x);
	}
}
	
void update_min(int i, int l, int r, int p, ll x) {
	if (p < l or p > r) {
		return;
	} else if (l == r) {
		tree[i] = min(tree[i], x);
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		update_min(lc, l, mid, p, x - tree[i]);
		update_min(rc, mid + 1, r, p, x - tree[i]);
	}
}

ll query(int i, int l, int r, int p) {
	if (p < l or p > r) {
		return inf;
	} else if (l == r) {
		return tree[i];
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		return tree[i] + min(query(lc, l, mid, p), query(rc, mid + 1, r, p));
	}
}