/*

Code for problem D by cookiedoth
Generated 23 Feb 2020 at 12.57 P


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

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

struct event {
	int x, type, id;
};

bool operator < (event a, event b) {
	return make_pair(a.x, a.type) < make_pair(b.x, b.type);
}

const int INF = 1e9 + 228;
const int K = 8;
int n, m, k, dp[1 << K], _dp[1 << K], ids[K], odd[1 << K];
vector<event> ev;

void init_dp() {
	fill(dp, dp + (1 << k), -INF);
	fill(ids, ids + k, -1);
	dp[0] = 0;
}

void init_odd() {
	for (int i = 0; i < (1 << k); ++i) {
		odd[i] = (__builtin_popcount(i) & 1);
	}
}

signed main() {
	fast_io();
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		ev.push_back({l, 1, i});
		ev.push_back({r + 1, -1, i});
	}
	sort(all(ev));
	init_dp();
	init_odd();
	for (int it = 0; it < (int)ev.size(); ++it) {
		auto e = ev[it];
		fill(_dp, _dp + (1 << k), -INF);
		if (e.type == 1) {
			int bit = -1;
			for (int i = 0; i < k; ++i) {
				if (ids[i] == -1) {
					bit = i;
					break;
				}
			}
			assert(bit != -1);
			for (int mask = 0; mask < (1 << k); ++mask) {
				chkmax(_dp[mask], dp[mask]);
				chkmax(_dp[mask ^ (1 << bit)], dp[mask]);
			}
			ids[bit] = e.id;
		} else {
			int bit = -1;
			for (int i = 0; i < k; ++i) {
				if (ids[i] == e.id) {
					bit = i;
					break;
				}
			}
			assert(bit != -1);
			ids[bit] = -1;
			for (int mask = 0; mask < (1 << k); ++mask) {
				if (((mask >> bit) & 1) == 0) {
					_dp[mask] = max(dp[mask], dp[mask ^ (1 << bit)]);
				}
			}
		}
		copy(_dp, _dp + (1 << k), dp);
		if (it < (int)ev.size() - 1) {
			for (int mask = 0; mask < (1 << k); ++mask) {
				if (dp[mask] != -INF && odd[mask]) {
					dp[mask] += ev[it + 1].x - ev[it].x;
				}
			}
		}
	}
	cout << dp[0] << endl;
}