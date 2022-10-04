/*

Code for problem  by cookiedoth
Generated 04 Jul 2020 at 07.50 PM


  !











^_^
-_-
z_z

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

ll a, b, c;
vector<ll> v;

pair<ll, ll> find_diff() {
	vector<ll> v2 = v;
	sort(all(v2));
	return {v2[1] - v2[0], v2[2] - v2[1]};
}

void read() {
	cin >> a >> b >> c;
	v = {a, b, c};
}

void query(ll t) {
	cout << t << endl;
	int pos;
	cin >> pos;
	if (pos == 0) {
		exit(0);
	}
	pos--;
	v[pos] += t;
}

signed main() {
	fast_io();
	read();
	cout << "First" << endl;
	pair<ll, ll> pp = find_diff();
	cerr << pp.first << " " << pp.second << endl;
	query(pp.first + pp.second);
	pp = find_diff();
	query(pp.first + 2 * pp.second);
	pp = find_diff();
	query(pp.first);
	assert(0);
	// while (true) {
	// 	pair<ll, ll> p = find_diff();
	// 	if (p.first < p.second) {
	// 		query(p.second);
	// 	}
	// 	ll b = max(p.first, p.second), s = min(p.first, p.second);
	// 	if (p.first == p.second) {
	// 		query(p.first);
	// 	}
	// 	if (p.first % p.second == 0 || p.second % p.first == 0) {
	// 		query(p.first + p.second);
	// 	}
	// 	if ((b - s) % s == 0) {
	// 		query(s);
	// 	}
	// 	ll d = b / s;
	// 	ll t = d * s;
	// 	while (t < b + s) {
	// 		t += s;
	// 	}
	// 	query(t);
	// 	output(all(v));
	// }
}