/*

Code for problem D by savkinsd2089
Generated 18 Oct 2018 at 07.54 pm
The Moon is Waxing Gibbous (68% of Full)










(@)(@)(@)(@)(@)

~_^
\_()_/
~_^

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
ll n, k, a[mx], pa[mx];
map<int, int> cnt;

int inv(int x) {
	return (1 << k) - 1 - x;
}

signed main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		pa[i] = pa[i - 1] ^ a[i - 1];
	}
	//output(pa, pa + n + 1);
	for (int i = 0; i <= n; ++i) {
		if ((pa[i] & 1) == 0) {
			//cerr << pa[i] << endl;
			cnt[pa[i]]++;
		}
		else {
			//cerr << inv(pa[i]) << endl;
			cnt[inv(pa[i])]++;
		}
	}
	ll ans = n * (n + 1) / 2;
	for (auto pp : cnt) {
		ll val = pp.second;
		//cerr << "val = " << val << endl;
		ll v1 = val / 2, v2 = val - v1;
		ans -= v1 * (v1 - 1) / 2;
		ans -= v2 * (v2 - 1) / 2;
	}
	cout << ans << endl;
}