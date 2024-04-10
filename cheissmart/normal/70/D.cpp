#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<double, double> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;
const double oo = 1e18, eps = 1e-12;

int sign(double x) {
	return x > eps ? 1 : x < -eps ? -1 : 0;
}

#define x F
#define y S

#define opab(op) operator op (const pi a, const pi b)
pi opab(+) { // vector addition
	return pi(a.x + b.x, a.y + b.y);
}
pi opab(-) { // vector subtraction
	return pi(a.x - b.x, a.y - b.y);
}
double opab(*) { // dot prodoct
	return a.x * b.x + a.y * b.y;
}
double opab(^) { // cross prodoct
	return a.x * b.y - a.y * b.x;
}
pi operator / (pi a, const double b) {
	a.x /= b, a.y /= b;
	return a;
}
pi operator * (pi a, const double b) {
	a.x *= b, a.y *= b;
	return a;
}
pi operator - (pi a) {
	return pi(a.x, -a.y);
}
double abs(pi a) { // length of vector a
	return sqrt(a * a);
}
int ori(pi a, pi b, pi c) {
	return sign((b - a) ^ (c - a));
}

struct Half_down_hull {
	set<pi> s;
	bool inside(pi p) {
		auto it = s.upper_bound(p);
		if(it == s.begin()) return false;
		if(it == s.end()) return prev(it) -> x == p.x && prev(it) -> y <= p.y;
		return ori(p, *prev(it), *it) >= 0;
	}
	void insert(pi p) {
		if(inside(p)) return;
		s.insert(p);
		auto it = s.find(p);
		while(next(it) != s.end() && next(next(it)) != s.end() && ori(*it, *next(it), *next(next(it))) < 0)
			s.erase(next(it));
		while(it != s.begin() && prev(it) != s.begin() && ori(*prev(prev(it)), *prev(it), *it) < 0)
			s.erase(prev(it));
	}
};

struct Hull {
	Half_down_hull up, down;
	bool inside(pi p) {
		return down.inside(p) && up.inside(-p);
	}
	void insert(pi p) {
		down.insert(p);
		up.insert(-p);	
	}
} h;

signed main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		int op, x, y;
		cin >> op >> x >> y;
		if(op == 1) { // add point
			h.insert(pi(x, y));
		} else { // check whether (x, y) is inside the area of the convex hull
			if(h.inside(pi(x, y)))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	
}