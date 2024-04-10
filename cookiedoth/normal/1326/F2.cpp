/*

Code for problem F2 by cookiedoth
Generated 01 Apr 2020 at 04.19 PM










(@)(@)(@)(@)(@)

-_-
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
#define ll unsigned long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define popcount(a) __builtin_popcount(a)

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

istream& operator >> (istream &is, __int128 &x) {
	long long a;
	is >> a;
	x = (__int128)a;
	return is;
}

ostream& operator << (ostream &os, const __int128 &x) {
	os << (long long)x;
	return os;
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

const int MAX_N = 18;
int n, know[MAX_N][MAX_N];

void read() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char c;
			cin >> c;
			know[i][j] = c - '0';
		}
	}
}

const int MAX_SUBS = (1 << MAX_N);

ll path_dp[MAX_SUBS][MAX_N], paths[MAX_N + 1][MAX_SUBS];

void calc_paths() {
	for (int i = 0; i < n; ++i) {
		path_dp[1 << i][i] = 1;
	}
	for (int sub = 1; sub < (1 << n); ++sub) {
		for (int from = 0; from < n; ++from) {
			if (path_dp[sub][from]) {
				for (int to = 0; to < n; ++to) {
					if (((sub >> to) & 1) == 0 && know[from][to]) {
						path_dp[sub ^ (1 << to)][to] += path_dp[sub][from];
					}
				}
			}
		}
	}
	for (int sub = 1; sub < (1 << n); ++sub) {
		for (int v = 0; v < n; ++v) {
			paths[popcount(sub)][sub] += path_dp[sub][v];
		}
	}
	// cerr << "paths" << endl;
	// for (int sub = 0; sub < (1 << n); ++sub) {
	// 	if (paths[popcount(sub)][sub]) {
	// 		cout << sub << " " << paths[popcount(sub)][sub] << endl;
	// 	}
	// }
}

void sos_paths() {
	for (int len = 1; len <= n; ++len) {
		for (int b = 0; b < n; ++b) {
			for (int i = 0; i < (1 << n); ++i) {
				if ((i >> b) & 1) {
					paths[len][i] += paths[len][i ^ (1 << b)];
				}
			}
		}
	}
}

map<vector<int>, ll> values;
vector<int> cur;
vector<vector<int> > splits;

void bruteforce(int sum, int val) {
	if (sum == n) {
		splits.push_back(cur);
		return;
	}
	if (sum + 2 * val <= n || sum + val == n) {
		cur.push_back(val);
		bruteforce(sum + val, val);
		cur.pop_back();
	}
	if (sum + val < n) {
		bruteforce(sum, val + 1);
	}
}

vector<ll> coef;

void calc_values() {
	coef.resize(1 << n);
	for (int i = 0; i < (1 << n); ++i) {
		coef[i] = ((n - popcount(i)) % 2 ? -1 : 1);
	}
	for (auto split : splits) {
		ll sum = 0;
		for (int sub = 0; sub < (1 << n); ++sub) {
			ll cur = 1;
			for (auto x : split) {
				cur *= paths[x][sub];
			}
			sum += cur * coef[sub];
		}
		values[split] = sum;
	}
}

ll ans[MAX_SUBS];

void calc_ans() {
	for (int sub = 0; sub < (1 << (n - 1)); ++sub) {
		int cur_block = 1;
		vector<int> blocks;
		for (int i = 0; i < n - 1; ++i) {
			if ((sub >> i) & 1) {
				cur_block++;
			} else {
				blocks.push_back(cur_block);
				cur_block = 1;
			}
		}
		blocks.push_back(cur_block);
		sort(all(blocks));
		ans[sub] = values[blocks];
	}
}

void backsos_ans() {
	for (int b = 0; b < n; ++b) {
		for (int sub = 0; sub < (1 << n); ++sub) {
			if ((sub >> b) & 1) {
				ans[sub ^ (1 << b)] -= ans[sub];
			}
		}
	}
}

signed main() {
	fast_io();
	read();
	calc_paths();
	sos_paths();
	bruteforce(0, 1);
	calc_values();
	calc_ans();
	backsos_ans();
	output(ans, ans + (1 << (n - 1)), cout);
}