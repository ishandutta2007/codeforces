/*

Code for problem B by cookiedoth
Generated 27 Nov 2019 at 09.32 P










(@)(@)(@)(@)(@)

\_()_/
o_O
-_-

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

struct st {
	st() {}
	int n;
	vector<int> t;

	void init(int _n) {
		n = 1;
		while (n < _n) {
			n <<= 1;
		}
		t.resize(2 * n);
	}

	void add(int pos) {
		pos += n;
		while (pos) {
			t[pos]++;
			pos >>= 1;
		}
	}

	int get(int cnt, int v, int tl, int tr) {
		if (tl == tr) {
			return tl;
		}
		int tm = (tl + tr) >> 1;
		if (t[v * 2] > cnt) {
			return get(cnt, v * 2, tl, tm);
		} else {
			return get(cnt - t[v * 2], v * 2 + 1, tm + 1, tr);
		}
	}

	int get(int cnt) {
		int res = get(cnt, 1, 0, n - 1);
		return res;
	}
};

const int mx = 2e5 + 228;
int n, q, ans[mx], a[mx];
vector<pair<int, int> > vp;
vector<vector<pair<int, int> > > Q;

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		vp.emplace_back(-a[i], i);
	}
	sort(all(vp));
	cin >> q;
	Q.resize(n + 1);
	for (int i = 0; i < q; ++i) {
		int k, pos;
		cin >> k >> pos;
		pos--;
		Q[k].emplace_back(pos, i);
	}
	st t;
	t.init(n);
	for (int i = 0; i < n; ++i) {
		t.add(vp[i].second);
		for (auto pp : Q[i + 1]) {
			ans[pp.second] = a[t.get(pp.first)];
		}
	}
	output(ans, ans + q, cout);
}