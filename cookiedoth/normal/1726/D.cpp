/*

Code for problem D by cookiedoth
Generated 06 Sep 2022 at 10.55 AM
The Moon is Waxing Gibbous (81% of Full)


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

z_z
>_<
o_O

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
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
#include <array>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define length(a) (int)a.size()

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

const int MAX_N = 2e5 + 228;
bool used[MAX_N];
int n, m, par[MAX_N], h[MAX_N];
vector<vector<int>> g;
vector<pair<int, int>> out_edges, blue_edges, e;

void dfs(int v, int pv) {
	par[v] = pv;
	used[v] = true;
	for (auto v1 : g[v]) {
		if (!used[v1]) {
			h[v1] = h[v] + 1;
			dfs(v1, v);
		} else {
			if (v1 != pv && h[v1] < h[v]) {
				out_edges.push_back({v, v1});
			}
		}
	}
}

void read() {
	cin >> n >> m;
	g.assign(n, vector<int>());
	e.clear();
	out_edges.clear();
	blue_edges.clear();
	fill(used, used + n, false);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
		e.emplace_back(u, v);
	}
}

void process() {
	if (out_edges.size() < 3) {
		blue_edges = out_edges;
		return;
	}
	set<int> outv;
	for (auto [u, v] : out_edges) {
		outv.insert(u);
		outv.insert(v);
	}
	if (outv.size() != 3) {
		blue_edges = out_edges;
		return;
	}
	vector<int> outv_vec(all(outv));
	sort(all(outv_vec), [] (int u, int v) { return h[u] < h[v]; });
	for (auto [u, v] : out_edges) {
		if (u == outv_vec[1] || v == outv_vec[1]) {
			blue_edges.emplace_back(u, v);
		}
	}
	blue_edges.emplace_back(outv_vec[1], par[outv_vec[1]]);
}

void print_ans() {
	for (int i = 0; i < m; ++i) {
		bool is_blue = false;
		for (auto [u, v] : blue_edges) {
			if ((e[i].first == u && e[i].second == v) || (e[i].first == v && e[i].second == u)) {
				is_blue = true;
			}
		}
		cout << is_blue;
	}
	cout << '\n';
}

void solve() {
	read();
	dfs(0, 0);
	process();
	print_ans();
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}