/*

Code for problem F1 by cookiedoth
Generated 19 Mar 2020 at 06.25 PM


 ] 
 
Il] 


=_=
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

const int mx = 14;
const int RES_MASK = (1 << 6);
const int MX_MASK = (1 << mx);
int n, a[mx][mx], dp[mx][MX_MASK][RES_MASK], ch_res_mask[2];
ll ans[MX_MASK];

int rev_bits(int mask, int L) {
	int res = 0;
	for (int i = 0; i < L; ++i) {
		if ((mask >> i) & 1) {
			res ^= (1 << (L - i - 1));
		}
	}
	return res;
}

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char c;
			cin >> c;
			a[i][j] = c - '0';
		}
	}
	int L = n / 2, R = n - L;
	for (int i = 0; i < n; ++i) {
		dp[i][1 << i][0] = 1;
	}
	for (int sub = 1; sub < (1 << n); ++sub) {
		int pop_cnt = popcount(sub), rs = pop_cnt - 1;
		if (pop_cnt >= L && pop_cnt >= R) {
			continue;
		}
		for (int last = 0; last < n; ++last) {
			for (int nxt = 0; nxt < n; ++nxt) {
				if ((sub >> nxt) & 1) {
					continue;
				}
				for (int res_mask = 0; res_mask < (1 << rs); ++res_mask) {
					int new_res_mask = res_mask;
					if (a[last][nxt]) {
						new_res_mask ^= (1 << rs);
					}
					dp[nxt][sub ^ (1 << nxt)][new_res_mask] += dp[last][sub][res_mask];
				}
			}
		}
	}
	int ALL = (1 << n) - 1;
	for (int sub = 0; sub < (1 << n); ++sub) {
		if (popcount(sub) != L) {
			continue;
		}
		int _sub = (ALL ^ sub);
		if (L == R && sub > _sub) {
			continue;
		}
		vector<int> us, them;
		for (int i = 0; i < n; ++i) {
			if ((sub >> i) & 1) {
				us.push_back(i);
			} else {
				them.push_back(i);
			}
		}
		for (int res1 = 0; res1 < (1 << (L - 1)); ++res1) {
			for (int res2 = 0; res2 < (1 << (R - 1)); ++res2) {
				int flip_res2 = 0;
				for (int i = 0; i < R - 1; ++i) {
					if ((res2 >> i) & 1) {
						flip_res2 ^= (1 << (R - 2 - i));
					}
				}
				flip_res2 <<= L;
				int res_mask = flip_res2 ^ res1;
				ch_res_mask[0] = res_mask;
				ch_res_mask[1] = res_mask ^ (1 << (L - 1));
				for (auto x : us) {
					for (auto y : them) {
						ans[ch_res_mask[a[x][y]]] += dp[x][sub][res1] * dp[y][_sub][res2];
					}
				}
			}
		}
	}
	for (int i = 0; i < (1 << (n - 1)); ++i) {
		ll res = ans[i];
		if (L == R) {
			res += ans[rev_bits(i, n - 1)];
		}
		cout << res << " ";
	}
	cout << "\n";
}