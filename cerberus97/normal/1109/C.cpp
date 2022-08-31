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

const int N = 2e5 + 10;
const ll inf = 1e18 + 42;

struct seg_node {
	ll sum, min_val, min_t, last_s;
	seg_node() : sum(0), min_val(0), min_t(inf), last_s(-inf) {}
};

struct qry_type {
	int type, v1, v2, v3;
};

seg_node tree[4 * N];
qry_type q[N];
map<ll, int> compress;
ll rev[N];

void update(int i, int l, int r, int p, ll s);
void combine(int i, int lc, int rc, int l, int mid, int r);
bool query(int i, int l, int r, int ql, int qr, ll &v, ll &s, ld &ans);

int main() {
	// cout << sizeof(tree) / 1e6 << endl;
	fast_cin();
	int t; cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> q[i].type >> q[i].v1;
		compress[q[i].v1];
		if (q[i].type == 1) {
			cin >> q[i].v2;
		} else if (q[i].type == 3) {
			cin >> q[i].v2 >> q[i].v3;
			compress[q[i].v2];
		}
	}
	int id = 0;
	for (auto &i : compress) {
		i.second = id;
		rev[id] = i.first;
		++id;
		// cout << i.second << ' ' << i.first << endl;
	}
	for (int i = 0; i < t; ++i) {
		// cout << "qry " << i << endl;
		if (q[i].type == 1) {
			update(1, 0, id, compress[q[i].v1], q[i].v2);
		} else if (q[i].type == 2) {
			update(1, 0, id, compress[q[i].v1], inf);
		} else {
			ll v = q[i].v3;
			ll s = 0;
			ld ans = 0;
			if (v == 0) {
				cout << q[i].v1 << '\n';
			} else if (query(1, 0, id, compress[q[i].v1], compress[q[i].v2], v, s, ans)) {
				cout << fixed << setprecision(10) << ans << '\n';
			} else {
				cout << -1 << '\n';
			}
		}
	}
}

void update(int i, int l, int r, int p, ll s) {
	// cout << i << ' ' << l << ' ' << r << endl;
	if (p < l or p >= r) {
		return;
	} else if (l == r - 1) {
		if (s == inf) {
			tree[i].sum = 0;
			tree[i].min_val = 0;
			tree[i].min_t = inf;
			tree[i].last_s = -inf;
		} else {
			tree[i].sum = s * (rev[r] - rev[l]);
			tree[i].min_val = min(0ll, tree[i].sum);
			tree[i].min_t = l;
			tree[i].last_s = s;
		}
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		update(lc, l, mid, p, s);
		update(rc, mid, r, p, s);
		combine(i, lc, rc, l, mid, r);
	}
}

void combine(int i, int lc, int rc, int l, int mid, int r) {
	// cout << i << ' ' << lc << ' ' << rc << ' ' << mid << endl;
	ll transition = 0;
	if (tree[lc].last_s != -inf) {
		ll temp = rev[r];
		if (tree[rc].min_t != inf) {
			temp = rev[tree[rc].min_t];
		}
		transition = (temp - rev[mid]) * tree[lc].last_s;
	}
	tree[i].sum = tree[lc].sum + tree[rc].sum + transition;
	tree[i].min_val = min(tree[lc].min_val, tree[lc].sum + transition + tree[rc].min_val);
	tree[i].min_t = min(tree[lc].min_t, tree[rc].min_t);
	if (tree[rc].last_s == -inf) {
		tree[i].last_s = tree[lc].last_s;
	} else {
		tree[i].last_s = tree[rc].last_s;
	}
	// cout << "DONE" << endl;
}

bool query(int i, int l, int r, int ql, int qr, ll &v, ll &s, ld &ans) {
	int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
	// cout << i << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << v << ' ' << s << endl;
	// cout << t
	if (l > qr or ql >= r) {
		return false;
	} else if (ql <= l and r <= qr) {
		if (tree[i].min_t == inf) {
			ll sz = rev[r] - rev[l];
			if (v + sz * s <= 0) {
				ans = rev[l] + ld(-v) / s;
				return true;
			} else {
				v += sz * s;
				return false;
			}
		} else {
			ll transition = rev[tree[i].min_t] - rev[l];
			ll min_val = v + transition * s + tree[i].min_val;
			if (v + transition * s <= 0) {
				ans = ld(-v) / s + rev[l];
				return true;
			} else if (min_val <= 0) {
				if (l == r - 1) {
					// cout << "c" << ' ' << rev[l] << ' ' << ld(-v) << ' ' << tree[i].last_s << endl;
					ans = rev[l] + ld(-v) / tree[i].last_s;
					// cout << ans << endl;
					return true;
				} else if (query(lc, l, mid, ql, qr, v, s, ans)) {
					return true;
				} else {
					return query(rc, mid, r, ql, qr, v, s, ans);
				}
			} else {
				v += transition * s + tree[i].sum;
				s = tree[i].last_s;
				return false;
			}
		}
	} else if (l == r - 1) {
		return false;
	} else {
		if (query(lc, l, mid, ql, qr, v, s, ans)) {
			return true;
		} else {
			return query(rc, mid, r, ql, qr, v, s, ans);
		}
	}
}