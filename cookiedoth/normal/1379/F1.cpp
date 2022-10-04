/*

Code for problem F by cookiedoth
Generated 20 Jul 2020 at 04.53 PM



10%

30%

50%

70%

100%

-_-
z_z
=_=

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

struct node {
	int maxL, minR, bad;

	node(): maxL(-INF), minR(INF), bad(0) {}
	node(int _maxL, int _minR): maxL(_maxL), minR(_minR), bad(_maxL > minR) {}
};

node combine(const node &a, const node &b) {
	node res;
	res.maxL = max(a.maxL, b.maxL);
	res.minR = min(a.minR, b.minR);
	res.bad = (a.bad | b.bad | a.minR < b.maxL);
	return res;
}

struct st {
	st() {}

	vector<node> t;
	int n;

	void init(int _n) {
		n = _n;
		t.resize(4 * n);
	}

	void update(int pos, node val, int v, int tl, int tr) {
		if (tl == tr) {
			t[v] = val;
		} else {
			int tm = (tl + tr) >> 1;
			if (pos <= tm) {
				update(pos, val, v * 2, tl, tm);
			} else {
				update(pos, val, v * 2 + 1, tm + 1, tr);
			}
			t[v] = combine(t[v * 2], t[v * 2 + 1]);
		}
	}

	int update(int pos, node val) {
		update(pos, val, 1, 0, n - 1);
		return (1 ^ t[1].bad);
	}
};

int n, m, q;
vector<set<int> > onlyL, onlyR;
st T;

void flip_cell(int r, int c) {
	int r1 = r / 2;
	int c1 = c / 2;
	if (r % 2 == 0) {
		if (onlyR[r1].find(c1) == onlyR[r1].end()) {
			onlyR[r1].insert(c1);
		} else {
			onlyR[r1].erase(c1);
		}
	} else {
		if (onlyL[r1].find(c1) == onlyL[r1].end()) {
			onlyL[r1].insert(c1);
		} else {
			onlyL[r1].erase(c1);
		}
	}
}

int update_ST(int r) {
	// cerr << "update_ST " << r << endl;
	int maxL = (onlyL[r].empty() ? -INF : (*prev(onlyL[r].end()))) + 1;
	int minR = (onlyR[r].empty() ? INF : (*onlyR[r].begin()));
	// cerr << "maxL = " << maxL << endl;
	// cerr << "minR = " << minR << endl;
	int res = T.update(r, node(maxL, minR));
	return res;
}

int query(int r, int c) {
	flip_cell(r, c);
	// cerr << "flip_cell " << r << " " << c << endl;
	return update_ST(r / 2);
}

void process_queries() {
	T.init(n);
	onlyL.resize(n);
	onlyR.resize(n);
	for (int i = 0; i < q; ++i) {
		int r, c;
		cin >> r >> c;
		r--;
		c--;
		// cerr << "query " << r << " " << c << endl;
		int res = query(r, c);
		cout << (res ? "YES" : "NO") << '\n';
	}
}

signed main() {
	fast_io();
	cin >> n >> m >> q;
	process_queries();
}