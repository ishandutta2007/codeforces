/*

Code for problem  by cookiedoth
Generated 16 May 2020 at 03.01 PM



10%

30%

50%

70%

100%

~_^
=_=
>_<

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
#define ll __int128
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()

using namespace std;

istream& operator >> (istream &is, __int128 &x) {
	long long a;
	is >> a;
	x = (__int128)a;
	return is;
}

ostream& operator << (ostream &os, const __int128 &x) {
	os << (long long)x;
	return os;
}

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

ll guessedNumber;

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

#ifndef TESTING
int ask(ll x) {
	assert(x <= (ll)1e18);
	cout << "? " << x << endl;
	int res;
	cin >> res;
	return res;
}
#else
int ask(ll x) {
	return gcd(x, guessedNumber);
}
#endif

int numberOfDivisors(int x) {
	int res = 0;
	for (int i = 1; i * i <= x; ++i) {
		if (x % i == 0) {
			if (i * i == x) {
				res++;
			} else {
				res += 2;
			}
		}
	}
	return res;
}

void guess(int ans) {
	cout << "! " << ans << endl;
	#ifdef TESTING
	int realAns = numberOfDivisors(guessedNumber);
	// cerr << "realAns = " << realAns << endl;
	assert(abs(realAns - ans) <= 7 || (ans * 2 >= realAns && realAns * 2 >= ans));
	#endif
}

const int Q1 = 17;
const int MAX_P = 10000;
const ll C = 1e18;

vector<int> primes;

int isPrime(int x) {
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			return 0;
		}
	}
	return 1;
}

void gen_primes() {
	for (int i = 2; i <= MAX_P; ++i) {
		if (isPrime(i)) {
			primes.push_back(i);
		}
	}
}

vector<vector<int> > prime_packs;
vector<ll> packs_product;

void init() {
	gen_primes();
	int ptr = 0;
	for (int i = 0; i < Q1; ++i) {
		ll prod = 1;
		prime_packs.push_back(vector<int> ());
		for (; ; ++ptr) {
			prod *= (ll)primes[ptr];
			if (prod > C) {
				break;
			} else {
				prime_packs.back().push_back(primes[ptr]);
			}
		}
		prod = 1;
		for (auto x : prime_packs.back()) {
			prod *= x;
		}
		packs_product.push_back(prod);
	}
	// for (auto v : prime_packs) {
	// 	output(all(v));
	// }
}

vector<int> poss_primes;

void search_primes() {
	for (int i = 0; i < Q1; ++i) {
		int res = ask(packs_product[i]);
		for (auto p : prime_packs[i]) {
			if (res % p == 0) {
				poss_primes.push_back(p);
			}
		}
	}
}

int number, div_cnt;

int degree(int x, int p) {
	int res = 0;
	while (x % p == 0) {
		x /= p;
		res++;
	}
	return res;
}

int power(int a, int deg) {
	int res = 1;
	for (int i = 0; i < deg; ++i) {
		res *= a;
	}
	return res;
}

void guess_number() {
	ll all_product = 1;
	for (auto p : poss_primes) {
		all_product *= (ll)p;
	}
	number = 1;
	div_cnt = 1;
	for (int deg = 2; deg <= 32; deg <<= 1) {
		all_product *= all_product;
		int res = ask(all_product);
		vector<int> new_poss_primes;
		all_product = 1;
		for (auto p : poss_primes) {
			int cur_deg = degree(res, p);
			if (cur_deg < deg) {
				number *= power(p, cur_deg);
				div_cnt *= (cur_deg + 1);
			} else {
				all_product *= power(p, deg);
				new_poss_primes.push_back(p);
			}
		}
		poss_primes = new_poss_primes;
	}
}

void solve() {
	poss_primes.clear();
	search_primes();
	// cerr << "poss_primes" << endl;
	// output(all(poss_primes));
	guess_number();
	if (number > 3) {
		guess(div_cnt * 2);
	} else {
		if (number == 1) {
			guess(8);
		} else {
			guess(9);
		}
	}
}

signed main() {
	fast_io();

	init();

	int T;
	cin >> T;
	while (T--) {
		#ifdef TESTING
		cin >> guessedNumber;
		#endif
		solve();
	}
}