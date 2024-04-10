/*

Code for problem C by cookiedoth
Generated 15 Mar 2020 at 11.22 PM



10%

30%

50%

70%

100%

>_<
\_()_/
^_^

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
int n, ans[mx];
vector<vector<pair<int, int> > > g;

signed main() {
	fast_io();
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].emplace_back(v, i);
		g[v].emplace_back(u, i);
	}
	fill(ans, ans + n - 1, -1);
	int it = 0;
	for (int i = 0; i < n; ++i) {
		if (g[i].size() >= 3) {
			for (auto pp : g[i]) {
				ans[pp.second] = it++;
			}
			break;
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		if (ans[i] == -1) {
			ans[i] = it++;
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		cout << ans[i] << "\n";
	}
}