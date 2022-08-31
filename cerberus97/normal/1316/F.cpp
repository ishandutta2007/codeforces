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

const int N = 3e5 + 10, Q = 3e5 + 10, mod = 1e9 + 7;

int add(int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0) a += mod;
	return a;
}

int mul(ll a, int b) {
	return (a * b) % mod;
}

int pwr(int x, int e) {
	int res = 1;
	while (e) {
		if (e & 1) {
			res = mul(res, x);
		}
		x = mul(x, x);
		e /= 2;
	}
	return res;
}

struct node_t {
	int cnt, vl, vr, ans;
	node_t() {
		cnt = vl = vr = ans = 0;
	}
};

struct upd_t {
	int val, idx, tm, tree_id;
};

node_t tree[4 * (N + Q)];
int p2[N], p2_inv[N], val[N + Q];
bool init[N + Q];

void build(int i, int l, int r);
void update(int i, int l, int r, int p, int x);
void combine(node_t& n, const node_t& l, const node_t& r);

int main() {
	fast_cin();
	int n; cin >> n;
	p2[0] = p2_inv[0] = 1;
	int half = pwr(2, mod - 2);
	for (int i = 1; i <= n; ++i) {
		p2[i] = mul(2, p2[i - 1]);
		p2_inv[i] = mul(half, p2_inv[i - 1]);
	}
	vector<upd_t> upd(n);
	vector<int> loc(n, -1);
	for (int i = 0; i < n; ++i) {
		int p; cin >> p;
		upd[i] = {p, i, i, 0};
	}
	int q; cin >> q;
	upd.resize(n + q);
	for (int i = 0; i < q; ++i) {
		int idx, x;
		cin >> idx >> x;
		upd[n + i] = {x, idx - 1, n + i, 0};
	}
	sort(upd.begin(), upd.end(), [&](const upd_t& u1, const upd_t& u2) {
		return u1.val < u2.val;
	});
	for (int i = 0; i < n + q; ++i) {
		upd[i].tree_id = i + 1;
		val[i + 1] = upd[i].val;
		init[i + 1] = (upd[i].tm < n);
	}
	build(1, 1, n + q);
	cout << tree[1].ans << '\n';
	sort(upd.begin(), upd.end(), [&](const upd_t& u1, const upd_t& u2) {
		return u1.tm < u2.tm;
	});
	for (auto& u : upd) {
		if (u.tm < n) {
			loc[u.idx] = u.tree_id;
		} else {
			update(1, 1, n + q, loc[u.idx], 0);
			loc[u.idx] = u.tree_id;
			update(1, 1, n + q, loc[u.idx], 1);
			cout << tree[1].ans << '\n';
		}
	}
}

void build(int i, int l, int r) {
	if (l == r) {
		tree[i].cnt = init[l];
		tree[i].vl = mul(init[l], val[l]);
		tree[i].vr = mul(p2_inv[1], tree[i].vl);
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		build(lc, l, mid);
		build(rc, mid + 1, r);
		combine(tree[i], tree[lc], tree[rc]);
	}
}

void update(int i, int l, int r, int p, int x) {
	if (l > p or p > r) {
		return;
	} else if (l == r) {
		tree[i].cnt = x;
		tree[i].vl = mul(x, val[l]);
		tree[i].vr = mul(p2_inv[1], tree[i].vl);
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		update(lc, l, mid, p, x);
		update(rc, mid + 1, r, p, x);
		combine(tree[i], tree[lc], tree[rc]);
	}
}

void combine(node_t& n, const node_t& l, const node_t& r) {
	n.cnt = l.cnt + r.cnt;
	n.ans = add(add(l.ans, r.ans), mul(mul(l.vl, r.vr), p2_inv[l.cnt]));
	n.vl = add(l.vl, mul(p2[l.cnt], r.vl));
	n.vr = add(l.vr, mul(p2_inv[l.cnt], r.vr));
}