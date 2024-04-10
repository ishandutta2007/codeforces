/*

Code for problem E by cookiedoth
Generated 27 Jul 2020 at 02.43 PM


  !











>_<
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
	int v, used, fake;
};

int n, m;
vector<edge> e;
vector<vector<int> > g;

void add_edge(int u, int v, int fake) {
	g[u].push_back(e.size());
	e.push_back({v, 0, fake});
	g[v].push_back(e.size());
	e.push_back({u, 0, fake});
}

vector<int> ptr, cycle;

void dfs(int v) {
	while (ptr[v] < g[v].size()) {
		int en = g[v][ptr[v]++];
		if (e[en].used == 0) {
			e[en].used = 1;
			e[en ^ 1].used = 1;
			dfs(e[en].v);
			cycle.push_back(en);
		}
	}
}

void solve() {
	cin >> n >> m;
	g.assign(n, vector<int> ());
	e.clear();
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		add_edge(u, v, 0);
	}
	vector<int> odd;
	for (int i = 0; i < n; ++i) {
		if (g[i].size() % 2 == 1) {
			odd.push_back(i);
		}
	}
	for (int i = 0; i < odd.size(); i += 2) {
		add_edge(odd[i], odd[i + 1], 1);
	}
	ptr.assign(n, 0);
	cout << n - odd.size() << '\n';
	for (int i = 0; i < n; ++i) {
		if (ptr[i] < g[i].size()) {
			cycle.clear();
			dfs(i);
			for (auto en : cycle) {
				en ^= 1;
				if (e[en].fake == 0) {
					cout << e[en ^ 1].v + 1 << ' ' << e[en].v + 1 << '\n';
				}
			}
		}
	}
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}