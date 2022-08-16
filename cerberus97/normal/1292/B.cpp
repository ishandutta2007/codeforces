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

const int N = 1e5 + 10;

ll solve(vector<pll>& pts, ll xs, ll ys, ll t);

int main() {
	fast_cin();
	ll x0, y0, ax, ay, bx, by, xs, ys, t;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
	ll x = x0, y = y0;
	vector<pll> pts;
	while (x - xs + y - ys <= t) {
		if (abs(x - xs) + abs(y - ys) <= t) {
			pts.pb({x, y});
		}
		x = ax * x + bx;
		y = ay * y + by;
	}
	ll ans = solve(pts, xs, ys, t);
	reverse(pts.begin(), pts.end());
	ans = max(ans, solve(pts, xs, ys, t));
	cout << ans << endl;
}

ll solve(vector<pll>& pts, ll xs, ll ys, ll t) {
	ll ans = 0;
	int sz = pts.size();
	for (int i = 0; i < sz; ++i) {
		ll left = t - (abs(pts[i].first - xs) + abs(pts[i].second - ys));
		if (left < 0) {
			continue;
		}
		ll cand = 1;
		for (int j = i + 1; j < sz; ++j) {
			left -= (abs(pts[j].first - pts[j - 1].first) + abs(pts[j].second - pts[j - 1].second));
			if (left < 0) {
				break;
			} else {
				++cand;
			}
		}
		ans = max(ans, cand);
	}
	return ans;
}