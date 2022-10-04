/*

Code for problem C by cookiedoth
Generated 25 May 2022 at 09.18 PM
The Moon is Waning Crescent (21% of Full)


        __________
       1          1
       1          1
       1          1
  ____ 1     ____ 1
 /    \1    /    \1
1      1   1      1
 \____/     \____/
 
~_^
=_=
\_()_/

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

const int MAX_N = 1e5 + 228;
int n, bal[2 * MAX_N];
string s;

void solve() {
	cin >> n >> s;
	n *= 2;
	for (int i = 0; i < n; ++i) {
		bal[i + 1] = bal[i] + (s[i] == '(' ? 1 : -1);
	}
	int l = n, r = -1;
	for (int i = 0; i <= n; ++i) {
		if (bal[i] < 0) {
			chkmin(l, i);
			chkmax(r, i);
		}
	}
	if (l > r) {
		cout << 0 << '\n';
		return;
	}
	int pos1 = max_element(bal, bal + l + 1) - bal;
	int pos2 = max_element(bal + r, bal + n + 1) - bal;
	int pos = max_element(bal, bal + n + 1) - bal;
	if (bal[pos1] + bal[pos2] >= bal[pos]) {
		cout << 1 << '\n';
		cout << pos1 + 1 << ' ' << pos2 << '\n';
		return;
	} else {
		cout << 2 << '\n';
		cout << 1 << ' ' << pos << '\n';
		cout << pos + 1 << ' ' << n << '\n';
	}
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}