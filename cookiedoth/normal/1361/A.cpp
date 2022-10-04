/*

Code for problem A by cookiedoth
Generated 04 Jun 2020 at 05.43 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

=_=
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

int n, m;
vector<vector<int> > g;
vector<int> t, val;

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
	t.resize(n);
	vector<pair<int, int> > order;
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
		t[i]--;
		order.emplace_back(t[i], i);
	}
	val.resize(n, -1);
	sort(all(order));
	vector<int> keks;
	for (int i = 0; i < n; ++i) {
		int v0 = order[i].second;
		keks.assign(t[v0] + 1, 0);
		for (auto v : g[v0]) {
			if (val[v] >= 0 && val[v] <= t[v0]) {
				keks[val[v]] = 1;
			}
		}
		int is_zero = 0;
		for (int j = 0; j < t[v0]; ++j) {
			if (keks[j] == 0) {
				is_zero = 1;
			}
		}
		if (is_zero || keks[t[v0]] == 1) {
			cout << -1 << endl;
			exit(0);
		}
		val[v0] = t[v0];
	}
	for (auto x : order) {
		cout << x.second + 1 << " ";
	}
	cout << endl;
}