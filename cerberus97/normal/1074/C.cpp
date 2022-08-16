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

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 3e5 + 10, inf = 1e9;

struct point {
	ll x, y;
	bool operator==(const point &o) const {
		return x == o.x and y == o.y;
	}
};

ll ans[10];
point p[N];

ll get_per(vector<point> &pts);
ll dist(point p1, point p2);

int main() {
	fast_cin();
	int n; cin >> n;
	ll min_x = inf, max_x = -inf;
	ll min_y = inf, max_y = -inf;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i].x >> p[i].y;
		min_x = min(min_x, p[i].x);
		max_x = max(max_x, p[i].x);
		min_y = min(min_y, p[i].y);
		max_y = max(max_y, p[i].y);
	}
	vector<point> good;
	for (int i = 1; i <= n; ++i) {
		if (p[i].x == min_x or p[i].x == max_x or p[i].y == min_y or p[i].y == max_y) {
			good.pb(p[i]);
		}
	}
	int s = good.size(), subsets = (1 << s);
	for (int mask = 0; mask < subsets; ++mask) {
		vector<point> cur;
		for (int i = 0; i < s; ++i) {
			if (mask & (1 << i)) {
				cur.pb(good[i]);
			}
		}
		ll per = get_per(cur), k = cur.size();
		ans[k] = max(ans[k], per);
	}
	ll tr = 0;
	for (int i = 0; i < s; ++i) {
		for (int j = i + 1; j < s; ++j) {
			for (int k = 1; k <= n; ++k) {
				if (good[i] == p[k] or good[j] == p[k]) {
					continue;
				}
				vector<point> temp = {good[i], good[j], p[k]};
				tr = max(tr, get_per(temp));
			}
		}
	}
	cout << tr << ' ';
	for (int i = 4; i <= n; ++i) {
		if (i < s) {
			cout << ans[i] << ' ';
		} else {
			cout << ans[s] << ' ';
		}
	}
}

ll get_per(vector<point> &pts) {
	int n = pts.size();
	ll per = 0;
	for (int i = 0; i < n; ++i) {
		per += dist(pts[i], pts[(i + 1) % n]);
	}
	return per;
}

ll dist(point p1, point p2) {
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}