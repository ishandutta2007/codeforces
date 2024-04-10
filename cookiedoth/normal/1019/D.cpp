/*

Code for problem D by savkinsd2089
Generated 12 Aug 2018 at 07.13 pm
The Moon is Waxing Crescent (2% of Full)










(@)(@)(@)(@)(@)

z_z
\_()_/
>_<

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

vect rotatem90(vect a) {
	return vect(a.y, -a.x);
}

struct line {
	ld A, B, C;
	//vect v;

	line() {}

	line(vect v1, vect v2) {
		//cerr << "making line " << v1 << " " << v2 << endl;
		A = v1.y - v2.y;
		B = v2.x - v1.x;
		C = -(ld)v1.x * A - (ld)v1.y * B;
		ld nrm = sqrt(A * A + B * B);
		A /= nrm;
		B /= nrm;
		C /= nrm;
		//v = v2 - v1;
		//cerr << A << " " << B << " " << C << endl;
	}

	ld get(vect v) {
		return (A * (ld)v.x + B * (ld)v.y + C);
	}
};

ostream& operator << (ostream &os, line &l) {
	os << l.A << " " << l.B << " " << l.C;
	return os;
}

bool operator < (line a, line b) {
	return rotatem90(vect(a.A, a.B)) < rotatem90(vect(b.A, b.B));
}

bool ycmp(vect a, vect b) {
	return make_pair(a.y, a.x) < make_pair(b.y, b.x);
}

bool pycmp(pair<vect, int> a, pair<vect, int> b) {
	return ycmp(a.first, b.first);
}

struct event {
	line l;
	int i, j;
};

const ld EPS = 1e-8;
int n;
ld S;
vector<vect> a, _a;
vector<int> p;
vector<event> ev;
vector<pair<vect, int> > vp;

bool operator < (event e1, event e2) {
	return (a[e1.j] - a[e1.i]) < (a[e2.j] - a[e2.i]);
}

void my_swap(int i, int j) {
	int pi = p[i];
	int pj = p[j];
	swap(a[pi], a[pj]);
	p[i] = pj;
	p[j] = pi;
}

ld length(vect v) {
	return sqrt(norm(v));
}

signed main() {
	cin >> n >> S;

	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		vp.push_back({a[i], i});
	}
	_a = a;

	ev.reserve(n * n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j && half_plane(a[j] - a[i]) == 0) {
				ev.push_back({line(a[i], a[j]), i, j});
			}
		}
	}

	p.resize(n);
	iota(p.begin(), p.end(), 0);

	sort(all(ev));
	sort(all(vp), pycmp);

	for (int i = 0; i < n; ++i) {
		a[i] = vp[i].first;
		p[vp[i].second] = i;
	}
	for (int i = 0; i < ev.size(); ++i) {
		ld h = 2 * S / length(_a[ev[i].i] - _a[ev[i].j]);
		int l = 0, r = n - 1;
		while (r > l) {
			int mid = (l + r) >> 1;
			ld cur_h = ev[i].l.get(a[mid + 1]);
			if (cur_h > h + EPS)
				r = mid;
			else
				l = mid + 1;
		}
		ld cur_h = ev[i].l.get(a[l]);
		if (abs(h - cur_h) < EPS) {
			cout << "Yes" << endl;
			cout << _a[ev[i].i] << endl;
			cout << _a[ev[i].j] << endl;
			cout << a[l] << endl;
			return 0;
		}
		h = -2 * S / length(_a[ev[i].i] - _a[ev[i].j]);
		l = 0, r = n - 1;
		while (r > l) {
			int mid = (l + r) >> 1;
			ld cur_h = ev[i].l.get(a[mid + 1]);
			if (cur_h > h + EPS)
				r = mid;
			else
				l = mid + 1;
		}
		cur_h = ev[i].l.get(a[l]);
		if (abs(h - cur_h) < EPS) {
			cout << "Yes" << endl;
			cout << _a[ev[i].i] << endl;
			cout << _a[ev[i].j] << endl;
			cout << a[l] << endl;
			return 0;
		}
		my_swap(ev[i].i, ev[i].j);
	}
	cout << "No" << endl;
}