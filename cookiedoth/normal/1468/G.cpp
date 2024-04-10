/*

Code for problem G by cookiedoth
Generated 07 Sep 2021 at 05.27 PM


  !
 
                                    
                          
                  




















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
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define length(a) (int)a.size()

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

struct pt {
	ll x, y;

	pt(): x(0), y(0) {}
	pt(ll _x, ll _y): x(_x), y(_y) {}
};

pt operator + (pt a, pt b) {
	return pt(a.x + b.x, a.y + b.y);
}

pt operator - (pt a, pt b) {
	return pt(a.x - b.x, a.y - b.y);
}

ll operator * (pt a, pt b) {
	return a.x * b.x + a.y * b.y;
}

ll operator / (pt a, pt b) {
	return a.x * b.y - a.y * b.x;
}

istream& operator >> (istream &is, pt &p) {
	is >> p.x >> p.y;
	return is;
}

ostream& operator << (ostream &os, const pt &p) {
	os << p.x << " " << p.y;
	return os;
}

int half_plane(pt a) {
	return (a.y > 0 || (a.y == 0 && a.x > 0)) ^ 1;
}

bool polar_cmp(pt a, pt b) {
	int ha = half_plane(a), hb = half_plane(b);
	if (ha < hb) {
		return 1;
	}
	if (ha > hb) {
		return 0;
	}
	return (a / b > 0);
}

void construct_line(pt p1, pt p2, ld& a, ld& b, ld& c) {
	a = p1.y - p2.y;
	b = p2.x - p1.x;
	c = p1.x * a + p1.y * b;
}

pair<ld, ld> intersect_lines(ld a1, ld b1, ld c1, ld a2, ld b2, ld c2) {
	ld det = a1 * b2 - a2 * b1;
	assert(fabsl(det) > 1e-9);
	ld x = (c1 * b2 - c2 * b1) / det;
	ld y = (a1 * c2 - a2 * c1) / det;
	// cerr << "check " << a1 * x + b1 * y - c1 << ' ' << a2 * x + b2 * y - c2 << '\n';
	return {x, y};
}

pair<ld, ld> intersect_lines(pt p1, pt p2, pt p3, pt p4) {
	ld a1, b1, c1;
	ld a2, b2, c2;
	construct_line(p1, p2, a1, b1, c1);
	construct_line(p3, p4, a2, b2, c2);
	// cerr << "construct_line " << a1 << ' ' << b1 << ' ' << c1 << '\n';
	// cerr << "construct_line " << a2 << ' ' << b2 << ' ' << c2 << '\n';
	return intersect_lines(a1, b1, c1, a2, b2, c2);
}

ld sqr(ld x) {
	return x * x;
}

int n;
ll H;
vector<pt> polyline;

signed main() {
	fast_io();
	cout << setprecision(10) << fixed;
	cin >> n >> H;
	polyline.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> polyline[i];
	}
	pt eye(polyline[n - 1].x, polyline[n - 1].y + H);
	pt p(0, -1);
	ld ans = 0;
	for (int i = n - 2; i >= 0; --i) {
		pt cur = polyline[i] - eye;
		if (polar_cmp(cur, p)) {
			// cerr << "intersection\n";
			// cerr << polyline[i + 1] << ' ' << polyline[i] << '\n';
			// cerr << eye << ' ' << eye + p << '\n';
			pair<ld, ld> inter = intersect_lines(polyline[i + 1], polyline[i], eye, eye + p);
			// cerr << "i see segement from " << inter.first << ' ' << inter.second << " to " << polyline[i] << '\n';
			ans += sqrtl(sqr(inter.first - polyline[i].x) + sqr(inter.second - polyline[i].y));
			p = cur;
		} else if (!polar_cmp(p, cur) && !polar_cmp(cur, p) && p / (polyline[i + 1] - polyline[i]) == 0) {
			ans += sqrtl(sqr(polyline[i + 1].x - polyline[i].x) + sqr(polyline[i + 1].y - polyline[i].y));
		}
	}
	cout << ans << '\n';
}