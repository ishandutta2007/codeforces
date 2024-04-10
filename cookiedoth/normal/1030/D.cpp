/*

Code for problem D by savkinsd2089
Generated 23 Sep 2018 at 04.35 pm
The Moon is Waxing Gibbous (98% of Full)


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

o_O
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

ll n, m, k, cnt;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

signed main() {
	cin >> n >> m >> k;

	if (k % 2 == 0) {
		k /= 2;
		ll g1 = gcd(n, k);
		n /= g1;
		k /= g1;
		ll g2 = gcd(m, k);
		m /= g2;
		k /= g2;
		if (k != 1) {
			cout << "NO" << endl;
			return 0;
		}
		cout << "YES" << endl;
		cout << 0 << " " << 0 << endl;
		cout << 0 << " " << m << endl;
		cout << n << " " << 0 << endl;
	}
	else {
		if ((n * m) % k != 0) {
			cout << "NO" << endl;
			return 0;
		}
		ll n1 = n;
		ll m1 = m;
		ll g1 = gcd(n1, k);
		n1 /= g1;
		k /= g1;
		m1 /= gcd(m1, k);
		if (n1 * 2 <= n)
			n1 *= 2;
		else {
			if (m1 * 2 <= m)
				m1 *= 2;
		}
		cout << "YES" << endl;
		cout << 0 << " " << 0 << endl;
		cout << 0 << " " << m1 << endl;
		cout << n1 << " " << 0 << endl;
	}
}