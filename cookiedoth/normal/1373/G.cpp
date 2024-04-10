/*

Code for problem G by cookiedoth
Generated 25 Jun 2020 at 06.55 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

\_()_/
^_^
~_^

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
#define sz(a) (int)a.size()

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

const int INF = 1e9;

struct st {
	vector<int> t, mod;
	int n;

	st(int _n) {
		n = _n;
		t.resize(4 * n);
		mod.resize(4 * n);
	}

	void update(int l, int r, int val, int v, int tl, int tr) {
		if (r < tl || tr < l) {
			return;
		}
		if (l <= tl && tr <= r) {
			mod[v] += val;
			t[v] += val;
		} else {
			int tm = (tl + tr) >> 1;
			update(l, r, val, v * 2, tl, tm);
			update(l, r, val, v * 2 + 1, tm + 1, tr);
			t[v] = max(t[v * 2], t[v * 2 + 1]) + mod[v];
		}
	}

	void update(int l, int r, int val) {
		update(l, r, val, 1, 0, n - 1);
	}

	int get(int l, int r, int v, int tl, int tr) {
		if (r < tl || tr < l) {
			return -INF;
		}
		if (l <= tl && tr <= r) {
			return t[v];
		} else {
			int tm = (tl + tr) >> 1;
			int res_l = get(l, r, v * 2, tl, tm);
			int res_r = get(l, r, v * 2 + 1, tm + 1, tr);
			return max(res_l, res_r) + mod[v];
		}
	}

	int get(int l, int r) {
		int res = get(l, r, 1, 0, n - 1);
		return res;
	}
};

int n, m, k;

void process() {
	cin >> n >> k >> m;
	int TS = 2 * n;
	k--;
	st T(TS);
	for (int i = 0; i < TS; ++i) {
		T.update(i, i, -(TS - i));
	}
	set<pair<int, int> > used;
	multiset<int> ds;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		int d = y + abs(x - k);
		int delta = 0;
		if (used.find({x, y}) == used.end()) {
			delta = 1;
			used.insert({x, y});
			ds.insert(d);
		} else {
			delta = -1;
			used.erase({x, y});
			ds.erase(ds.find(d));
		}
		// cerr << "d = " << d << endl;
		// cerr << "delta = " << delta << endl;
		T.update(0, d, delta);
		if (ds.empty()) {
			cout << 0 << '\n';
		} else {
			int rpos = (*prev(ds.end()));
			// cerr << "rpos = " << rpos << endl;
			int val = T.get(0, rpos);
			// cerr << "val = " << val << endl;
			int level = max(rpos + 1, 2 * n + val);
			cout << max(0, level - n) << '\n';
		}
	}
}

signed main() {
	fast_io();
	process();
}