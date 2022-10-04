/*

Code for problem H by savkinsd2089
Generated 12 Dec 2018 at 10.12 pm
The Moon is Waxing Crescent (26% of Full)


 ] 
 
Il] 


-_-
z_z
z_z

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

const int mx = 2e5 + 228;
const int lg = 18;
int n, src[mx], a[mx], q, pref[lg][mx];

signed main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		src[i] = c - '0';
	}

	for (int i = 0; i < n - 1; ++i) {
		a[i] = src[i] ^ src[i + 1];
	}

	for (int i = 0; i < lg; ++i) {
		int step = (1 << i);
		for (int j = 0; j < n - 1; ++j) {
			if (j < step) {
				pref[i][j] = a[j];
			}
			else {
				pref[i][j] = pref[i][j - step] + a[j];
			}
		}
	}

	cin >> q;
	for (int q_id = 0; q_id < q; ++q_id) {
		int l, r;
		cin >> l >> r;
		if (l == r) {
			cout << "0\n";
			continue;
		}

		int sz = r - l, pos = l, step = 2, ans = 0, log_step = 1;
		while (sz) {
			int cur_sz = (r - 1 - pos) / step + 1, most_r = pos + (cur_sz - 1) * step, cur_sum;
			if (pos < step) {
				cur_sum = pref[log_step][most_r];
			}
			else {
				cur_sum = pref[log_step][most_r] - pref[log_step][pos - step];
			}
			ans += min(cur_sum, cur_sz - cur_sum);
			pos += step / 2;
			step <<= 1;
			sz >>= 1;
			log_step++;
		}
		cout << (ans + 1) / 2 << "\n";
	}
}