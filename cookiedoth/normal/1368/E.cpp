/*

Code for problem E by cookiedoth
Generated 18 Jun 2020 at 06.24 PM










(@)(@)(@)(@)(@)

o_O
-_-
z_z

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

const int mx = 2e5 + 228;
int n, m, clr[mx];
vector<vector<int> > g, rev_g;

void paint0(int v) {
	clr[v] = 0;
	for (auto v1 : g[v]) {
		if (clr[v1] == -1) {
			clr[v1] = 1;
		}
	}
}

void solve() {
	vector<pair<int, int> > e;
	cin >> n >> m;
	g.assign(n, vector<int> ());
	rev_g.assign(n, vector<int> ());
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		rev_g[v].push_back(u);
		e.emplace_back(u, v);
	}
	for (int i = 0; i < n; ++i) {
		sort(all(g[i]));
	}
	fill(clr, clr + n, -1);
	for (int i = 0; i < n; ++i) {
		int bad = 0;
		for (auto v : rev_g[i]) {
			if (clr[v] == 1) {
				bad = 1;
			}
		}
		if (!bad) {
			if (clr[i] == -1) {
				paint0(i);
			}
		} else {
			clr[i] = 2;
		}
	}
	// output(clr, clr + n);
	vector<int> to_close;
	for (int i = 0; i < n; ++i) {
		if (clr[i] == 2) {
			to_close.push_back(i);
		}
	}
	// assert(to_close.size() * 7 <= 4 * n);
	// for (auto pp : e) {
	// 	if (clr[pp.first] != 2 && clr[pp.second] != 2) {
	// 		assert(clr[pp.first] == 0);
	// 		assert(clr[pp.second] == 1);
	// 	}
	// }
	cout << to_close.size() << '\n';
	for (auto x : to_close) {
		cout << x + 1 << " ";
	}
	cout << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}