/*

Code for problem B by cookiedoth
Generated 02 Feb 2020 at 05.24 P


  !











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

const int K = 26;
const int mx = 2e5 + 228;
int n, q, pref[K][mx];
string s;

signed main() {
	fast_io();
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < K; ++j) {
			pref[j][i + 1] = pref[j][i];
		}
		pref[s[i] - 'a'][i + 1]++;
	}
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		int cnt = 0;
		for (int j = 0; j < K; ++j) {
			if (pref[j][r + 1] != pref[j][l]) {
				cnt++;
			}
		}
		if (l == r) {
			cout << "Yes\n";
			continue;
		}
		if (cnt >= 3) {
			cout << "Yes\n";
			continue;
		}
		if (cnt == 1) {
			cout << "No\n";
			continue;
		}
		if (cnt == 2 && s[l] == s[r]) {
			cout << "No\n";
		} else {
			cout << "Yes\n";
		}
	}
}