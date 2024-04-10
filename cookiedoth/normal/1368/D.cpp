/*

Code for problem D by cookiedoth
Generated 18 Jun 2020 at 06.02 PM


  !











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

const int B = 20;
int n;
vector<ll> a;

signed main() {
	fast_io();
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> cnt(B);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < B; ++j) {
			cnt[j] += ((a[i] >> j) & 1);
		}
	}
	vector<ll> b(n);
	for (int i = 0; i < B; ++i) {
		for (int j = 0; j < cnt[i]; ++j) {
			b[j] |= (1 << i);
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += b[i] * b[i];
	}
	cout << ans << endl;
}