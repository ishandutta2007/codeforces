/*

Code for problem C by cookiedoth
Generated 04 Jun 2020 at 06.09 PM


  !











^_^
~_^
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

struct edge {
	int v, used;
	edge(int _v, int _used): v(_v), used(_used) {}
};

const int mx = 5e5 + 228;
const int C = 20;
int n, V, a[mx], b[mx];
vector<int> euler, ptr;
vector<edge> e;
vector<vector<int> > g;

void add_edge(int u, int v) {
	g[u].emplace_back(e.size());
	e.emplace_back(v, 0);
	g[v].emplace_back(e.size());
	e.emplace_back(u, 0);
}

void build_graph(int bits) {
	V = (1 << bits);
	int mask = (V - 1);
	euler.clear();
	e.clear();
	g.assign(V, vector<int> ());
	ptr.assign(V, 0);
	for (int i = 0; i < n; ++i) {
		add_edge(a[i] & mask, b[i] & mask);
	}
}

void dfs(int v) {
	while (ptr[v] < g[v].size()) {
		int en = g[v][ptr[v]++];
		if (e[en].used == 0) {
			e[en].used = 1;
			e[en ^ 1].used = 1;
			dfs(e[en].v);
			euler.push_back(en);
		}
	}
}

int check(int bits) {
	build_graph(bits);
	for (int i = 0; i < V; ++i) {
		if (g[i].size() % 2) {
			return 0;
		}
	}
	for (int i = 0; i < V; ++i) {
		if (!g[i].empty()) {
			dfs(i);
			if (euler.size() != n) {
				return 0;
			} else {
				return 1;
			}
		}
	}
	assert(0);
}

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}
	int l = 0, r = C;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid + 1)) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	check(l);
	cout << l << endl;
	// reverse(all(euler));
	// output(all(euler));
	for (auto x : euler) {
		int base = (x / 2) * 2;
		if (x % 2 == 0) {
			cout << base + 2 << " " << base + 1 << " ";
		} else {
			cout << base + 1 << " " << base + 2 << " ";
		}
	}
	cout << endl;
}