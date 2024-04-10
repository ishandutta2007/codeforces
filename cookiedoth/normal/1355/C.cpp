/*

Code for problem C by cookiedoth
Generated 16 May 2020 at 04.07 PM


  !











~_^
z_z
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

ll A, B, C, D;

ll calc(ll n, ll m, ll s) {
	// cerr << "calc " << n << " " << m << " " << s << endl;
	if (s < 0) {
		return 0;
	}
	if (n > m) {
		swap(n, m);
	}
	if (s < n) {
		return (s + 1) * (s + 2) / 2;
	}
	if (s >= n && s <= m) {
		return (n + 1) * (n + 2) / 2 + (n + 1) * (s - n);
	}
	return (n + 1) * (m + 1) - calc(n, m, n + m - s - 1);
}

signed main() {
	fast_io();
	cin >> A >> B >> C >> D;
	ll ans = 0;
	for (ll z = C; z <= D; ++z) {
		ans += calc(B - A, C - B, z - A - B);
	}
	ans = (B - A + 1) * (C - B + 1) * (D - C + 1) - ans;
	cout << ans << endl;
}