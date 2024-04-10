/*

Code for problem  by cookiedoth
Generated 23 Jul 2020 at 05.35 PM


  !
 
                                    
                          
                  




















\_()_/
^_^
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
const int mx = 1e5 + 228;
int n, sz[mx];
vector<vector<int> > g;

// int d[mx][mx];

// void build_d() {
// 	for (int i = 0; i < n; ++i) {
// 		for (int j = 0; j < n; ++j) {
// 			if (i != j) {
// 				d[i][j] = INF;
// 			}
// 		}
// 	}
// 	for (int i = 0; i < n; ++i) {
// 		for (auto v : g[i]) {
// 			d[i][v] = 1;
// 		}
// 	}
// 	for (int k = 0; k < n; ++k) {
// 		for (int i = 0; i < n; ++i) {
// 			for (int j = 0; j < n; ++j) {
// 				chkmin(d[i][j], d[i][k] + d[k][j]);
// 			}
// 		}
// 	}
// }

void read() {
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
}

void calc_sz(int v, int pv) {
	sz[v] = 1;
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			calc_sz(v1, v);
			sz[v] += sz[v1];
		}
	}
}

int find_centroid(int v, int pv) {
	for (auto v1 : g[v]) {
		if (v1 != pv && 2 * sz[v1] > n) {
			return find_centroid(v1, v);
		}
	}
	return v;
}

vector<vector<int> > subtrees;

void add_to_last_subtree(int v, int pv) {
	subtrees.back().push_back(v);
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			add_to_last_subtree(v1, v);
		}
	}
}

int c;

void add_subtrees() {
	for (auto v1 : g[c]) {
		subtrees.push_back(vector<int> ());
		add_to_last_subtree(v1, c);
	}
}

set<pair<pair<int, int>, int> > S;

void construct_S() {
	for (int i = 0; i < subtrees.size(); ++i) {
		// int t = (2 * subtrees[i].size() >= n ? INF : subtrees[i].size());
		int t = subtrees[i].size();
		S.insert({{t, t}, i});
	}
	S.insert({{1, 1}, subtrees.size()});
	subtrees.push_back({c});
	// cerr << "subtrees" << endl;
	// for (auto v : subtrees) {
	// 	output(all(v));
	// }
}

vector<int> order;

void process() {
	int lst = -1;
	for (int i = 0; i < n; ++i) {
		auto it = prev(S.end());
		while (it->second == lst) {
			it--;
		}
		auto pp = (*it);
		S.erase(it);
		lst = pp.second;
		order.push_back(subtrees[pp.second].back());
		subtrees[pp.second].pop_back();
		pp.first.first--;
		S.insert(pp);
	}
	// output(all(order));
}

vector<int> p;
ll ans;

void print_ans() {
	p.resize(n);
	calc_sz(c, c);
	for (int i = 0; i < n; ++i) {
		if (i != c) {
			ans += 2 * (ll)sz[i];
		}
	}
	for (int i = 0; i < n; ++i) {
		p[order[i]] = order[(i + 1) % n];
	}
	cout << ans << '\n';
	for (int i = 0; i < n; ++i) {
		cout << p[i] + 1 << ' ';
	}
	cout << '\n';
}

// void check_ans() {
// 	build_d();
// 	ll real_ans = 0;
// 	for (int i = 0; i < n; ++i) {
// 		assert(p[i] != i);
// 		real_ans += d[i][p[i]];
// 	}
// 	assert(ans == real_ans);
// }

signed main() {
	fast_io();
	read();
	calc_sz(0, 0);
	c = find_centroid(0, 0);
	// cerr << "c = " << c << endl;
	add_subtrees();
	construct_S();
	process();
	print_ans();
	// check_ans();
}

//kek