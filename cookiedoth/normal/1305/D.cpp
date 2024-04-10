/*

Code for problem D by cookiedoth
Generated 03 Mar 2020 at 05.57 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

z_z
>_<
\_()_/

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

const int mx = 1010;
int n, rem[mx];
vector<set<int> > g;

int guess(int x) {
	cout << "! " << x + 1 << endl;
	exit(0);
}

void remove_vertex(int v) {
	g[*g[v].begin()].erase(v);
	g[v].clear();
	rem[v] = 1;
}

void process() {
	vector<int> to_ask;
	for (int i = 0; i < n; ++i) {
		if (g[i].size() == 1) {
			to_ask.push_back(i);
			if (to_ask.size() == 2) {
				break;
			}
		}
	}
	if (to_ask.size() < 2) {
		for (int i = 0; i < n; ++i) {
			if (rem[i] == 0) {
				guess(i);
			}
		}
	}
	cout << "? " << to_ask[0] + 1 << " " << to_ask[1] + 1 << endl;
	int res;
	cin >> res;
	res--;
	if (res == to_ask[0]) {
		guess(to_ask[0]);
	}
	if (res == to_ask[1]) {
		guess(to_ask[1]);
	}
	remove_vertex(to_ask[0]);
	remove_vertex(to_ask[1]);
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
		g[u].insert(v);
		g[v].insert(u);
	}
	while (true) {
		process();
	}
}