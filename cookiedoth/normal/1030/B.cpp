/*

Code for problem B by savkinsd2089
Generated 23 Sep 2018 at 04.07 pm
The Moon is Waxing Gibbous (98% of Full)










(@)(@)(@)(@)(@)

o_O
\_()_/
o_O

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
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
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)

#ifndef TESTING
	#define endl '\n'
#endif

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

struct vect {
	ll x, y;
	vect(): x(0), y(0) {}
	vect(ll _x, ll _y): x(_x), y(_y) {}
};

vect operator + (vect a, vect b) {
	return vect(a.x + b.x, a.y + b.y);
}

vect operator - (vect a, vect b) {
	return vect(a.x - b.x, a.y - b.y);
}

ll operator * (vect a, vect b) {
	return a.x * b.x + a.y * b.y;
}

ll operator / (vect a, vect b) {
	return a.x * b.y - a.y * b.x;
}

bool operator == (vect a, vect b) {
	return a.x == b.x && a.y == b.y;
}

bool operator != (vect a, vect b) {
	return !(a == b);
}

istream& operator >> (istream &is, vect &p) {
	is >> p.x >> p.y;
	return is;
}

ostream& operator << (ostream &os, vect &p) {
	os << p.x << " " << p.y;
	return os;
}

typedef vector<vect> polygon;

int sign(ll x) {
	if (x > 0)
		return 1;
	if (x < 0)
		return -1;
	return 0;
}

int in_polygon(vect p, polygon a) {
	a.push_back(a[0]);
	int n = a.size() - 1;
	vector<ll> x;
	for (int i = 0; i < n; ++i) {
		x.push_back((a[i + 1] - a[i]) / (p - a[i]));
	}
	for (int i = 0; i < (int)x.size() - 1; ++i) {
		if (sign(x[i]) * sign(x[i + 1]) < 0)
			return 0;
	}
	return 1;
}

signed main() {
	int n, d, m;
	cin >> n >> d >> m;
	polygon a = {{0, d}, {d, 0}, {n, n - d}, {n - d, n}};
	for (int i = 0; i < m; ++i) {
		vect p;
		cin >> p;
		if (in_polygon(p, a))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}