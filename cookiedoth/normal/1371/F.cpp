/*

Code for problem F by cookiedoth
Generated 01 Jul 2020 at 04.49 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

=_=
\_()_/
o_O

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

struct node {
	int len = 0, max_01 = 0, max_10 = 0;
	int lc = 0, lc_len = 0, lc_len2 = 0;
	int rc = 0, rc_len = 0, rc_len2 = 0;
	int mod = 0;

	node() {}

	node(int c): len(1), lc(c), lc_len(1), rc(c), rc_len(1) {}

	void flip() {
		swap(max_01, max_10);
		lc ^= 1;
		rc ^= 1;
	}

	void print() {
		cerr << "printing node " << len << endl;
		cerr << max_01 << " " << max_10 << endl;
		cerr << lc << " " << lc_len << " " << lc_len2 << endl;
		cerr << rc << " " << rc_len << " " << rc_len2 << endl;
		cerr << "mod = " << mod << endl;
	}
};

node merge(node a, node b) {
	// cerr << "merging=============" << endl;
	// a.print();
	// b.print();
	if (a.mod) {
		a.flip();
	}
	if (b.mod) {
		b.flip();
	}
	node res;
	res.len = a.len + b.len;
	res.max_01 = max(a.max_01, b.max_01);
	res.max_10 = max(a.max_10, b.max_10);
	if (a.rc == 0 && b.lc == 1) {
		chkmax(res.max_01, a.rc_len + b.lc_len);
	}
	if (a.rc == 1 && b.lc == 0) {
		chkmax(res.max_10, a.rc_len + b.lc_len);
	}
	if (a.rc == 0 && b.lc == 0) {
		chkmax(res.max_01, a.rc_len + b.lc_len + b.lc_len2);
		chkmax(res.max_10, a.rc_len2 + a.rc_len + b.lc_len);
	}
	if (a.rc == 1 && b.lc == 1) {
		chkmax(res.max_01, a.rc_len2 + a.rc_len + b.lc_len);
		chkmax(res.max_10, a.rc_len + b.lc_len + b.lc_len2);
	}
	res.lc = a.lc;
	if (a.lc_len == a.len) {
		if (b.lc == a.lc) {
			res.lc_len = a.len + b.lc_len;
			res.lc_len2 = b.lc_len2;
		} else {
			res.lc_len = a.len;
			res.lc_len2 = b.lc_len;
		}
	} else {
		res.lc_len = a.lc_len;
		res.lc_len2 = a.lc_len2;
		if (a.lc_len + a.lc_len2 == a.len && b.lc == a.rc) {
			res.lc_len2 += b.lc_len;
		}
	}
	res.rc = b.rc;
	if (b.rc_len == b.len) {
		if (b.rc == a.rc) {
			res.rc_len = b.len + a.rc_len;
			res.rc_len2 = a.rc_len2;
		} else {
			res.rc_len = b.len;
			res.rc_len2 = a.rc_len;
		}
	} else {
		res.rc_len = b.rc_len;
		res.rc_len2 = b.rc_len2;
		if (b.rc_len + b.rc_len2 == b.len && a.rc == b.lc) {
			res.rc_len2 += a.rc_len;
		}
	}
	// res.print();
	return res;
}

struct st {
	vector<node> t;
	int n;

	st() {}

	void build(const vector<int> &a, int v, int tl, int tr) {
		if (tl == tr) {
			t[v] = node(a[tl]);
		} else {
			int tm = (tl + tr) >> 1;
			build(a, v * 2, tl, tm);
			build(a, v * 2 + 1, tm + 1, tr);
			t[v] = merge(t[v * 2], t[v * 2 + 1]);
		}
	}

	void build(const vector<int> &a) {
		n = a.size();
		t.resize(4 * n);
		build(a, 1, 0, n - 1);
	}

	void push(int v, int tl, int tr) {
		if (t[v].mod) {
			t[v].flip();
			t[v].mod = 0;
			if (tl != tr) {
				t[v * 2].mod ^= 1;
				t[v * 2 + 1].mod ^= 1;
			}
		}
	}

	void update(int l, int r, int v, int tl, int tr) {
		if (r < tl || tr < l) {
			return;
		}
		if (l <= tl && tr <= r) {
			t[v].mod ^= 1;
			push(v, tl, tr);
		} else {
			int tm = (tl + tr) >> 1;
			push(v, tl, tr);
			update(l, r, v * 2, tl, tm);
			update(l, r, v * 2 + 1, tm + 1, tr);
			t[v] = merge(t[v * 2], t[v * 2 + 1]);
		}
	}

	void flip(int l, int r) {
		update(l, r, 1, 0, n - 1);
	}

	node get(int l, int r, int v, int tl, int tr) {
		if (r < tl || tr < l) {
			return node();
		}
		push(v, tl, tr);
		if (l <= tl && tr <= r) {
			return t[v];
		} else {
			int tm = (tl + tr) >> 1;
			node res_l = get(l, r, v * 2, tl, tm);
			node res_r = get(l, r, v * 2 + 1, tm + 1, tr);
			return merge(res_l, res_r);
		}
	}

	int get(int l, int r) {
		node res = get(l, r, 1, 0, n - 1);
		return max(res.max_10, max(res.lc_len, res.rc_len));
	}
};

int n, q;
st T;

void read() {
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = (s[i] == '<' ? 0 : 1);
	}
	T.build(a);
}

int query(int l, int r) {
	T.flip(l, r);
	int res = T.get(l, r);
	return res;
}

void process_queries() {
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		int res = query(l, r);
		cout << res << '\n';
	}
}

signed main() {
	fast_io();
	read();
	process_queries();
}