/*

Code for problem E by cookiedoth
Generated 27 Jul 2020 at 12.53 PM










(@)(@)(@)(@)(@)

=_=
\_()_/
o_O

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
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

void subt(int &a, int b) {
	a -= b;
	if (a < 0) {
		a += MOD;
	}
}

int n, ones_sum, zeros_sum, head = -1, pos, first_zero;
string s;
vector<int> zeros, nxt;

void add0() {
	if (first_zero) {
		pos = zeros.size();
		first_zero = 0;
	}
	add(zeros_sum, ones_sum);
	zeros.push_back(ones_sum);
	nxt.push_back(head);
	head = (int)zeros.size() - 1;
	if (nxt[pos] != -1) {
		subt(zeros_sum, zeros[nxt[pos]]);
		nxt[pos] = nxt[nxt[pos]];
	}
}

void add1() {
	add(ones_sum, zeros_sum + 1);
	first_zero = 1;
}

int mult = 1, mult2 = 1;

void read() {
	cin >> s;
	n = s.size();
	int pref_len = 0, suf_len = 0;
	while (pref_len < n && s[pref_len] == '0') {
		pref_len++;
		mult++;
	}
	while (suf_len < n && s[n - 1 - suf_len] == '0') {
		suf_len++;
		mult2++;
	}
	if (pref_len == n) {
		cout << n << '\n';
		exit(0);
	}
	s.substr(pref_len, n - suf_len - pref_len);
	n = s.size();
}

void solve() {
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') {
			add1();
		} else {
			add0();
		}
	}
}

void calc_ans() {
	int ans = ones_sum;
	ans = mul(ans, mult);
	ans = mul(ans, mult2);
	cout << ans << '\n';
}

signed main() {
	fast_io();
	read();
	solve();
	calc_ans();
}