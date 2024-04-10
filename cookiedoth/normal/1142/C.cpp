/*

Code for problem C by cookiedoth
Generated 01 Apr 2019 at 09.10 P


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

o_O
-_-
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
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
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

struct pt {
	ll x, y;
	pt(ll _x, ll _y): x(_x), y(_y) {}
	pt(): x(0), y(0) {}
};

pt operator - (pt a, pt b) {
	return pt(a.x - b.x, a.y - b.y);
}

ld operator * (pt a, pt b) {
	return (ld)a.x * (ld)b.x + (ld)a.y * (ld)b.y;
}

ld operator / (pt a, pt b) {
	return (ld)a.x * (ld)b.y - (ld)a.y * (ld)b.x;
}

bool operator < (pt a, pt b) {
	return make_pair(a.y, a.x) < make_pair(b.y, b.x);
}

bool operator == (pt a, pt b) {
	return !(a < b) && !(b < a);
}

ld len(pt a) {
	return a * a;
}

istream& operator >> (istream &is, pt &p) {
	is >> p.x >> p.y;
	return is;
}

ostream& operator << (ostream &os, pt &p) {
	os << p.x << " " << p.y;
	return os;
}

pt base;
const ld EPS = 1e-9;

bool base_polar_cmp(pt a, pt b) {
	ld cross = (a - base) / (b - base);
	return (cross > EPS || (fabs(cross) < EPS && len(a - base) < len(b - base)));
}

vector<pt> convex_hull(vector<pt> &a) {
	sort(all(a));
	a.erase(unique(all(a)), a.end());
	base = a[0];
	sort(a.begin() + 1, a.end(), base_polar_cmp);
	vector<pt> st;
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		while (st.size() >= 2) {
			pt last = st.back() - st[st.size() - 2];
			pt next_vect = a[i] - st.back();
			if (last / next_vect < EPS) {
				st.pop_back();
			}
			else {
				break;
			}
		}
		st.push_back(a[i]);
	}
	return st;
}

const ll INF = 2e12;

signed main() {
	fast_io();
	ll x_min = INF, x_max = -INF;
	int n;
	cin >> n;
	vector<pt> a;
	for (int i = 0; i < n; ++i) {
		ll x, y;
		cin >> x >> y;
		//cerr << x << " " << y << endl;
		chkmin(x_min, x);
		chkmax(x_max, x);
		y -= x * x;
		a.push_back({x, y});
	}
	x_max += 1;
	x_min -= 1;
	a.push_back({x_min, -INF});
	a.push_back({x_max, -INF});
	a = convex_hull(a);
	int ans = (int)a.size() - 3;
	cout << ans << endl;
}