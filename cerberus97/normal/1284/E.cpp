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

const int N = 2500 + 10;
const ld PI = acos(-1);

struct pt {
	ll x, y;
	ld angle;
};

pt p[N];

inline ll cross(ll x1, ll y1, ll x2, ll y2);
ll c3(ll n);
ll c4(ll n);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i].x >> p[i].y;
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		int cx = p[i].x, cy = p[i].y;
		vector<pt> pts;
		for (int j = 1; j <= n; ++j) {
			if (i != j) {
				// pts.pb(atan2(p[j].y - cy, p[j].x - cx));
				pts.pb({p[j].x - cx, p[j].y - cy});
				pts.back().angle = atan2(pts.back().y, pts.back().x);
			}
		}
		sort(pts.begin(), pts.end(), [&] (const pt& p1, const pt& p2) {
			return p1.angle < p2.angle;
		});
		int m = pts.size(), k = 0;
		ll temp = 0;
		for (int j = 0; j < m; ++j) {
			pts.pb(pts[j]);
		}
		for (int j = 0; j < m; ++j) {
			while (k + 1 < j + m) {
				if (cross(pts[j].x, pts[j].y, pts[k + 1].x - pts[j].x, pts[k + 1].y - pts[j].y) >= 0) {
					++k;
				} else {
					break;
				}
			}
			ll cnt = k - j;
			temp += c3(cnt);
		}
		ans += c4(m) - temp;
	}
	cout << ans << '\n';
}

ll c3(ll n) {
	return (n * (n - 1) * (n - 2)) / 6;
}

ll c4(ll n) {
	return (n * (n - 1) * (n - 2) * (n - 3)) / 24;
}	

inline ll cross(ll x1, ll y1, ll x2, ll y2) {
	// pts[j].x * pts[k + 1].y - pts[j].y * pts[k + 1].x
	return x1 * y2 - y1 * x2;
}