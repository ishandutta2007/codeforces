/*

Code for problem B by cookiedoth
Generated 08 May 2022 at 08.00 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

o_O
-_-
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
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define length(a) (int)a.size()

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

const int MAX_S = 1e6 + 228;
int n, m, pref[MAX_S], S, suf[MAX_S], suf_r[MAX_S];
string s;

void solve() {
	cin >> n >> m >> s;
	S = n * m;
	for (int i = 0; i < S; ++i) {
		pref[i + 1] = pref[i] + (int)(s[i] - '0');
	}
	fill(suf, suf + S + 1, 0);
	fill(suf_r, suf_r + S + 1, 0);
	for (int r = 0; r < m; ++r) {
		for (int i = 0; i < n; ++i) {
			if (s[i * m + r] == '1') {
				suf[i * m + r] = 1;
				break;
			}
		}
	}
	for (int i = m - 1; i < S; ++i) {
		if (pref[i + 1] - pref[i - m + 1]) {
			suf_r[i]++;
		}
	}
	for (int i = 1; i < S; ++i) {
		suf[i] += suf[i - 1];
	}
	for (int i = m; i < S; ++i) {
		suf_r[i] += suf_r[i - m];
	}
	for (int i = 0; i < S; ++i) {
		int res = suf[i] + suf_r[i];
		if (i % m != m - 1) {
			res += (int)(pref[i % m + 1] > 0);
		}
		cout << res << ' ';
	}
	cout << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}