/*

Code for problem B by savkinsd2089
Generated 18 Nov 2018 at 07.13 pm
The Moon is Waxing Gibbous (78% of Full)


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

~_^
~_^
>_<

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
#include <numeric>
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

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int mx = 110;
int n, sz, a[mx], sum, dp[mx][mx * mx], pref[mx][mx * mx], ans;

signed main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}

	sort(a, a + n);

	vector<pair<int, int> > v;
	int cnt = 1, val = a[0];
	for (int i = 1; i <= n; ++i) {
		if (i == n || a[i] != a[i - 1]) {
			v.push_back({val, cnt});
			val = a[i];
			cnt = 1;
		}
		else {
			cnt++;
		}
	}

	sz = v.size();
	dp[0][0] = 1;

	for (int i = 0; i < sz; ++i) {
		val = v[i].first;
		cnt = v[i].second;

		for (int j = 0; j <= n; ++j) {
			for (int s = 0; s <= sum; ++s) {
				pref[j][s] = dp[j][s];
			}
		}

		for (int j = 1; j <= n; ++j) {
			for (int s = val; s <= sum; ++s) {
				pref[j][s] += pref[j - 1][s - val];
			}
		}

		for (int j = 0; j <= n; ++j) {
			for (int s = 0; s <= sum; ++s) {
				int upd_cnt = min(j, s / val);
				if (upd_cnt <= cnt) {
					dp[j][s] = min(pref[j][s], 2);
				}
				else {
					dp[j][s] = min(pref[j][s] - pref[j - cnt - 1][s - (cnt + 1) * val], 2);
				}
			}
		}
	}

	/*cerr << "dp" << endl;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= sum; ++j) {
			cerr << dp[i][j] << " ";
		}
		cerr << endl;
	}*/

	for (auto pp : v) {
		int val = pp.first;
		int cnt = pp.second;
		for (int i = 1; i <= cnt; ++i) {
			if (dp[i][val * i] == 1) {
				chkmax(ans, i);
				if (ans == cnt && v.size() == 2) {
					ans = n;
				}
			}
		}
	}

	cout << ans << endl;
}