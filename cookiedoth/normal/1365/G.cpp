/*

Code for problem G by cookiedoth
Generated 07 Jun 2020 at 07.25 PM



10%

30%

50%

70%

100%

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

const int mx = 1010;
const int B = 13;
const int B1 = 6;
const int CB = 63;
int n, mask[mx];
ll real_mask[CB], ans[mx];

ll ask(vector<int> v) {
	if (!v.empty()) {
		cout << "? " << v.size();
		for (auto x : v) {
			cout << " " << x + 1;
		}
		cout << endl;
		ll res;
		cin >> res;
		return res;
	} else {
		return 0;
	}
}

signed main() {
	fast_io();
	cin >> n;
	int ptr = 0;
	for (int i = 0; i < (1 << B); ++i) {
		if (__builtin_popcount(i) == B1 && ptr < n) {
			mask[ptr++] = i;
		}
	}
	for (int it = 0; it < B; ++it) {
		vector<int> cur;
		for (int i = 0; i < n; ++i) {
			if ((mask[i] >> it) & 1) {
				cur.push_back(i);
			}
		}
		ll res = ask(cur);
		for (int b = 0; b < CB; ++b) {
			if ((res >> b) & 1LL) {
				real_mask[b] |= (1LL << it);
			}
		}
	}
	for (int b = 0; b < CB; ++b) {
		if (real_mask[b]) {
			for (int i = 0; i < n; ++i) {
				if (mask[i] != real_mask[b]) {
					ans[i] ^= (1LL << b);
				}
			}
		}
	}
	cout << "!";
	for (int i = 0; i < n; ++i) {
		cout << " " << ans[i];
	}
	cout << endl;
}