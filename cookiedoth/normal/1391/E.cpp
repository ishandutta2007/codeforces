/*

Code for problem E by cookiedoth
Generated 10 Aug 2020 at 05.38 PM










(@)(@)(@)(@)(@)

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

const int mx = 5e5 + 228;
int n, m, used[mx], par[mx], h[mx];
vector<vector<int> > g, H;

void read() {
	cin >> n >> m;
	g.assign(n, vector<int> ());
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

void dfs(int v) {
	used[v] = 1;
	for (auto v1 : g[v]) {
		if (used[v1] == 0) {
			par[v1] = v;
			h[v1] = h[v] + 1;
			dfs(v1);
		}
	}
}

int find_path() {
	for (int i = 0; i < n; ++i) {
		if (2 * (h[i] + 1) >= n) {
			vector<int> path;
			int v = i;
			while (true) {
				path.push_back(v);
				if (v == 0) {
					break;
				}
				v = par[v];
			}
			cout << "PATH\n";
			cout << path.size() << '\n';
			for (auto v1 : path) {
				cout << v1 + 1 << ' ';
			}
			cout << '\n';
			return 1;
		}
	}
	return 0;
}

void find_pairing() {
	H.assign(n, vector<int> ());
	for (int i = 0; i < n; ++i) {
		H[h[i]].push_back(i);
	}
	vector<pair<int, int> > out;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j + 1 < H[i].size(); j += 2) {
			out.emplace_back(H[i][j], H[i][j + 1]);
		}
	}
	cout << "PAIRING\n";
	cout << out.size() << '\n';
	for (auto pp : out) {
		cout << pp.first + 1 << ' ' << pp.second + 1 << '\n';
	}
}

void solve() {
	read();
	fill(used, used + n, 0);
	dfs(0);
	if (find_path()) {
		return;
	}
	find_pairing();
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}

}