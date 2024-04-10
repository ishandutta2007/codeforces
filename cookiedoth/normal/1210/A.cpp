/*

Code for problem A by cookiedoth
Generated 22 Sep 2019 at 11.48 P


 ] 
 
Il] 


^_^
~_^
=_=

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

const int mx = 10;
const int C = 6;
int n, m, used[C][C];
vector<pair<int, int> > e;

signed main() {
	fast_io();
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		e.emplace_back(u, v);
	}
	vector<int> clr(n);
	int ans = 0;
	while (true) {
		for (int i = 0; i < C; ++i) {
			for (int j = 0; j < C; ++j) {
				used[i][j] = 0;
			}
		}
		int res = 0;
		for (auto pp : e) {
			if (used[clr[pp.first]][clr[pp.second]] == 0) {
				res++;
				used[clr[pp.first]][clr[pp.second]] = 1;
				used[clr[pp.second]][clr[pp.first]] = 1;
			}
		}
		chkmax(ans, res);
		int ok = 0;
		for (int i = 0; i < n; ++i) {
			if (clr[i] < C - 1) {
				clr[i]++;
				for (int j = 0; j < i; ++j) {
					clr[j] = 0;
				}
				ok = 1;
				break;
			}
		}
		if (ok == 0) {
			break;
		}
	}
	cout << ans << endl;
}