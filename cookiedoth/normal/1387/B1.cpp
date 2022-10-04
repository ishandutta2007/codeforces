/*

Code for problem  by cookiedoth
Generated 23 Jul 2020 at 04.25 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

\_()_/
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

int n;
vector<vector<int> > g, children;

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
	children.resize(n);
}

void hang(int v, int pv) {
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			children[v].push_back(v1);
			hang(v1, v);
		}
	}
}

const int INF = 1e9;
const int mx = 1e5 + 228;
int dp[mx][2], aux_dp[mx][2], cur_dp[2];
int par[mx][2];
pair<int, int> aux_par[mx][2];

void calc_dp(int v) {
	for (auto v1 : children[v]) {
		calc_dp(v1);
	}
	for (int i = 0; i < 2; ++i) {
		cur_dp[i] = INF;
		dp[v][i] = INF;
	}
	cur_dp[0] = 0;
	for (auto v1 : children[v]) {
		for (int i = 0; i < 2; ++i) {
			aux_dp[v1][i] = INF;
		}
		for (int took_v = 0; took_v < 2; ++took_v) {
			if (chkmin(aux_dp[v1][took_v], cur_dp[took_v] + dp[v1][0])) {
				aux_par[v1][took_v] = {took_v, 0};
			}
			if (chkmin(aux_dp[v1][1], cur_dp[took_v] + dp[v1][1])) {
				aux_par[v1][1] = {took_v, 1};
			}
		}
		for (int i = 0; i < 2; ++i) {
			cur_dp[i] = aux_dp[v1][i];
		}
	}
	chkmin(dp[v][0], cur_dp[1]);
	if (chkmin(dp[v][1], cur_dp[1] + 1)) {
		par[v][1] = 1;
	}
	if (chkmin(dp[v][1], cur_dp[0] + 1)) {
		par[v][1] = 0;
	}
}

int path_cnt;
vector<vector<int> > paths;

int restore_dp(int v, int is_path, int path_id) {
	// cerr << "restore_dp " << v << " " << is_path << " " << path_id << endl;
	if (is_path && path_id != -1) {
		paths[path_id].push_back(v);
	}
	int state, last_path_id = -1;
	if (is_path == 0) {
		state = 1;
	}
	if (is_path == 1) {
		state = par[v][1];
	}
	for (int i = (int)children[v].size() - 1; i >= 0; --i) {
		int v1 = children[v][i];
		int type = aux_par[v1][state].second;
		state = aux_par[v1][state].first;
		if (type == 0) {
			restore_dp(v1, 0, -1);
		} else {
			if (last_path_id == -1) {
				last_path_id = restore_dp(v1, 1, -1);
				// cerr << "last_path_id = " << last_path_id << endl;
			} else {
				paths[last_path_id].push_back(v);
				// cerr << "kek" << endl;
				// output(paths[last_path_id]);
				restore_dp(v1, 1, last_path_id);
				last_path_id = -1;
			}
		}
	}
	// cerr << "done " << v << endl;
	// if (!paths.empty()) {
	// 	output(paths[0]);
	// }
	if (last_path_id == -1 && is_path == 1 && path_id == -1) {
		paths.push_back(vector<int> ());
		last_path_id = path_cnt++;
	}
	// cerr << "kek" << endl;
	if (path_id == -1 && last_path_id != -1) {
		paths[last_path_id].push_back(v);
	}
	if (path_id == -1 && is_path == 1) {
		path_id = last_path_id;
	}
	return path_id;
}

vector<int> p, used;

void restore_p() {
	// cerr << "paths" << endl;
	// for (auto v : paths) {
	// 	output(all(v));
	// }
	reverse(all(paths));
	p.resize(n);
	used.resize(n);
	for (auto v : paths) {
		vector<int> curV;
		for (auto v1 : v) {
			if (used[v1] == 0) {
				used[v1] = 1;
				curV.push_back(v1);
			}
		}
		assert(curV.size() > 1);
		for (int i = 0; i < (int)curV.size(); ++i) {
			p[curV[i]] = curV[(i + 1) % curV.size()];
		}
	}
}

signed main() {
	fast_io();
	read();
	hang(0, 0);
	calc_dp(0);
	restore_dp(0, 0, -1);
	// cerr << "restore_dp" << endl;
	restore_p();
	cout << dp[0][0] * 2 << endl;
	for (int i = 0; i < n; ++i) {
		cout << p[i] + 1 << ' ';
	}
	cout << '\n';
}