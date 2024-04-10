/*

Code for problem F by cookiedoth
Generated 23 Jan 2020 at 01.46 P



10%

30%

50%

70%

100%

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

const int INF = 1e9;
const int mx = 2e5 + 228;
int n, down_d[mx], up_d[mx], top_ch[mx], top_ch2[mx];
vector<vector<int> > g;

void dfs(int v, int pv) {
	down_d[v] = 0;
	top_ch[v] = -INF;
	top_ch2[v] = -INF;
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			dfs(v1, v);
			chkmax(down_d[v], down_d[v1] + 1);
			if (down_d[v1] > top_ch[v]) {
				top_ch2[v] = top_ch[v];
				top_ch[v] = down_d[v1];
			} else {
				if (down_d[v1] > top_ch2[v]) {
					top_ch2[v] = down_d[v1];
				}
			}
		}
	}
}

int ans = 0, v0 = -1;
vector<int> best;

void dfs2(int v, int pv) {
	if (v == pv) {
		up_d[v] = 0;
	} else {
		up_d[v] = up_d[pv] + 1;
		if (down_d[v] == top_ch[pv]) {
			chkmax(up_d[v], top_ch2[pv] + 2);
		} else {
			chkmax(up_d[v], top_ch[pv] + 2);
		}
	}
	vector<pair<int, int> > keks = {{up_d[v], pv}};
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			dfs2(v1, v);
			keks.emplace_back(down_d[v1] + 1, v1);
		}
	}
	sort(rall(keks));
	if ((int)keks.size() > 3) {
		keks.resize(3);
	}
	int cur = 0;
	for (int i = 0; i < keks.size(); ++i) {
		cur += keks[i].first;
	}
	if (chkmax(ans, cur)) {
		best.clear();
		v0 = v;
		for (int i = 0; i < keks.size(); ++i) {
			best.push_back(keks[i].second);
		}
		// cerr << "v0 = " << v0 << endl;
		// cerr << "best" << endl;
		// output(all(best));
	}
}

pair<int, int> longest_path(int v, int pv) {
	pair<int, int> res = {0, v};
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			pair<int, int> pp = longest_path(v1, v);
			pp.first++;
			chkmax(res, pp);
		}
	}
	return res;
}

int used[mx];
vector<int> out;

void apply(int v) {
	out.push_back(v);
	used[v] = 1;
}

signed main() {
	fast_io();
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, 0);
	dfs2(0, 0);
	for (auto v : best) {
		pair<int, int> pp = longest_path(v, v0);
		// cerr << "longest_path " << v0 << " " << v << endl;
		// cerr << pp.first << " " << pp.second << endl;
		apply(pp.second);
	}
	if (out.size() < 3) {
		apply(v0);
	}
	for (int i = 0; i < n; ++i) {
		if (used[i] == 0 && out.size() < 3) {
			apply(i);
		}
	}
	cout << ans << endl;
	for (auto v : out) {
		cout << v + 1 << " ";
	}
	cout << endl;
}