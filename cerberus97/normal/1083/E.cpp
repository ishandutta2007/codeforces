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

const int N = 1e6 + 10, P = 1e6 + 10;
const ll inf = 1e18 + 42;

vector<int> compress;

/* Usage:
	Tutorial - https://cp-algorithms.com/geometry/convex_hull_trick.html

	Add line y = mx + c using add_line({m, c}).
	Query for point x using query(x).
	For max instead of min, change lines marked with ###
	P = total number of lines added
*/
struct point {
	ll m, c; // y = mx + c; ###
};

point line[4 * P];

struct li_chao_tree {
	// int lc[P * int(log2(MX))], rc[P * int(log2(MX))];
	// int nxt_free = 2;
	void add_line(point add, int i = 1, ll l = 0, ll r = P) {
		ll m = (l + r) / 2;
		bool lef = (eval(add, compress[l]) > eval(line[i], compress[l])); // ###
		bool mid = (eval(add, compress[m]) > eval(line[i], compress[m])); // ###
		if (l == r - 1) { // Leaf Node
			if (lef) {
				line[i] = add;
			}
		} else if (lef != mid) { // Intersection point in (l, m]
			add_line(add, 2 * i, l, m);
			if (mid) {
				line[i] = add;
			}
		} else {
			add_line(add, 2 * i + 1, m, r);
			if (lef) {
				line[i] = add;
			}
		}
	}
	ll query(ll x, int i = 1, ll l = 0, ll r = P) {
		ll ans = eval(line[i], compress[x]), m = (l + r) / 2;
		if (l == r - 1) {
			return ans;
		} else if (x < m) {
			return max(ans, query(x, 2 * i, l, m)); // ###
		} else {
			return max(ans, query(x, 2 * i + 1, m, r)); // ###
		}
	}
	inline ll eval(point p, ll x) {
		return p.m * x + p.c;
	}
};

struct pts {
	ll x, y, a;
	bool operator<(const pts &o) {
		if (x != o.x) {
			return x < o.x;
		} else {
			return y < o.y;
		}
	}
};

pts p[N];
// map<int, int> compress;

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i].x >> p[i].y >> p[i].a;
		compress.pb(p[i].y);
	}
	compress.erase(unique(compress.begin(), compress.end()), compress.end());
	sort(compress.begin(), compress.end());
	int k = compress.size();
	compress.resize(P, compress[k - 1] + 1);
	sort(p + 1, p + 1 + n);
	li_chao_tree cht;
	// cht.add_line({0, 0});
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		int l = 0, r = k - 1, j = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (compress[mid] == p[i].y) {
				j = mid;
				break;
			} else if (compress[mid] < p[i].y) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		ll cur = cht.query(j) + p[i].x * p[i].y - p[i].a;
		// cout << i << ' ' << cur << endl;
		ans = max(ans, cur);
		cht.add_line({-p[i].x, cur});
	}
	cout << ans << endl;
}