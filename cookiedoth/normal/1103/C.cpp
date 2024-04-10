/*

Code for problem C by savkinsd2089
Generated 22 Jan 2019 at 05.29 pm
The Moon is Waning Gibbous (97% of Full)


 ] 
 
Il] 


-_-
^_^
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
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)

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

const int N = 25e4 + 228;
int n, m, k, used[N], h[N], p[N];
vector<int> g[N], children[N];

void dfs(int v) {
	used[v] = 1;
	for (auto v1 : g[v]) {
		if (used[v1] == 0) {
			children[v].push_back(v1);
			p[v1] = v;
			h[v1] = h[v] + 1;
			dfs(v1);
		}
	}
}

vector<vector<int> > cycles;

void push_cycle(int u, int v, vector<int> &a) {
	while (u != v) {
		a.push_back(u);
		u = p[u];
	}
	a.push_back(u);
}

void add_cycle(int u, int v) {
	vector<int> a;
	push_cycle(u, v, a);
	cycles.push_back(a);
}

void cycle_dfs(int v) {
	if (children[v].size() == 0) {
		vector<int> up;
		for (auto v1 : g[v]) {
			if (p[v1] != v && p[v] != v1) {
				up.push_back(v1);
			}
		}

		if (up.size() == 1) {
			int up_v = up[0];
			if ((h[v] - h[up_v] + 1) % 3 != 0) {
				add_cycle(v, up_v);
			}
		}
		else {
			int ok = 0;
			for (auto up_v : up) {
				if ((h[v] - h[up_v] + 1) % 3 != 0) {
					add_cycle(v, up_v);
					ok = 1;
					break;
				}
			}

			if (!ok) {
				vector<int> a = {v};
				int v1 = up[0], v2 = up[1];
				if (h[v1] < h[v2]) {
					swap(v1, v2);
				}
				push_cycle(v1, v2, a);
				cycles.push_back(a);
			}
		}
	}

	for (auto v1 : children[v]) {
		cycle_dfs(v1);
	}
}

signed main() {
	fast_io();
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(0);

	int path_len = (n + k - 1) / k;
	for (int i = 0; i < n; ++i) {
		if (h[i] >= path_len) {
			vector<int> path;
			int v = i;
			for (int j = 0; j < path_len; ++j) {
				path.push_back(v);
				v = p[v];
			}
			cout << "PATH\n";
			cout << path_len << "\n";
			for (auto x : path) {
				cout << x + 1 << " ";
			}
			cout << "\n";
			exit(0);
		}
	}

	cycle_dfs(0);
	if (cycles.size() < k) {
		assert(0);
	}

	cout << "CYCLES" << endl;
	for (int i = 0; i < k; ++i) {
		cout << cycles[i].size() << endl;
		for (auto v : cycles[i]) {
			cout << v + 1 << " ";
		}
		cout << endl;
	}
}