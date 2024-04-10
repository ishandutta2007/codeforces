/*

Code for problem E by cookiedoth
Generated 17 May 2020 at 01.28 PM


 ] 
 
Il] 


~_^
=_=
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

int n, m, n1, n2, n3;
vector<vector<int> > g;

void read() {
	cin >> n >> m;
	cin >> n1 >> n2 >> n3;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

const int mx = 5010;
vector<vector<int> > cmp[2];
int clr[mx];

int dfs(int v) {
	cmp[clr[v]].back().push_back(v);
	for (auto v1 : g[v]) {
		if (clr[v1] == -1) {
			clr[v1] = (clr[v] ^ 1);
			if (dfs(v1)) {
				return 1;
			}
		} else {
			if (clr[v1] != (clr[v] ^ 1)) {
				return 1;
			}
		}
	}
	return 0;
}

void no() {
	cout << "NO\n";
	exit(0);
}

void process() {
	fill(clr, clr + n, -1);
	for (int i = 0; i < n; ++i) {
		if (clr[i] == -1) {
			clr[i] = 0;
			cmp[0].push_back(vector<int> ());
			cmp[1].push_back(vector<int> ());
			if (dfs(i)) {
				no();
			}
		}
	}
}

int cs, dp[mx][mx], which[mx], delta[mx];

void knapsack() {
	dp[0][0] = 1;
	cs = cmp[0].size();
	for (int i = 0; i < cs; ++i) {
		if (cmp[0][i].size() > cmp[1][i].size()) {
			swap(cmp[0][i], cmp[1][i]);
		}
		// cerr << "sizes " << cmp[0][i].size() << " " << cmp[1][i].size() << endl;
		n2 -= cmp[0][i].size();
		delta[i] = cmp[1][i].size() - cmp[0][i].size();
		for (int j = 0; j <= n; ++j) {
			if (dp[i][j]) {
				dp[i + 1][j] = 1;
				if (j + delta[i] <= n) {
					dp[i + 1][j + delta[i]] = 2;
				}
			}
		}
	}
	if (n2 < 0 || dp[cs][n2] == 0) {
		no();
	}
	int j = n2;
	for (int i = cs; i >= 1; --i) {
		assert(dp[i][j]);
		if (dp[i][j] == 2) {
			which[i - 1] = 1;
			j -= delta[i - 1];
		}
	}
}

int ans[mx];

void calc_ans() {
	for (int i = 0; i < cs; ++i) {
		for (auto v : cmp[which[i]][i]) {
			ans[v] = 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (ans[i] == 0 && n3) {
			ans[i] = 2;
			n3--;
		}
	}
}

void print_ans() {
	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		cout << ans[i] + 1;
	}
	cout << '\n';
}

signed main() {
	fast_io();
	read();
	process();
	knapsack();
	calc_ans();
	print_ans();
}