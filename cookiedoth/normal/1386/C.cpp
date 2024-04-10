/*

Code for problem  by cookiedoth
Generated 26 Jul 2020 at 01.58 PM



10%

30%

50%

70%

100%

~_^
=_=
\_()_/

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct dsu {
	vector<int> p, sz, off;
	vector<pair<int, int> > st;
	int n;

	dsu() {}

	void init(int _n) {
		n = _n;
		p.resize(n);
		iota(all(p), 0);
		off.resize(n);
		sz.resize(n, 1);
	}

	int get_root(int v, int &val) {
		while (p[v] != v) {
			val ^= off[v];
			v = p[v];
		}
		return v;
	}

	int join(int u, int v) {
		// cerr << "=====join " << u << " " << v << endl;
		int val_u = 0, val_v = 0;
		u = get_root(u, val_u);
		v = get_root(v, val_v);
		if (u == v) {
			return (val_u == val_v);
		}
		if (sz[u] > sz[v]) {
			swap(u, v);
			swap(val_u, val_v);
		}
		int xr = (val_u ^ val_v ^ 1);
		st.emplace_back(u, xr);
		// cerr << "success " << u << " " << v << endl;
		p[u] = v;
		off[u] ^= xr;
		sz[v] += sz[u];
		return 0;
	}

	void roll_back(int target_sz) {
		while (st.size() > target_sz) {
			pair<int, int> pp = st.back();
			st.pop_back();
			int u = pp.first, v = p[u];
			// cerr << "=====remove " << u << " " << v << endl;
			sz[v] -= sz[u];
			p[u] = u;
			off[u] ^= pp.second;
		}
		// output(all(p));
		// output(all(sz));
		// output(all(off));
	}
};

dsu T;

const int mx = 2e5 + 228;
int n, m, q, L[mx];
vector<pair<int, int> > e;

void read() {
	cin >> n >> m >> q;
	e.resize(m);
	for (int i = 0; i < m; ++i) {
		cin >> e[i].first >> e[i].second;
		e[i].first--;
		e[i].second--;
	}
}

void go(int l, int r, int res_l, int res_r) {
	if (l > r) {
		return;
	}
	// cerr << "go " << l << " " << r << " " << res_l << " " << res_r << endl;
	int mid = (l + r) >> 1, init_state = T.st.size(), bad = 0, res_mid;
	for (int i = l; i < mid; ++i) {
		if (T.join(e[i].first, e[i].second)) {
			bad = 1;
		}
	}
	if (bad) {
		res_mid = res_r;
	} else {
		res_mid = max(res_l, mid);
		for (int i = res_r - 1; i >= max(res_l, mid); --i) {
			if (T.join(e[i].first, e[i].second)) {
				// cerr << "sas " << i << endl;
				res_mid = i;
				break;
			}
		}
	}
	T.roll_back(init_state);

	bad = 0;
	for (int i = res_r - 1; i >= res_mid; --i) {
		if (T.join(e[i].first, e[i].second)) {
			bad = 1;
		}
	}
	L[mid] = res_mid;
	// cerr << "mid = " << mid << endl;
	// cerr << "res_mid = " << res_mid << endl;
	if (bad) {
		for (int i = l; i < mid; ++i) {
			L[i] = res_mid;
		}
	} else {
		go(l, mid - 1, res_l, res_mid);
	}
	T.roll_back(init_state);
	bad = 0;
	for (int i = l; i <= mid; ++i) {
		if (T.join(e[i].first, e[i].second)) {
			bad = 1;
		}
	}
	if (bad) {
		for (int i = mid + 1; i <= r; ++i) {
			L[i] = res_r;
		}
	} else {
		go(mid + 1, r, res_mid, res_r);
	}
	T.roll_back(init_state);
	// cerr << "return" << endl;
}

void process_queries() {
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		cout << (L[l] > r ? "YES" : "NO") << '\n';
	}
}

signed main() {
	fast_io();
	read();
	T.init(n);
	go(0, m - 1, 0, m);
	// output(L, L + m);
	process_queries();
}