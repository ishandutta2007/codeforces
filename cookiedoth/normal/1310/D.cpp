/*

Code for problem D by cookiedoth
Generated 24 Feb 2020 at 06.57 PM


 ] 
 
Il] 


^_^
~_^
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

const int mx = 85;
const int INF = 1e9 + 228;
int n, k, k2, d[mx][mx], max_dist[mx][mx][mx], used[mx], cycle[mx], ans;

void bruteforce(int len) {
	if (len == k2) {
		int res = 0;
		for (int i = 0; i < k2; ++i) {
			int u = cycle[i];
			int v = cycle[(i + 1) % k2];
			int ok = 0;
			for (int it = 0; it < n - 2 + (int)(u == v); ++it) {
				int _v = max_dist[u][v][it];
				if (!used[_v]) {
					res += d[u][_v] + d[_v][v];
					ok = 1;
					break;
				}
			}
			if (!ok) {
				res = INF;
				break;
			}
		}
		chkmin(ans, res);
	} else {
		for (int i = 0; i < n; ++i) {
			used[i]++;
			cycle[len] = i;
			bruteforce(len + 1);
			used[i]--;
		}
	}
}

signed main() {
	fast_io();
	cin >> n >> k;
	k2 = k / 2;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> d[i][j];
		}
	}
	vector<pair<int, int> > vp;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			vp.clear();
			for (int v = 0; v < n; ++v) {
				if (v != i && v != j) {
					vp.emplace_back(d[i][v] + d[v][j], v);
				}
			}
			sort(all(vp));
			for (int it = 0; it < vp.size(); ++it) {
				max_dist[i][j][it] = vp[it].second;
			}
		}
	}
	ans = INF;
	bruteforce(1);
	cout << ans << endl;
}