/*

Code for problem A by savkinsd2089
Generated 18 Nov 2018 at 06.41 pm
The Moon is Waxing Gibbous (78% of Full)


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

\_()_/
^_^
^_^

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
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define y1 Y1

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
	ld x, y;
	vect(): x(0), y(0) {}
	vect(ld _x, ld _y): x(_x), y(_y) {}
};

ld sq(ld x) {
	return x * x;
}

ld distance(vect a, vect b) {
	return sqrt(sq(a.x - b.x) + sq(a.y - b.y));
}

bool operator == (vect a, vect b) {
	return a.x == b.x && a.y == b.y;
}

const ld EPS = 1e-9;
const ld INF = 1e18;
vect FAKE(INF, INF);
ld a, b, c;
ld x1, y1, x2, y2;

ld dist;
ld ans = INF;

vect intersect_x(ld x, ld y) {
	ld val = -c - a * x;
	if (fabs(b) < EPS) {
		if (fabs(val) < EPS) {
			return vect(x, -c / a);
		}
		else {
			dist += INF;
			return FAKE;
		}
	}
	else {
		dist += fabs(y - val / b);
		return vect(x, val / b);
	}
}

vect intersect_y(ld x, ld y) {
	ld val = -c - b * y;
	if (fabs(a) < EPS) {
		if (fabs(val) < EPS) {
			return vect(-c / b, y);
		}
		else {
			dist += INF;
			return FAKE;
		}
	}
	else {
		dist += fabs(val / a - x);
		return vect(val / a, y);
	}
}

signed main() {
	cin >> a >> b >> c;
	cin >> x1 >> y1 >> x2 >> y2;
	chkmin(ans, fabs(x1 - x2) + fabs(y1 - y2));

	dist = 0;
	vect v1 = intersect_x(x1, y1);
	vect v2 = intersect_x(x2, y2);
	dist += distance(v1, v2);
	chkmin(ans, dist);

	dist = 0;
	v1 = intersect_y(x1, y1);
	v2 = intersect_x(x2, y2);
	dist += distance(v1, v2);
	chkmin(ans, dist);

	dist = 0;
	v1 = intersect_x(x1, y1);
	v2 = intersect_y(x2, y2);
	dist += distance(v1, v2);
	chkmin(ans, dist);

	dist = 0;
	v1 = intersect_y(x1, y1);
	v2 = intersect_y(x2, y2);
	dist += distance(v1, v2);
	chkmin(ans, dist);

	cout << setprecision(10) << ans << endl;
}