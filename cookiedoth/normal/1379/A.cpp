/*

Code for problem A by cookiedoth
Generated 20 Jul 2020 at 01.24 PM


 ] 
 
Il] 


^_^
~_^
=_=

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

string pattern = "abacaba";
char other = 'd';

void no() {
	cout << "No\n";
}

int check(string s) {
	int real_occ = 0;
	int n = s.size();
	for (int i = 0; i <= n - (int)pattern.size(); ++i) {
		int is_real = 1;
		for (int j = 0; j < pattern.size(); ++j) {
			if (pattern[j] != s[i + j]) {
				is_real = 0;
			}
		}
		real_occ += is_real;
	}
	return real_occ;
}

void solve() {
	string s;
	int n;
	cin >> n;
	cin >> s;
	int real_occ = 0, q_occ = 0, first_q_occ = -1;
	vector<int> q_occ_v;
	for (int i = 0; i <= n - (int)pattern.size(); ++i) {
		int is_real = 1, is_q = 1;
		for (int j = 0; j < pattern.size(); ++j) {
			if (pattern[j] != s[i + j]) {
				is_real = 0;
			}
			if (s[i + j] != '?' && pattern[j] != s[i + j]) {
				is_q = 0;
			}
		}
		real_occ += is_real;
		if (is_q) {
			q_occ++;
			q_occ_v.push_back(i);
		}
	}
	if (real_occ >= 2) {
		no();
		return;
	}
	if (real_occ == 0 && q_occ == 0) {
		no();
		return;
	}
	if (real_occ == 0) {
		int got = 0;
		for (auto pos : q_occ_v) {
			string t = s;
			for (int i = 0; i < pattern.size(); ++i) {
				t[pos + i] = pattern[i];
			}
			for (int i = 0; i < n; ++i) {
				if (t[i] == '?') {
					t[i] = other;
				}
			}
			if (check(t) == 1) {
				got = 1;
				s = t;
				break;
			}
		}
		if (got == 0) {
			no();
			return;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (s[i] == '?') {
			s[i] = other;
		}
	}
	cout << "Yes\n";
	cout << s << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}