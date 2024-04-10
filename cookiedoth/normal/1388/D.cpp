/*

Code for problem D by cookiedoth
Generated 01 Aug 2020 at 10.08 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

=_=
\_()_/
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

const int mx = 2e5 + 228;
int n, b[mx];
ll a[mx];
vector<vector<int> > children;
vector<int> order;

void read() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	children.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		b[i]--;
		if (b[i] != -2) {
			children[b[i]].push_back(i);
		}
	}
}

void dfs(int v) {
	for (auto v1 : children[v]) {
		dfs(v1);
		if (a[v1] > 0) {
			a[v] += a[v1];
		}
	}
}

void order_dfs(int v) {
	vector<int> up, down;
	for (auto v1 : children[v]) {
		if (a[v1] > 0) {
			up.push_back(v1);
		} else {
			down.push_back(v1);
		}
	}
	for (auto v1 : up) {
		order_dfs(v1);
	}
	order.push_back(v);
	for (auto v1 : down) {
		order_dfs(v1);
	}
}

void solve() {
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		if (b[i] == -2) {
			dfs(i);
			order_dfs(i);
		}
	}
	for (int i = 0; i < n; ++i) {
		ans += a[i];
	}
	cout << ans << '\n';
	for (int i = 0; i < n; ++i) {
		cout << order[i] + 1 << ' ';
	}
	cout << '\n';
}

signed main() {
	fast_io();
	read();
	solve();
}