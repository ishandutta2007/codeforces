/*

Code for problem E by savkinsd2089
Generated 15 Dec 2018 at 03.49 pm
The Moon is Waxing Gibbous (51% of Full)


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

>_<
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

class mfe {

private:

	ll value;

	const static ll mod = 1e9 + 7;

	ll power(ll x, ll deg) {
		if (deg == 0)
			return 1;
		if ((deg & 1) == 0) {
			ll half = power(x, deg >> 1);
			return (half * half) % mod;
		}
		else {
			ll peace = power(x, deg - 1);
			return (peace * x) % mod;
		}
	}

	ll power(ll x) {
		return power(x, mod - 2);
	}

public:

	mfe(ll _value): value((_value % mod + mod) % mod) {}
	mfe(int _value): value(((ll)_value % mod + mod) % mod) {}
	mfe(): value(0) {}

	mfe inv () {
		return mfe(power(value));
	}

	mfe operator + (const mfe &a) {
		return (this->value + a.value) % mod;
	}

	mfe operator * (const mfe &a) {
		return (this->value * a.value) % mod;
	}

	mfe operator - (const mfe &a) {
		return (this->value - a.value + mod) % mod;
	}

	mfe operator / (const mfe &a) {
		return (*this) * ((mfe)power(a.value));
	}

	mfe operator += (const mfe &a) {
		return *this = *this + a;
		//this->value = (this->value + a.value) % mod;
	}

	mfe operator -= (const mfe &a) {
		return *this = *this - a;
		//this->value = (this->value - a.value + mod) % mod;
	}

	mfe operator *= (const mfe &a) {
		return *this = *this * a;
		//this->value = (this->value * a.value) % mod;
	}

	mfe operator /= (const mfe &a) {
		return *this = *this / a;
		//value = (value * power(a->value)) % mod;
	}

	mfe operator ++ (int) {
		return (this->value + 1) % mod;
	}

	mfe operator ++ () {
		return (this->value + 1) % mod;
	}

	mfe operator -- (int) {
		return (this->value - 1 + mod) % mod;
	}

	mfe operator -- () {
		return (this->value - 1 + mod) % mod;
	}

	mfe operator + () {
		return (*this);
	}

	mfe operator - () {
		return ((mod - this->value) % mod);
	}

	operator int() const {
		return (int)value;
	}

	operator ll() const {
		return (ll)value;
	}

};

ostream& operator << (ostream &s, const mfe& a) {
	return s << (ll)a;
}

istream& operator >> (istream &s, mfe &a) {
	ll val;
	s >> val;
	a = mfe(val);
	return s;
}

const ll MOD = 1e9 + 7;
const ll p2 = 5e8 + 4;
ll n, m;
mfe ans;

ll pref_sum(mfe x) {
	return x * (x + (mfe)1) / (mfe)2;
}

void add_div(ll k) {
	ll l = n / (k + 1) + 1;
	ll r = n / k;
	if (l > m || l > r) {
		return;
	}
	chkmin(r, m);
	mfe seg_sum = pref_sum(r) - pref_sum(l - 1);
	seg_sum *= (mfe)k;
	mfe len = (mfe)(r - l + 1);
	mfe diff = ((mfe)n * (mfe)len) - seg_sum;
	ans += diff;
}

const ll K = 1e6 + 228;

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= K; ++i) {
		add_div(i);
	}
	ll max_val = n / (K + 1);
	for (ll i = 1; i <= min(max_val, m); ++i) {
		ans += (mfe)(n % i);
	}
	if (m > n) {
		ans += (mfe)(m - n) * (mfe)n;
	}
	cout << ans << endl;
}