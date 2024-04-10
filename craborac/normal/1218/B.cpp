// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

double sqr(double num) {
	return num * num;
}

struct point {
	int x, y;
	point(int _x, int _y) : x(_x), y(_y) {}

	point operator+(point const& other) const {
		return point(x + other.x, y + other.y);
	}

	point operator-(point const& other) const {
		return point(x - other.x, y - other.y);
	}

	ll len2() const {
		return (ll) x * x + (ll) y * y;
	}
};

ostream& operator<<(ostream& o, point const& p) {
	o << "(" << p.x << ", " << p.y << ")";
	return o;
}

ll cross(point const& p1, point const& p2) {
	return p1.x * p2.y - p1.y * p2.x;
}

bool operator<(point const& p1, point const& p2) {
	bool fl1 = p1.y > 0 || (p1.y == 0 && p1.x > 0);
	bool fl2 = p2.y > 0 || (p2.y == 0 && p2.x > 0);
	if (fl1 != fl2) {
		return fl1 < fl2;
	}
	ll tmp = cross(p1, p2);
	if (tmp) {
		return tmp > 0;
	}
	return p1.len2() < p2.len2();
}


struct line {
	int a, b, c;
	line() : a(0), b(0), c(0) {}
	line(point const& p1, point const& p2) {
		a = p2.y - p1.y;
		b = p1.x - p2.x;
		c = -(p1.x * a + p1.y * b);
		assert(abs(a * p2.x + b * p2.y + c) < 1e-5);
	}
};

line cur_dir;
vector<line> segs;

double dist_intersection(line const& l1, line const& l2) {
	ll d = (ll) l1.a * l2.b - (ll) l1.b * l2.a;
	ll d1 = -(ll) l1.c * l2.b + (ll) l1.b * l2.c;
	ll d2 = -(ll) l1.a * l2.c + (ll) l1.c * l2.a;
	return sqr(d1 / (double) d) + sqr(d2 / (double) d);
}

struct segs_cmp {
	bool operator()(int a, int b) {
		if (a == b) {
			return false;
		}
		return dist_intersection(segs[a], cur_dir) < dist_intersection(segs[b], cur_dir);
	}
};

struct point_d { 
	double x, y;
	point_d(double _x, double _y) : x(_x), y(_y) {}
	point_d(point p) : x(p.x), y(p.y) {}
};

double cross(point_d const& p1, point_d const& p2) {
	return p1.x * p2.y - p1.y * p2.x;
}

point_d intersection(line const& l1, line const& l2) {
	ll d = (ll) l1.a * l2.b - (ll) l1.b * l2.a;
	ll d1 = -(ll) l1.c * l2.b + (ll) l1.b * l2.c;
	ll d2 = -(ll) l1.a * l2.c + (ll) l1.c * l2.a;
	return point_d(d1 / (double) d, d2 / (double) d);
}

void solve() {
	int n;
	cin >> n;
	vector<vector<point>> polys;
	vector<pair<vector<point>, vector<point>>> parts;
	vector<tuple<point, int, int>> actions;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		polys.push_back({});
		for (int j = 0; j < k; ++j) {
			int x, y;
			cin >> x >> y;
			polys[i].push_back({x, y});
		}
		reverse(polys[i].begin(), polys[i].end());
		int ind = 0;
		for (int j = 0; j < k; ++j) {
			if (cross(polys[i][ind], polys[i][j]) > 0) {
				ind = j;
			}
		}
		rotate(polys[i].begin(), polys[i].begin() + ind, polys[i].end());
		ind = 0;
		for (int j = 0; j < k; ++j) {
			if (cross(polys[i][ind], polys[i][j]) < 0) {
				ind = j;
			}
		}
		parts.push_back({vector<point>(polys[i].begin(), polys[i].begin() + ind + 1), vector<point>(polys[i].begin() + ind, polys[i].end())});
		parts[i].ss.push_back(polys[i][0]);
		reverse(parts[i].ff.begin(), parts[i].ff.end());
		actions.push_back({polys[i][0], i, 1});
		actions.push_back({polys[i][ind], i, 0});
		segs.push_back(line(polys[i][0], polys[i][ind]));
	}

	sort(actions.begin(), actions.end());

	vector<int> last_t(n);

	for (auto [p, ind, t] : actions) {
		last_t[ind] = t;
	}

	cur_dir = line(point(0, 0), get<0>(actions[0]));

	set<int, segs_cmp> have;
	for (int i = 0; i < n; ++i) {
		if (last_t[i] == 0) {
			have.insert(i);
		}
	}

	vector<vector<pair<point, point>>> poly_angles(n);

	for (int i = 0; i < szof(actions); ++i) {
		auto [p, ind, t] = actions[i];
		// cerr << p << " " << ind << " " << t << endl;
		cur_dir = line(point(0, 0), p);
		int prev = (i - 1 + szof(actions)) % szof(actions);
		if (szof(have)) {
			if (cross(get<0>(actions[prev]), p)) {
				poly_angles[*have.begin()].push_back({get<0>(actions[prev]), p});
			}
		}
		if (t == 0) {
			have.insert(ind);
		} else {
			have.erase(ind);
		}
	}

	// for (int i = 0; i < n; ++i) {
	// 	cerr << "polygon " << i + 1 << endl;
	// 	for (auto p : poly_angles[i]) {
	// 		cerr << p.ff << " " << p.ss << endl;
	// 	}
	// }

	double ans = 0;

	for (int i = 0; i < n; ++i) {
		int ind = 0;
		for (int j = 0; j < szof(poly_angles[i]); ++j) {
			if (cross(poly_angles[i][ind].ff, poly_angles[i][j].ff) < 0) {
				ind = j;
			}
		}
		rotate(poly_angles[i].begin(), poly_angles[i].begin() + ind, poly_angles[i].end());

		auto calc = [&](vector<point> const& pl) {
			int cnt = 0;
			double ret = 0;
			for (int j = 0; j < szof(poly_angles[i]); ++j) {
				auto [from, to] = poly_angles[i][j];
				while (cross(pl[cnt], from) > 0) {
					++cnt;
				}
				if (cross(pl[cnt], to) < 0) {
					line cl(pl[cnt], pl[cnt - 1]);
					ret += cross(intersection(line(point(0, 0), from), cl), intersection(line(point(0, 0), to), cl));
					continue;
				}
				if (cross(pl[cnt], from) < 0) {
					ret += cross(intersection(line(point(0, 0), from), line(pl[cnt], pl[cnt - 1])), pl[cnt]);
				}
				while (cnt < szof(pl) - 1 && cross(pl[cnt + 1], to) >= 0) {
					ret += cross(pl[cnt], pl[cnt + 1]);
					++cnt;
				}
				if (cnt < szof(pl) - 1) {
					ret += cross(pl[cnt], intersection(line(point(0, 0), to), line(pl[cnt], pl[cnt + 1])));
				}
			}
			return ret;
		};

		ans += calc(parts[i].ss);
		ans -= calc(parts[i].ff);
	}

	cout << ans / 2 << "\n";
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}