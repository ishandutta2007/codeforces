/*

Code for problem F by cookiedoth
Generated 24 Jun 2020 at 07.08 PM


  !











>_<
o_O
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

const int mx = 1010;
int n;
vector<vector<int> > g;

#ifndef TESTING
pair<int, int> ask(const vector<int> &v) {
	cout << "? " << v.size();
	for (auto x : v) {
		cout << " " << x + 1;
	}
	cout << endl;
	int x, d;
	cin >> x >> d;
	x--;
	return {x, d};
}

void guess(int v1, int v2) {
	cout << "! " << v1 + 1 << " " << v2 + 1 << endl;
	string res;
	cin >> res;
	assert(res == "Correct");
}
#else
const int INF = 1e9;
int d[mx][mx], _v1, _v2;
mt19937 rng(58);

pair<int, int> ask(vector<int> &v) {
	shuffle(all(v), rng);
	int opt = -1, best = INF;
	for (auto x : v) {
		if (chkmin(best, d[x][_v1] + d[x][_v2])) {
			opt = x;
		}
	}
	cerr << "ask" << endl;
	output(all(v));
	cerr << opt << " " << best << endl;
	return {opt, best};
}

void guess(int v1, int v2) {
	if (v1 > v2) {
		swap(v1, v2);
	}
	assert(v1 == _v1 && v2 == _v2);
	cerr << "Correct" << endl;
}

void gen_test() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			d[i][j] = INF;
		}
	}
	for (int i = 0; i < n; ++i) {
		d[i][i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		for (auto v : g[i]) {
			d[i][v] = 1;
		}
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				chkmin(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	while (true) {
		_v1 = rng() % n;
		_v2 = rng() % n;
		if (_v1 < _v2) {
			break;
		}
	}
	cerr << "got " << _v1 << " " << _v2 << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cerr << d[i][j] << " ";
		}
		cerr << endl;
	}
}
#endif

int root, path_len, h[mx], sub[mx], fs, max_h;

void read() {
	cin >> n;
	g.assign(n, vector<int> ());
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

void first_query() {
	vector<int> allV(n);
	iota(all(allV), 0);
	pair<int, int> pp = ask(allV);
	root = pp.first;
	path_len = pp.second;
}

void dfs(int v, int pv) {
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			h[v1] = h[v] + 1;
			sub[v1] = (v == pv ? v1 : sub[v]);
			dfs(v1, v);
		}
	}
}

void hang() {
	h[root] = 0;
	sub[root] = -1;
	dfs(root, root);
	int pos = (max_element(h, h + n) - h);
	fs = sub[pos];
	max_h = 0;
	for (int i = 0; i < n; ++i) {
		if (sub[i] != fs) {
			chkmax(max_h, h[i]);
		}
	}
}

int v1;

void binsearch() {
	int l = 0, r = max_h;
	v1 = root;
	while (l < r) {
		int mid = (l + r) >> 1;
		vector<int> to_ask;
		for (int i = 0; i < n; ++i) {
			if (sub[i] != fs && h[i] > mid) {
				to_ask.push_back(i);
			}
		}
		pair<int, int> pp = ask(to_ask);
		if (pp.second == path_len) {
			v1 = pp.first;
			l = mid + 1;
		} else {
			r = mid;
		}
	}
}

int v2;

void determine_v2() {
	int target_h = path_len - h[v1];
	vector<int> to_ask;
	for (int i = 0; i < n; ++i) {
		if (sub[i] != sub[v1] && h[i] == target_h) {
			to_ask.push_back(i);
		}
	}
	pair<int, int> pp = ask(to_ask);
	v2 = pp.first;
}

void solve() {
	read();
	#ifdef TESTING
	gen_test();
	#endif
	first_query();
	hang();
	binsearch();
	determine_v2();
	guess(v1, v2);
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}