/*

Code for problem D by cookiedoth
Generated 26 Jul 2020 at 04.37 PM


  !
 
                                    
                          
                  




















o_O
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

const int mx = 1e5 + 228;
int n, a, b, down_d[mx], down_d2[mx], up_d[mx], pivot;
vector<vector<int> > g, children;

void dfs1(int v, int pv) {
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			children[v].push_back(v1);
			dfs1(v1, v);
			int t = down_d[v1] + 1;
			if (t > down_d[v]) {
				down_d2[v] = down_d[v];
				down_d[v] = t;
			} else {
				chkmax(down_d2[v], t);
			}
		}
	}
}

void dfs2(int v, int pv) {
	if (v) {
		up_d[v] = up_d[pv] + 1;
		chkmax(up_d[v], down_d[v] + 1 == down_d[pv] ? down_d2[pv] + 1 : down_d[pv] + 1);
	}
	for (auto v1 : children[v]) {
		dfs2(v1, v);
	}
}

void read() {
	cin >> n >> a >> b;
	a--;
	b--;
	g.assign(n, vector<int> ());
	children.assign(n, vector<int> ());
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	fill(down_d, down_d + n, 0);
	fill(down_d2, down_d2 + n, 0);
	dfs1(0, 0);
	// cerr << "dfs1" << endl;
	dfs2(0, 0);
}

int L;

int find_path(int v, int pv, int to) {
	// cerr << "v = " << v << endl;
	// cerr << g.size() << endl;
	if (v == to) {
		return 0;
	}
	for (auto v1 : g[v]) {
		// cerr << "v1 = " << v1 << endl;
		if (v1 != pv) {
			int d = find_path(v1, v, to);
			if (d != -1) {
				return d + 1;
			}
		}
	}
	return -1;
}

int distance(int u, int v) {
	return find_path(u, u, v);
}

void find_pivot() {
	L = distance(a, b);
	// cerr << "L = " << L << endl;
	pivot = -1;
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (auto v1 : children[i]) {
			if (down_d[v1] + 1 >= L) {
				cnt++;
			}
		}
		if (up_d[i] >= L) {
			cnt++;
		}
		// cerr << "cnt = " << cnt << endl;
		if (cnt >= 3) {
			pivot = i;
		}
	}
	// cerr << "done" << endl;
}

int h[mx], leaf[mx], par[mx];

void dfs3(int v, int pv) {
	par[v] = pv;
	leaf[v] = v;
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			h[v1] = h[v] + 1;
			dfs3(v1, v);
			if (h[leaf[v1]] > h[leaf[v]]) {
				leaf[v] = leaf[v1];
			}
		}
	}
}

int cv[mx], clr;

int lca(int u, int v) {
	clr++;
	while (true) {
		cv[u] = clr;
		if (par[u] == u) {
			break;
		}
		u = par[u];
	}
	while (cv[v] != clr) {
		v = par[v];
	}
	return v;
}

void process() {
	// cerr << "process" << endl;
	h[pivot] = pivot;
	dfs3(pivot, pivot);
	int e = lca(a, b);
	set<pair<int, int> > used;
	while (true) {
		// cerr << "ab = " << a << " " << b << endl;
		if (used.find({a, b}) != used.end()) {
			cout << "NO\n";
			return;
		}
		used.insert({a, b});
		int a1 = leaf[a];
		int delta = h[a1] - h[a];
		int deltaL = h[a1] - h[e];
		if (deltaL >= L) {
			cout << "YES\n";
			return;
		}
		for (int it = 0; it < delta; ++it) {
			b = par[b];
		}
		a = a1;
		swap(a, b);
	}
}

void solve() {
	read();
	// cerr << "read" << endl;
	find_pivot();
	if (pivot == -1) {
		cout << "NO\n";
		return;
	}
	process();
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}