/*

Code for problem E by savkinsd2089
Generated 08 Aug 2018 at 09.00 pm
The Moon is Waning Crescent (10% of Full)


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

=_=
z_z
\_()_/

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

int half_plane(vect p) {
	return (p.y < 0 || (p.y == 0 && p.x < 0));
}

bool operator < (vect a, vect b) {
	int pa = half_plane(a), pb = half_plane(b);
	if (pa < pb)
		return 1;
	if (pa > pb)
		return 0;
	if (a / b == 0) {
		return (a * a < b * b);
	}
	return a / b > 0;
}

bool same_dir(vect a, vect b) {
	return !(a < b) && !(b < a);
}

ll norm(vect a) {
	return a * a;
}

typedef vector<vect> polygon;

istream& operator >> (istream &is, polygon &a) {
	int n;
	is >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		is >> a[i];
	}
	return is;
}

ostream& operator << (ostream &os, polygon &a) {
	for (int i = 0; i < (int)a.size(); ++i) {
		os << a[i] << endl;
	}
	return os;
}

void shift(polygon &a) {
	int n = a.size();
	int best_pt = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i].y < a[best_pt].y || (a[i].y == a[best_pt].y && a[i].x < a[best_pt].x))
			best_pt = i;
	}
	vector<vect> b;
	for (int i = best_pt; i < best_pt + n; ++i) {
		b.push_back(a[i % n]);
	}
	a = b;
}

bool pair_cmp(vect a, vect b) {
	return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}

vect BASE;

bool polar_cmp(vect a, vect b) {
	return (a - BASE) < (b - BASE) || (same_dir(a - BASE, b - BASE) && norm(a - BASE) < norm(b - BASE));
}

vector<vect> convex_hull(vector<vect> v) {
	sort(v.begin(), v.end(), pair_cmp);
	v.erase(unique(v.begin(), v.end()), v.end());
	int n = v.size();
	shift(v);
	vector<vect> st;
	st.push_back(v[0]);
	BASE = v[0];
	sort(v.begin(), v.end(), polar_cmp);
	for (int i = 1; i < n; ++i) {
		int sts = st.size();
		while (sts > 1 && (st[sts - 1] - st[sts - 2]) / (v[i] - st[sts - 1]) <= 0) {
			st.pop_back();
			sts = st.size();
		}
		st.push_back(v[i]); 
	}
	return st;
}

const ld pi = acos(-1);

ld get_polar(vect a) {
	ld res = atan2(a.x, a.y);
	if (res < 0)
		res += 2 * pi;
	return res;
}

typedef pair<ll, ld> base;
const ld EPS = 1e-9;

base get(polygon &a, int pos) {
	int n = a.size();
	ll dist = norm(a[(pos + 1) % n] - a[pos]);
	ld angle = get_polar(a[(pos + 1) % n] - a[pos]) - get_polar(a[(pos - 1 + n) % n] - a[pos]);
	while (angle < 0)
		angle += 2 * pi;
	while (angle >= 2 * pi - EPS)
		angle -= 2 * pi;
	return {dist, angle};
}

vector<int> prefix_function (vector<int> &s) {
	int n = (int) s.size();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

vector<base> all0, all;
vector<base> _a, _b;
vector<int> a1, b1, p;

int n, m, sz;
polygon a, b;

void check() {
	for (int i = 0; i < sz; ++i) {
		base B = get(a, i);
		_a.push_back(B);
		all0.push_back(B);
	}
	for (int i = 0; i < sz; ++i) {
		base B = get(b, i);
		_b.push_back(B);
		all0.push_back(B);
	}
	/*cerr << "_a" << endl;
	for (int i = 0; i < sz; ++i) {
		cerr << _a[i].first << " ";
	}
	cerr << endl;
	for (int i = 0; i < sz; ++i) {
		cerr << _a[i].second << " ";
	}
	cerr << endl;
	cerr << "_b" << endl;
	for (int i = 0; i < sz; ++i) {
		cerr << _b[i].first << " ";
	}
	cerr << endl;
	for (int i = 0; i < sz; ++i) {
		cerr << _b[i].second << " ";
	}
	cerr << endl;*/
	base last = {-1, 0};
	sort(all0.begin(), all0.end());
	for (int i = 0; i < 2 * sz; ++i) {
		if (all0[i].first > last.first || all0[i].second > last.second + EPS) {
			all.push_back(all0[i]);
			all.back().second += EPS;
			last = all0[i];
		}
	}
	for (int i = 0; i < sz; ++i) {
		a1.push_back(lower_bound(all.begin(), all.end(), _a[i]) - all.begin());
	}
	for (int i = 0; i < sz; ++i) {
		b1.push_back(lower_bound(all.begin(), all.end(), _b[i]) - all.begin());
	}
	for (int i = 0; i < sz; ++i) {
		p.push_back(b1[i]);
	}
	p.push_back(-1);
	for (int i = 0; i < 2 * sz; ++i) {
		p.push_back(a1[i % sz]);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	a = convex_hull(a);
	b = convex_hull(b);
	/*cerr << "a" << endl;
	cerr << a << endl;
	cerr << "b" << endl;
	cerr << b << endl;*/
	if (a.size() != b.size()) {
		cout << "NO" << endl;
		return 0;
	}
	sz = a.size();

	check();
	vector<int> pref = prefix_function(p);
	int max_el = (*max_element(pref.begin(), pref.end()));
	if (max_el == sz)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	//cerr << "a" << endl;
	//cerr << a << endl;
	//cerr << "b" << endl;
	//cerr << b << endl;
}