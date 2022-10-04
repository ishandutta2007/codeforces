/*

Code for problem B by cookiedoth
Generated 19 Nov 2019 at 05.53 P



10%

30%

50%

70%

100%

>_<
o_O
^_^

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

vector<ll> fact(ll x) {
	vector<ll> res;
	for (ll i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			res.push_back(i);
			while (x % i == 0) {
				x /= i;
			}
		}
	}
	if (x > 1) {
		res.push_back(x);
	}
	return res;
}

const int mx = 1e6 + 228;
int n;
ll a[mx], _a[mx], sum;

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum == 1) {
		cout << -1 << endl;
		exit(0);
	}
	vector<ll> primes = fact(sum);
	ll ans = 1e18;
	for (auto pr : primes) {
		copy(a, a + n, _a);
		for (int i = 1; i < n; ++i) {
			_a[i] += _a[i - 1];
		}
		ll op = 0;
		for (int i = 0; i < n; ++i) {
			op += min(_a[i] % pr, pr - _a[i] % pr);
		}
		chkmin(ans, op);
	}
	cout << ans << endl;
}