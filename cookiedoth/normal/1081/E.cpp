/*

Code for problem E by savkinsd2089
Generated 16 Dec 2018 at 05.14 pm
The Moon is Waxing Gibbous (61% of Full)



10%

30%

50%

70%

100%

>_<
o_O
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

const ll INF = 8e18;

ll next_sq(ll diff, ll &cur_sq) {
	ll min_a = INF, opt_b = INF;
	for (ll y = 1; y * y <= diff; ++y) {
		if (diff % y == 0) {
			ll x = diff / y;
			if ((x + y) % 2 == 0) {
				ll a = (x + y) >> 1;
				ll b = (x - y) >> 1;
				if (b > cur_sq && chkmin(min_a, a)) {
					opt_b = b;
				}
			}
		}
	}
	if (min_a == INF) {
		cout << "No\n";
		exit(0);
	}
	ll res = opt_b * opt_b - cur_sq * cur_sq;
	cur_sq = min_a;
	return res;
}

int n;
vector<ll> a;

signed main() {
	ll cur_sq = 0;
	cin >> n;
	n /= 2;
	for (int i = 0; i < n; ++i) {
		ll diff;
		cin >> diff;
		ll val = next_sq(diff, cur_sq);
		a.push_back(val);
		a.push_back(diff);
	}
	cout << "Yes\n";
	output(all(a), cout);
}