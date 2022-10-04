/*

Code for problem D by savkinsd2089
Generated 11 Jan 2019 at 06.02 pm
The Moon is Waxing Crescent (25% of Full)










(@)(@)(@)(@)(@)

=_=
o_O
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

const int mx = 2e5 + 228;
int n, a[mx], used[mx];
vector<int> g[mx], vertexes[mx];

void factor(int pos) {
	int val = a[pos];
	for (int i = 2; i * i <= val; ++i) {
		if (val % i == 0) {
			vertexes[i].push_back(pos);
			while (val % i == 0) {
				val /= i;
			}
		}
	}

	if (val != 1) {
		vertexes[val].push_back(pos);
	}
}

int furthest(int v, int pv, int val, int &res) {
	used[v] = val;
	res = v;
	int len = -1;
	for (auto v1 : g[v]) {
		int next_res;
		if (v1 != pv && a[v1] % val == 0 && chkmax(len, furthest(v1, v, val, next_res))) {
			res = next_res;
		}
	}
	return len + 1;
}

signed main() {
	fast_io();
	int border = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		used[i] = -1;
		chkmax(border, a[i]);
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 0; i < n; ++i) {
		factor(i);
	}

	int ans = 0;
	for (int i = 2; i <= border; ++i) {
		for (auto v : vertexes[i]) {
			if (used[v] != i) {
				int v1;
				furthest(v, -1, i, v1);
				int len = furthest(v1, -1, i, v1);
				chkmax(ans, len + 1);
			}
		}
	}

	cout << ans << endl;
}