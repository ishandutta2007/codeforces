/*

Code for problem C by cookiedoth
Generated 19 Apr 2021 at 04.39 PM



10%

30%

50%

70%

100%

\_()_/
^_^
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
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
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

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int n, s;
vector<int> elem, pref, suf;

int mul(int a, int b) {
	return (1LL * a * b) % n;
}

void adjust() {
	s = elem.size();
	output(all(elem));
	pref.resize(s + 1);
	suf.resize(s + 1);
	pref[0] = suf[0] = 1;
	for (int i = 0; i < s; ++i) {
		pref[i + 1] = mul(pref[i], elem[i]);
		suf[i + 1] = mul(suf[i], elem[s - 1 - i]);
	}
	for (int i = 0; i < s; ++i) {
		if (mul(pref[i], suf[s - 1 - i]) == 1) {
			elem.erase(elem.begin() + i);
			return;
		}
	}
	assert(0);
}

signed main() {
	fast_io();
	cin >> n;
	int prod = 1;
	for (int i = 1; i < n; ++i) {
		if (gcd(i, n) == 1) {
			elem.push_back(i);
			prod = mul(prod, i);
		}
	}
	if (prod != 1) {
		adjust();
	}
	cout << elem.size() << '\n';
	output(all(elem), cout);
}