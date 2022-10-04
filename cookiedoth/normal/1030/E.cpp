/*

Code for problem E by savkinsd2089
Generated 23 Sep 2018 at 04.57 pm
The Moon is Waxing Gibbous (98% of Full)



10%

30%

50%

70%

100%

~_^
>_<
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

const int lg = 64;
const int mx = 3e5 + 228;
int n, a[mx], pref[mx], pref2[2][mx], rb[mx][lg];
ll ans = 0;

signed main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll val;
		cin >> val;
		a[i] = __builtin_popcountll(val);
	}
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = pref[i] + a[i];
	}
	for (int i = 0; i <= n; ++i) {
		pref2[0][i + 1] = pref2[0][i];
		pref2[1][i + 1] = pref2[1][i];
		//cerr << "up " << i + 1 << " " << pref[i] % 2 << endl;
		pref2[pref[i] % 2][i + 1]++;
	}
	//output(a, a + n);
	//output(pref, pref + n + 1);
	//output(pref2[0], pref2[0] + n + 2);
	//output(pref2[1], pref2[1] + n + 2);
	for (int i = 0; i < lg; ++i) {
		//cerr << "i = " << i << endl;
		int pos = n;
		for (int j = n - 1; j >= 0; --j) {
			if (a[j] >= i)
				pos = j;
			//cerr << "pos = " << pos << endl;
			rb[j][i] = pos;
		}
	}
	/*cerr << "rb" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < lg; ++j) {
			cerr << rb[i][j] << " ";
		}
		cerr << endl;
	}*/
	for (int i = 0; i < n; ++i) {
		//cerr << "i = " << i << endl;
		int l = i;
		for (int j = 0; j < lg - 1; ++j) {
			//cerr << "j = " << j << endl;
			int r = rb[i][j + 1] - 1;
			//cerr << "lr = " << l << " " << r << endl;
			if (l <= r) {
				int pos = lower_bound(pref, pref + n + 1, pref[i] + 2 * j) - pref - 1;
				int real_l = max(l, pos);
				if (r >= real_l) {
					int type = pref[i] % 2;
					ans += (ll)pref2[type][r + 2] - pref2[type][real_l + 1];
				}
			}
			l = r + 1;
		}
		//cerr << "ans = " << ans << endl;
	}
	cout << ans << endl;
}