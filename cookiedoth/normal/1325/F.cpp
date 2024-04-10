/*

Code for problem F by cookiedoth
Generated 14 Mar 2020 at 05.58 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

^_^
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

const int mx = 1e5 + 228;
int S = 0;
int n, m, h[mx], used[mx], p[mx], cnt[mx];
vector<vector<int> > g;

void dfs(int v) {
	used[v] = 1;
	for (auto v1 : g[v]) {
		if (used[v1] == 0) {
			p[v1] = v;
			h[v1] = h[v] + 1;
			dfs(v1);
		} else {
			if (h[v] - h[v1] + 1 >= S) {
				cout << 2 << endl;
				vector<int> cycle;
				while (true) {
					cycle.push_back(v);
					if (v == v1) {
						break;
					}
					v = p[v];
				}
				cout << cycle.size() << endl;
				for (auto x : cycle) {
					cout << x + 1 << " ";
				}
				cout << endl;
				exit(0);
			}
		}
	}
}

signed main() {
	fast_io();
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	while (S * S < n) {
		S++;
	}
	dfs(0);
	for (int i = 0; i < n; ++i) {
		cnt[h[i] % (S - 1)]++;
	}
	int pos = (max_element(cnt, cnt + S - 1) - cnt);
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (h[i] % (S - 1) == pos) {
			ans.push_back(i);
		}
	}
	assert(ans.size() >= S);
	cout << 1 << endl;
	for (int i = 0; i < S; ++i) {
		cout << ans[i] + 1 << " ";
	}
	cout << endl;
}