/* 	* In the name of GOD  */
 
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
#define F first
#define S second
#define mk make_pair
map <int, int> par, f, sz;

inline int get (int x) {
	return (par[x] == 0 ? x : par[x]);
}

pair <int, int> get_root (int x) {
	if (get(x) == x)
		return {x, 0};
	pair <int, int> p = get_root(get(x));
	par[x] = p.F;
	f[x] ^= p.S;
	return {p.F, f[x]};
}

void merge (int x, int y, int w) {
	pair <int, int> px, py;
	px = get_root(x);
	py = get_root(y);
	if (px.F == py.F)
		return;
	if (sz[px.F] > sz[py.F])
		swap(px, py);
	par[px.F] = py.F;
	f[px.F] = px.S ^ py.S ^ w;
	sz[py.F] += sz[px.F];
	sz[px.F] = 0;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int last = 0;
	int q = 0;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			l ^= last;
			r ^= last;
			x ^= last;
			if (l > r)
				swap(l, r);
			l++;
			r += 2;
			merge(l, r, x);
		} else {
			int l, r;
			cin >> l >> r;
			l ^= last;
			r ^= last;
			if (l > r)
				swap(l, r);
			l++;
			r += 2;
			pair <int, int> pl = get_root(l), pr = get_root(r);
			if (pl.F == pr.F) {
				last = pl.S ^ pr.S;
				cout << last << '\n';
			} else {
				last = 1;
				cout << -1 << '\n';
			}
		}
	}
}