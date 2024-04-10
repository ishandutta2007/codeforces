/*

Code for problem C1 by savkinsd2089
Generated 12 Aug 2018 at 07.03 pm
The Moon is Waxing Crescent (2% of Full)


 ] 
 
Il] 


-_-
-_-
o_O

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
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
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)

#ifndef TESTING
	#define endl '\n'
#endif

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

const int mx = 1e6 + 228;
int n, m, flag[mx], cnt[mx];
vector<int> g[mx], pop, ans;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
	}
	memset(flag, -1, sizeof(int) * n);
	for (int i = 0; i < n; ++i) {
		if (flag[i] == -1) {
			flag[i] = i;
			pop.push_back(i);
			for (auto v : g[i]) {
				if (flag[v] == -1) {
					flag[v] = i;
				}
			}
		}
	}
	for (int i = (int)pop.size() - 1; i >= 0; --i) {
		int v = pop[i];
		if (cnt[v] == 0) {
			ans.push_back(v);
			for (auto v1 : g[v]) {
				cnt[v1]++;
			}
		}
	}
	cout << ans.size() << endl;
	for (auto x : ans) {
		cout << x + 1 << " ";
	}
	cout << endl;
}