/*

Code for problem B by cookiedoth
Generated 04 Jun 2020 at 05.53 PM



10%

30%

50%

70%

100%

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

const int MOD = 1e9 + 7;

int mul(int a, int b) {
	return (1LL * a * b) % MOD;
}

void add(int &a, int b) {
	a = (a + b) % MOD;
	if (a >= MOD) {
		a -= MOD;
	}
}

int diff(int a, int b) {
	a -= b;
	if (a < 0) {
		a += MOD;
	}
	return a;
}

int power(int a, int deg) {
	int res = 1;
	for (; deg; deg >>= 1, a = mul(a, a)) {
		if (deg & 1) {
			res = mul(res, a);
		}
	}
	return res;
}

int inverse(int a) {
	return power(a, MOD - 2);
}

const ll INF = 1e9;
int n, p;
ll delta;

void solve() {
	cin >> n >> p;
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		int deg;
		cin >> deg;
		if (p == 1) {
			deg = 0;
		}
		mp[deg]++;
	}
	vector<pair<int, int> > vp(all(mp));
	reverse(all(vp));
	int ans = 0;
	ll delta = 0;
	for (int i = 0; i < vp.size(); ++i) {
		if (i) {
			ans = mul(ans, power(p, vp[i - 1].first - vp[i].first));
			if (delta != INF && delta != 0) {
				for (int it = 0; it < vp[i - 1].first - vp[i].first; ++it) {
					delta *= (ll)p;
					if (delta >= INF) {
						delta = INF;
						break;
					}
				}
			}
		}
		if (delta == INF) {
			ans = diff(ans, vp[i].second);
		} else {
			int op = min((int)delta, vp[i].second);
			delta -= op;
			ans -= op;
			vp[i].second -= op;
			if (vp[i].second % 2 == 1) {
				ans = delta = 1;
			}
		}
	}
	ans = mul(ans, power(p, vp.back().first));
	cout << ans << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}