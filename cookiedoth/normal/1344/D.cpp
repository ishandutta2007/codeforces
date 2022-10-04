/*

Code for problem D by cookiedoth
Generated 06 May 2020 at 06.24 PM



10%

30%

50%

70%

100%

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

const int mx = 1e5 + 228;
int n;
ll A[mx], k;

void read() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
}

ll func(ll a, ll b) {
	return b * (a - b * b);
}

ll find_bound(ll a, ll bound) {
	ll l = 0, r = a;
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (func(a, mid + 1) - func(a, mid) >= bound) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return l;
}

ll apply_bound(ll bound, ll *cnt) {
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		res += (cnt[i] = find_bound(A[i], bound));
	}
	return res;
}

ll cnt[mx], cnt2[mx];
const ll INF = 1e30;

void solve() {
	ll l = -INF, r = INF;
	while (l < r) {
		ll mid = (l + r) >> 1;
		ll res = apply_bound(mid, cnt);
		if (res <= k) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	ll res = apply_bound(l, cnt);
	if (res < k) {
		apply_bound(l - 1, cnt2);
		for (int i = 0; i < n; ++i) {
			ll ch = min(k - res, cnt2[i] - cnt[i]);
			cnt[i] += ch;
			res += ch;
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << cnt[i] << " ";
	}
	cout << '\n';
}

signed main() {
	fast_io();
	read();
	solve();
}