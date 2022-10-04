/*

Code for problem D by cookiedoth
Generated 26 May 2020 at 07.17 PM


 ] 
 
Il] 


-_-
z_z
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

int n;
ll x;
vector<ll> points;

void read() {
	cin >> n >> x;
	ll sum = 0;
	points.push_back(sum);
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		sum += x;
		points.push_back(sum);
	}
	for (int i = 1; i <= n; ++i) {
		points.push_back(sum + points[i]);
	}
}

ll init_val, ans;
ll L, R;

void calc_init_val() {
	L = 0;
	R = x;
	for (int i = 0; i < 2 * n; ++i) {
		ll cnt = min(points[i + 1] - points[i], x - points[i]);
		if (cnt > 0) {
			init_val += cnt * (cnt + 1) / 2;
		}
	}
}

ll func(ll x) {
	return x * (x + 1) / 2;
}

void update(ll s1, ll s2, ll t) {
	init_val -= (func(s1 + t) - func(s1));
	init_val += (func(s2 + t) - func(s2));
	chkmax(ans, init_val);
}

void process() {
	ans = init_val;
	while (R < points.back()) {
		int pL = upper_bound(all(points), L) - points.begin();
		int pR = upper_bound(all(points), R) - points.begin();
		ll t = min(points[pL] - L, points[pR] - R);
		update(L - points[pL - 1], R - points[pR - 1], t);
		L += t;
		R += t;
	}
}

signed main() {
	fast_io();
	read();
	calc_init_val();
	process();
	cout << ans << endl;
}