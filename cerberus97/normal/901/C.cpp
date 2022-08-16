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

const int N = 3e5 + 10, inf = 1e6;

struct Q {
	int l, r, ind;
	bool operator<(const Q &other) const {
		return r < other.r;
	}
} qry[N];

vector <int> g[N], stk;
vector <pii> cycles;
ll tree1[4 * N], tree2[4 * N], store[N];
int seen[N];
int f[N];

void find_cycles(int cur, int p);
void update(ll* tree, int i, int l, int r, int p, ll x);
ll query(ll* tree, int i, int l, int r, int ql, int qr);
inline ll int_sum(ll x);

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
		// cout << u << ' ' << v << endl;
	}

	for (int i = 1; i <= n; ++i) {
		f[i] = n;
		if (!seen[i]) {
			// cout << "agd" << i << endl;
			find_cycles(i, -1);
		}
	}

	// cout << "Here\n";
	// return 0;
	for (auto &c : cycles) {
		f[c.first] = min(f[c.first], c.second - 1); 
	}

	int mn = inf;
	vector <pii> v;
	for (int i = n; i >= 1; --i) {
		mn   = min(f[i], mn);
		f[i] = mn;
		v.pb({f[i], i});
	}

	sort(v.begin(), v.end());
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d", &qry[i].l, &qry[i].r);
		qry[i].ind = i;
	}

	for (int i = 1; i <= n; ++i) {
		update(tree2, 1, 1, n, i, 1);
	}

	sort(qry + 1, qry + 1 + q);
	int nxt = 0;
	for (int i = 1; i <= q; ++i) {
		int ql = qry[i].l;
		int qr = qry[i].r;
		while (nxt < n and v[nxt].first < qry[i].r) {
			update(tree1, 1, 1, n, v[nxt].second, v[nxt].first);
			update(tree2, 1, 1, n, v[nxt].second, -1);
			++nxt;
		}

		ll ans = query(tree1, 1, 1, n, ql, qr);
		ans   += query(tree2, 1, 1, n, ql, qr) * qr;
		ans   -= int_sum(qr - 1) - int_sum(ql - 2);
		store[qry[i].ind] = ans;
	}

	for (int i = 1; i <= q; ++i) {
		printf("%lld\n", store[i]);
	}
}

void find_cycles(int cur, int p) {
	seen[cur] = 1;
	stk.pb(cur);
	for (auto &i : g[cur]) {
		// cout << cur << ' ' << p << ' ' << i << ' ' << seen[i] << endl;
		if (i == p) {
			continue;
		} else if (!seen[i]) {
			find_cycles(i, cur);
		} else if (seen[i] == 1) {
			int l = inf, r = -1;
			auto it = stk.rbegin();
			// cout << cur << ' ' << i << endl;
			while (true) {
				// cout << *it << endl;
				l = min(l, *it);
				r = max(r, *it);
				if ((*it) == i) {
					break;
				}

				++it;
			};

			cycles.pb({l, r});
		}
	}

	seen[cur] = 2;
	stk.pop_back();
}

void update(ll* tree, int i, int l, int r, int p, ll x) {
	tree[i] += x;
	if (l == r) {
		return;
	}

	int mid = (l + r) / 2;
	if (p <= mid) {
		update(tree, 2 * i, l, mid, p, x);
	} else {
		update(tree, 2 * i + 1, mid + 1, r, p, x);
	}
}

ll query(ll* tree, int i, int l, int r, int ql, int qr) {
	if (l > qr or ql > r) {
		return 0;
	} else if (ql <= l and r <= qr) {
		return tree[i];
	} else {
		int mid = (l + r) / 2;
		ll lt = query(tree, 2 * i, l, mid, ql, qr);
		ll rt = query(tree, 2 * i + 1, mid + 1, r, ql, qr);
		return lt + rt;
	}
}

inline ll int_sum(ll x) {
	return (x * (x + 1)) / 2;
}