/*

Code for problem F by cookiedoth
Generated 27 Apr 2020 at 08.44 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

\_()_/
^_^
~_^

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

const int MAX_N = 15;
const int MAX_SUB = (1 << MAX_N);
int n;
ll a[MAX_N], subset_sum[MAX_SUB];
int mask_lb[MAX_N][MAX_SUB];

void read() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
}

void calc_subset_sum() {
	for (int sub = 0; sub < (1 << n); ++sub) {
		subset_sum[sub] = 0;
		for (int i = 0; i < n; ++i) {
			if ((sub >> i) & 1) {
				subset_sum[sub] += a[i];
			}
		}
	}
}

void calc_mask_lb() {
	for (int i = 0; i < n; ++i) {
		for (int sub = 0; sub < (1 << n); ++sub) {
			mask_lb[i][sub] = -1;
			for (int j = i; j < n; ++j) {
				if ((sub >> j) & 1) {
					mask_lb[i][sub] = j;
					break;
				}
			}
		}
	}
}

const ll INF = 1e18;
ll dp[MAX_SUB][MAX_N + 1][MAX_N];
pair<int, int> par[MAX_SUB][MAX_N + 1][MAX_N];

void clear_dp() {
	for (int i = 0; i < (1 << n); ++i) {
		for (int cnt = 0; cnt <= n; ++cnt) {
			for (int pos = 0; pos < n; ++pos) {
				dp[i][cnt][pos] = INF;
			}
		}
	}
}

void calc_dp() {
	dp[0][0][0] = 0;
	for (int sub = 0; sub < (1 << n) - 1; ++sub) {
		for (int cnt = 0; cnt < n; ++cnt) {
			for (int pos = 0; pos < n; ++pos) {
				if (dp[sub][cnt][pos] == INF) {
					continue;
				}
				int others = ((1 << n) - 1) ^ sub;
				for (int next_sub = others; next_sub; next_sub = (next_sub - 1) & others) {
					int next_pos = mask_lb[pos][next_sub];
					if (next_pos != -1 && 
						subset_sum[next_sub] > dp[sub][cnt][pos] && 
						chkmin(dp[sub | next_sub][cnt + 1][next_pos], subset_sum[next_sub])) {

						par[sub | next_sub][cnt + 1][next_pos] = {next_sub, pos};
					}
				}
			}
		}
	}
}

vector<pair<int, int> > ans;

int get_id(int pos) {
	int res = 0;
	for (int i = 0; i < pos; ++i) {
		res += (a[i] > 0);
	}
	return res;
}

void increase(int i, int j) {
	ans.emplace_back(get_id(i), get_id(j));
	a[j] += a[i];
	a[i] = 0;
}

void process(int mask, int pos) {
	for (int i = 0; i < n; ++i) {
		if ((mask >> i) & 1 && i != pos) {
			increase(i, pos);
		}
	}
}

void restore_answer() {
	int sub = (1 << n) - 1, cnt = -1, pos = -1, ok = 0;
	for (cnt = n; cnt >= 1; --cnt) {
		for (pos = 0; pos < n; ++pos) {
			if (dp[sub][cnt][pos] != INF) {
				ok = 1;
				break;
			}
		}
		if (ok) {
			break;
		}
	}
	assert(ok);
	ans.clear();
	while (sub) {
		int mask = par[sub][cnt][pos].first;
		process(mask, pos);
		pos = par[sub][cnt][pos].second;
		sub ^= mask;
		cnt--;
	}
	cout << ans.size() << '\n';
	for (auto pp : ans) {
		cout << pp.first + 1 << " " << pp.second + 1 << '\n';
	}
}

void solve() {
	read();
	calc_subset_sum();
	calc_mask_lb();
	clear_dp();
	calc_dp();
	restore_answer();
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}