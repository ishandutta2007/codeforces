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

const int N = 5e5 + 10, inf = 1e6;

int a[N], ans[N], l[N], r[N], ql[N], qr[N], tree[4 * N], idx[4 * N];
vector<int> occ[N], events[N];
set<pii> str[N];

void update(int i, int l, int r, int p, int v) ;
pii query(int i, int l, int r, int ql, int qr);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		occ[a[i]].pb(i);
	}
	for (int i = 1; i < N; ++i) {
		if (occ[i].empty()) {
			continue;
		}
		occ[i].pb(0);
		occ[i].pb(n + 1);
		int s = occ[i].size();
		sort(occ[i].begin(), occ[i].end());
		for (int j = 1; j < s - 1; ++j) {
			l[occ[i][j]] = occ[i][j - 1] + 1;
			r[occ[i][j]] = occ[i][j + 1] - 1;
		}
	}
	int q; cin >> q;
	for (int i = 1; i <= q; ++i) {
		cin >> ql[i] >> qr[i];
		events[ql[i]].pb(i);
		events[qr[i] + 1].pb(-i);
	}
	for (int i = 1; i <= n; ++i) {
		update(1, 1, n, i, inf);
		str[i].insert({inf, 0});
	}
	for (int p = 1; p <= n; ++p) {
		for (auto &i : events[p]) {
			if (i > 0) {
				str[ql[i]].insert({qr[i], i});
				update(1, 1, n, ql[i], str[ql[i]].begin()->first);
			} else {
				i = -i;
				str[ql[i]].erase({qr[i], i});
				update(1, 1, n, ql[i], str[ql[i]].begin()->first);
			}
		}
		while (true) {
			pii temp = query(1, 1, n, l[p], r[p]);
			int val = temp.first, pos = temp.second;
			// cout << pos << ' ' << val << endl;
			if (val <= r[p]) {
				ans[str[pos].begin()->second] = a[p];
				str[pos].erase(str[pos].begin());
				update(1, 1, n, pos, str[pos].begin()->first);
			} else {
				break;
			}
		}
	}
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << '\n';
	}
}

void update(int i, int l, int r, int p, int v) {
	if (l == r) {
		tree[i] = v;
		idx[i] = l;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		if (p <= mid) {
			update(2 * i, l, mid, p, v);
		} else {
			update(2 * i + 1, mid + 1, r, p, v);
		}
		if (tree[lc] <= tree[rc]) {
			tree[i] = tree[lc];
			idx[i] = idx[lc];
		} else {
			tree[i] = tree[rc];
			idx[i] = idx[rc];
		}
	}
}

pii query(int i, int l, int r, int ql, int qr) {
	if (l > qr or ql > r) {
		return {inf, 0};
	} else if (ql <= l and r <= qr) {
		return {tree[i], idx[i]};
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		pii q1 = query(lc, l, mid, ql, qr);
		pii q2 = query(rc, mid + 1, r, ql, qr);
		if (q1.first <= q2.first) {
			return q1;
		} else {
			return q2;
		}
	}
}