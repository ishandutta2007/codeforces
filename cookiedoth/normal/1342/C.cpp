/*

Code for problem C by cookiedoth
Generated 26 Apr 2020 at 05.45 PM










(@)(@)(@)(@)(@)

>_<
o_O
-_-

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

const int MX = 4e4 + 228;

int a, b, q, good[MX], pref[MX];

void solve() {
	cin >> a >> b >> q;
	for (int i = 0; i < a * b; ++i) {
		good[i] = ((i % a) % b) != ((i % b) % a);
	}
	for (int i = 0; i < a * b; ++i) {
		pref[i + 1] = pref[i] + good[i];
	}
	for (int i = 0; i < q; ++i) {
		ll l, r;
		cin >> l >> r;
		ll block1 = l / (ll)(a * b);
		ll block2 = r / (ll)(a * b);
		int c1 = l % (a * b);
		int c2 = r % (a * b);
		ll ans = 0;
		if (block1 == block2) {
			ans = pref[c2 + 1] - pref[c1];
		} else {
			ans = pref[c2 + 1] + pref[a * b] - pref[c1];
			ans += (ll)pref[a * b] * (block2 - block1 - 1);
		}
		cout << ans << "\n";
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