/*

Code for problem H by cookiedoth
Generated 13 Jan 2020 at 11.05 P


  !











~_^
=_=
>_<

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

struct st {
	int n;
	vector<pair<int, int> > t;
	vector<int> mod;

	void init(int _n) {
		n = _n;
		t.resize(4 * n);
		mod.resize(4 * n);
	}

	pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) {
			return {a.first, a.second + b.second};
		} else {
			return min(a, b);
		}
	}

	void recalc(int v) {
		t[v] = merge(t[v * 2], t[v * 2 + 1]);
		t[v].first += mod[v];
	}

	void add(int l, int r, int val, int v, int tl, int tr) {
		if (l > r) {
			return;
		}
		if (l == tl && r == tr) {
			mod[v] += val;
			t[v].first += val;
		} else {
			int tm = (tl + tr) >> 1;
			add(l, min(r, tm), val, v * 2, tl, tm);
			add(max(l, tm + 1), r, val, v * 2 + 1, tm + 1, tr);
			recalc(v);
		}
	}

	void add(int l, int r, int val) {
		add(l, r, val, 1, 0, n - 1);
	}

	void change(int pos, int val, int v, int tl, int tr) {
		if (tl == tr) {
			t[v].second = val;
		} else {
			int tm = (tl + tr) >> 1;
			if (pos <= tm) {
				change(pos, val, v * 2, tl, tm);
			} else {
				change(pos, val, v * 2 + 1, tm + 1, tr);
			}
			recalc(v);
		}
	}

	void activate(int pos) {
		change(pos, 1, 1, 0, n - 1);
	}

	void deactivate(int pos) {
		change(pos, 0, 1, 0, n - 1);
	}

	int get() {
		int res = (t[1].first == 1 ? t[1].second : 0);
		return res;
	}
};

const int mx = 5e5 + 228;
const int MX = 1e6 + 228;
int n, q, a[mx];
st T;

void handle_seg(int x, int y, int c) {
	if (x > y) {
		swap(x, y);
	}
	T.add(x + 1, y, c);
}

signed main() {
	fast_io();
	cin >> n >> q;
	a[0] = MX - 1;
	a[n + 1] = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	T.init(MX);
	for (int i = 1; i <= n; ++i) {
		T.activate(a[i]);
	}
	for (int i = 0; i <= n; ++i) {
		handle_seg(a[i], a[i + 1], 1);
	}
	T.get();
	for (int i = 0; i < q; ++i) {
		int pos, val;
		cin >> pos >> val;
		handle_seg(a[pos - 1], a[pos], -1);
		handle_seg(a[pos], a[pos + 1], -1);
		T.deactivate(a[pos]);
		a[pos] = val;
		handle_seg(a[pos - 1], a[pos], 1);
		handle_seg(a[pos], a[pos + 1], 1);
		T.activate(a[pos]);
		int ans = T.get();
		cout << ans << '\n';
	}
}