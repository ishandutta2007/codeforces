/*

Code for problem  by cookiedoth
Generated 10 Oct 2020 at 07.07 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

=_=
\_()_/
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
#include <random>
#include <utility>
#include <tuple>
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

set<int> numbers;
vector<string> ans;

void print_ans() {
	cout << ans.size() << '\n';
	for (auto s : ans) {
		cout << s << '\n';
	}
	exit(0);
}

void add_xor(ll a, ll b) {
	if (a == 0 || b == 0) {
		return;
	}
	assert(numbers.find(a) != numbers.end());
	assert(numbers.find(b) != numbers.end());
	ans.push_back(to_string(a) + " ^ " + to_string(b));
	numbers.insert(a ^ b);
	if ((a ^ b) == 1) {
		print_ans();
	}
}

void add_sum(ll a, ll b) {
	if (a == 0 || b == 0) {
		return;
	}
	assert(numbers.find(a) != numbers.end());
	assert(numbers.find(b) != numbers.end());
	ans.push_back(to_string(a) + " + " + to_string(b));
	numbers.insert(a + b);
	if (a + b == 1) {
		print_ans();
	}
}

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

ll linear_gcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll g = linear_gcd(b, a % b, x, y);
	ll _x = x;
	x = y;
	y = _x - a / b * y;
	return g;
}

void multiply(ll a, ll mul) {
	ll res = 0;
	for (; mul; add_sum(a, a), a *= 2, mul >>= 1) {
		if (mul & 1) {
			add_sum(res, a);
			res += a;
		}
	}
}

ll x, y, cx, cy;

ll get(ll cx0, ll cy0, ll delta) {
	cx0 += delta * cx;
	cy0 += delta * cy;
	multiply(x, cx0);
	multiply(y, cy0);
	add_sum(x * cx0, y * cy0);
	return x * cx0 + y * cy0;
}

signed main() {
	fast_io();
	cin >> x;
	numbers.insert(x);
	for (ll n = 1; ; ++n) {
		y = ((x * n) ^ (x * (n + 1)));
		if (gcd(x, y) == 1) {
			// cerr << "n = " << n << endl;
			multiply(x, n);
			add_sum(x * n, x);
			add_xor(x * n, x * (n + 1));
			break;
		}
	}
	linear_gcd(x, y, cx, cy);
	ll dcx = cx / y;
	cx -= dcx * y;
	cy += dcx * x;
	if (cx < 0) {
		cx += y;
		cy -= x;
	}
	ll val1 = get(0, 2 * x, 0);
	ll val2 = get(0, 2 * x, 1);
	add_xor(val1, val2);
	assert(0);
}