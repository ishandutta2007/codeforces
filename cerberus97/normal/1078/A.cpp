/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

#define sq(x) (x) * (x)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

struct point {
	ld x, y;
};

ld dist_mt(point p1, point p2);
ld dist_ec(point p1, point p2);

int main() {
	fast_cin();
	ll a, b, c;
	cin >> a >> b >> c;
	point p1, p2;
	cin >> p1.x >> p1.y >> p2.x >> p2.y;
	ld ans = dist_mt(p1, p2);
	vector<point> cand;
	if (b) {
		cand.pb({p1.x, (-c - a * p1.x) / b});
		cand.pb({p2.x, (-c - a * p2.x) / b});
	}
	if (a) {
		cand.pb({(-c - b * p1.y) / a, p1.y});
		cand.pb({(-c - b * p2.y) / a, p2.y});
	}
	for (auto &i : cand) {
		for (auto &j : cand) {
			ans = min(ans, dist_mt(p1, i) + dist_ec(i, j) + dist_mt(j, p2));
		}
	}
	cout << fixed << setprecision(10) << ans << endl;
}

ld dist_mt(point p1, point p2) {
	return fabs(p1.x - p2.x) + fabs(p1.y - p2.y);
}

ld dist_ec(point p1, point p2) {
	return sqrt(sq(p1.x - p2.x) + sq(p1.y - p2.y));
}