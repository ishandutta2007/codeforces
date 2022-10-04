/*

Code for problem E by cookiedoth
Generated 01 Aug 2020 at 12.03 PM



10%

30%

50%

70%

100%

z_z
>_<
\_()_/

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
	return (a.y > 0 || (a.y == 0 && a.x < 0)) ^ 1;
}

bool operator < (const pt &a, const pt &b) {
	int ha = half_plane(a), hb = half_plane(b);
	if (ha < hb) {
		return 1;
	}
	if (ha > hb) {
		return 0;
	}
	return (a / b > 0);
}

bool init_cmp(const pt &a, const pt &b) {
	return make_pair(-a.y, a.x) < make_pair(-b.y, b.x);
}

const int mx = 4040;
int n;
vector<pair<pt, int> > a;
vector<pair<pt, pair<int, int> > > ev;

bool kek_cmp(const pair<pt, int> &p1, const pair<pt, int> &p2) {
	if (init_cmp(p1.first, p2.first)) {
		return 1;
	}
	if (init_cmp(p2.first, p1.first)) {
		return 0;
	}
	return p1.second < p2.second;
}

void build_events() {
	sort(all(a), kek_cmp);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i].first.y > a[j].first.y) {
				ev.emplace_back(a[j].first - a[i].first, pair<int, int> (i, j));
			}
		}
	}
	sort(all(ev));
	// for (int i = 0; i < n; ++i) {
	// 	cerr << "idx " << i << ": " << a[i].first << endl;
	// }
}

int is_left(pt p1, pt p2, pt dir) {
	return dir / (p2 - p1) >= 0;
}

int p[mx], _p[mx], oksum;
ld ans = 1e18;

ld get(pt p, pt dir) {
	return (ld)p.x + (ld)dir.x * (ld)p.y / -(ld)dir.y;
}

void upd_ans(pt dir) {
	// cerr << "upd_ans " << dir << endl;
	if (dir.y == 0) {
		return;
	}
	ld res = get(a[n - 1].first, dir) - get(a[0].first, dir);
	// cerr << get(a[0].first, dir) << endl;
	// cerr << "res = " << res << endl;
	chkmin(ans, res);
	// cerr << "ans = " << ans << endl;
}

void upd_ans(pt from, pt to) {
	// cerr << "upd_ans" << endl;
	pt opt = a[n - 1].first - a[0].first;
	if (opt.y > 0) {
		opt = pt() - opt;
	}
	if (opt.y == 0) {
		opt = {0, -1};
	}
	if (from < opt && opt < to) {
		upd_ans(opt);
	} else {
		upd_ans(from);
		upd_ans(to);
	}
	// cerr << "ans = " << ans << endl;
	// assert(ans >= 8.5);
}

pt dir0(-1, 0), dir1(1, 0);

pt lst_dir = dir0;

int swI, swJ;
pt nxtDir, nxtDir2;

int ok[mx];

int is_equal(pt p1, pt p2) {
	return (p2 - p1) / (nxtDir + nxtDir2) == 0;
}

void update_ok(int pos) {
	if (a[pos].second % 2) {
		return;
	}
	// cerr << "update_ok " << pos << endl;
	ok[pos] = 0;
	int diff = 0;
	for (int i = 0; i < 3; ++i) {
		if (pos + i + 1 == n) {
			break;
		}
		if (!is_equal(a[pos + i].first, a[pos + i + 1].first)) {
			diff++;
		}
		if (diff == 0 && a[pos + i + 1].second % 2 == 0) {
			break;
		}
		if (diff > 1) {
			break;
		}
		if ((a[pos + i + 1].second ^ a[pos].second) == 1) {
			ok[pos] = 1;
			// cerr << "ok " << i << endl;
			break;
		}
	}
	oksum += ok[pos];
}

void init() {
	iota(p, p + n, 0);
	iota(_p, _p + n, 0);
	for (int i = 0; i < n; ++i) {
		update_ok(i);
	}
}

void add(int t, int mult) {
	if (mult == -1) {
		for (int i = t - 5; i <= t + 2; ++i) {
			if (i >= 0 && i < n) {
				oksum -= ok[i];
				ok[i] = 0;
			}
		}
	} else {
		for (int i = t - 5; i <= t + 2; ++i) {
			if (i >= 0 && i < n) {
				update_ok(i);
			}
		}
	}
	// if (t) {
	// 	oksum += mult * (a[t - 1].second ^ a[t].second);
	// }
	// oksum += mult * (a[t].second ^ a[t + 1].second);
	// if (t + 1 < n - 1) {
	// 	oksum += mult * (a[t + 1].second ^ a[t + 2].second);
	// }
}

void my_swap(int i, int j) {
	// cerr << "swapL " << i << " " << j << endl;
	// cerr << "old_oksum = " << oksum << endl;
	int pi = _p[i], pj = _p[j];
	assert(abs(pi - pj) == 1);
	int t = min(pi, pj);
	add(t, -1);
	swap(a[pi], a[pj]);
	swap(p[pi], p[pj]);
	_p[i] = pj;
	_p[j] = pi;
	// cerr << "second" << endl;
	// for (int i = 0; i < n; ++i) {
	// 	cerr << a[i].second << ' ';
	// }
	// cerr << endl;
	add(t, 1);
	// cerr << "nxtDir = " << nxtDir << endl;
	// cerr << "nxtDir2 = " << nxtDir2 << endl;
	// for (int i = 0; i < n; ++i) {
	// 	cerr << a[i].first << endl;
	// }
}

signed main() {
	cout << setprecision(10) << fixed;
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int xl, xr, y;
		cin >> xl >> xr >> y;
		a.emplace_back(pt(xl, y), 2 * i);
		a.emplace_back(pt(xr, y), 2 * i + 1);
	}
	n *= 2;
	build_events();
	init();

	for (int i = 0; i < ev.size(); ++i) {
		int swI = ev[i].second.first;
		int swJ = ev[i].second.second;
		nxtDir = ev[i].first;
		nxtDir2 = (i == (int)ev.size() - 1 ? dir1 : ev[i + 1].first);
		if (oksum == n / 2) {
			upd_ans(lst_dir, nxtDir);
		}
		my_swap(swI, swJ);
		lst_dir = nxtDir;
	}
	if (oksum == n / 2) {
		upd_ans(lst_dir, dir1);
	}
	cout << ans << '\n';
}