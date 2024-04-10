/*

Code for problem B by cookiedoth
Generated 01 Apr 2019 at 08.12 P



10%

30%

50%

70%

100%

=_=
\_()_/
^_^

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

const int NEUTRAL = 1e9;

struct st {
	vector<int> t;
	int n;

	st() {}

	void build(int *a, int v, int tl, int tr) {
		if (tl == tr) {
			t[v] = a[tl];
		}
		else {
			int tm = (tl + tr) >> 1;
			build(a, v * 2, tl, tm);
			build(a, v * 2 + 1, tm + 1, tr);
			t[v] = min(t[v * 2], t[v * 2 + 1]);
		}
	}

	void build(int *a, int _n) {
		n = _n;
		t.resize(4 * n);
		build(a, 1, 0, n - 1);
	}

	int get(int l, int r, int v, int tl, int tr) {
		if (l > r) {
			return NEUTRAL;
		}
		if (l == tl && r == tr) {
			return t[v];
		}
		int tm = (tl + tr) >> 1;
		int res_l = get(l, min(r, tm), v * 2, tl, tm);
		int res_r = get(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
		return min(res_l, res_r);	
	}

	int get(int l, int r) {
		int res = get(l, r, 1, 0, n - 1);
		return res;
	}
};

const int mx = 2e5 + 228;
const int lg = 20;
int n, m, q, p[mx], _p[mx], a[mx], lst[mx], ptr[mx], up[mx][lg], ok_r[mx];

void read_arrays() {
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		p[i]--;
		_p[p[i]] = i;
	}
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
		a[i]--;
		a[i] = _p[a[i]];
	}
}

void calc_r() {
	for (int i = 0; i < n; ++i) {
		lst[i] = m;
	}
	ptr[m] = m;
	for (int i = m - 1; i >= 0; --i) {
		ptr[i] = lst[(a[i] + 1) % n];
		lst[a[i]] = i;
	}
	for (int i = m; i >= 0; --i) {
		up[i][0] = ptr[i];
		for (int j = 1; j < lg; ++j) {
			up[i][j] = up[up[i][j - 1]][j - 1];
		}
		int need = n - 1, pos = i;
		for (int j = lg - 1; j >= 0; --j) {
			if (need >= (1 << j)) {
				pos = up[pos][j];
				need -= (1 << j);
			}
		}
		ok_r[i] = pos;
	}
}

signed main() {
	fast_io();
	cin >> n >> m >> q;

	read_arrays();
	calc_r();

	st t;
	t.build(ok_r, m);
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		int mn = t.get(l, r);
		if (mn <= r) {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	cout << endl;
}