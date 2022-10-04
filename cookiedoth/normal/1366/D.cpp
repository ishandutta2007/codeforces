/*

Code for problem D by cookiedoth
Generated 11 Jun 2020 at 09.38 PM










(@)(@)(@)(@)(@)

o_O
^_^
~_^

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

const int N = 1e7 + 10;
int lp[N+1];
vector<int> pr;

void sieve() {
	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back (i);
		}
		for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

const int mx = 5e5 + 228;
int n, d1[mx], d2[mx];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		int p = lp[x];
		d1[i] = 1;
		while (lp[x] == p) {
			d1[i] *= p;
			x /= p;
		}
		if (x == 1) {
			d1[i] = -1;
			d2[i] = -1;
		} else {
			d2[i] = x;
		}
	}
}

void print() {
	output(d1, d1 + n, cout);
	output(d2, d2 + n, cout);
}

signed main() {
	fast_io();
	sieve();
	solve();
	print();
}