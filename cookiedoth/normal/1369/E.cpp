/*

Code for problem E by cookiedoth
Generated 23 Jun 2020 at 05.43 PM



10%

30%

50%

70%

100%

-_-
z_z
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

const int mx = 1e5 + 228;
int n, m, w[mx], used[mx];
vector<vector<pair<int, int> > > g;
vector<int> order;

void dfs(int v) {
	used[v] = 1;
	for (auto pp : g[v]) {
		int v1 = pp.first;
		int en = pp.second;
		if (used[v1] == 0) {
			order.push_back(en);
			w[v1]++;
			w[v]++;
		}
	}
	for (auto pp : g[v]) {
		int v1 = pp.first;
		if (used[v1] == 0 && w[v1] >= 0) {
			dfs(v1);
		}
	}
}

signed main() {
	fast_io();
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
	}
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].emplace_back(v, i);
		g[v].emplace_back(u, i);
		w[u]--;
		w[v]--;
	}
	for (int i = 0; i < n; ++i) {
		if (w[i] >= 0 && used[i] == 0) {
			dfs(i);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (used[i] == 0) {
			cout << "DEAD" << endl;
			exit(0);
		}
	}
	cout << "ALIVE" << endl;
	reverse(all(order));
	for (auto x : order) {
		cout << x + 1 << " ";
	}
	cout << endl;
}