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
typedef pair <ld, ld> pdd;

const int IT = 50;
const int N = 1e5 + 10, K = 2 * N, LOG = log2(K) + 5;
const ld TAU = 2 * atan2(0, -1), inf = 1e18 + 42, EPS = 1e-15;

ll px[N], py[N];
int jump[K][LOG];

bool solve(int n, int m, ld r);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	ld lo = 0, hi = inf;
	for (int i = 1; i <= n; ++i) {
		cin >> px[i] >> py[i];
		hi = min(hi, ld(sqrt(px[i] * px[i] + py[i] * py[i])));
	}
	for (int it = 0; it < IT; ++it) {
		ld mid = (lo + hi) / 2;
		if (solve(n, m, mid)) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << fixed << setprecision(10) << lo << '\n';
}

bool solve(int n, int m, ld r) {
	vector<pdd> intervals;
	for (int i = 1; i <= n; ++i) {
		ld d = sqrtl(px[i] * px[i] + py[i] * py[i]);
		ld phi = atan2(py[i], px[i]);
		if (r >= d) {
			return false;
		}
		ld theta = acos(r / d);
		// ld theta = atan2(sqrtl(px[i] * px[i] + py[i] * py[i] - r * r), r);
		ld lo = phi - theta, hi = phi + theta;
		if (lo < 0) {
			lo += TAU; hi += TAU;
		}
		intervals.pb({lo, hi});
		intervals.pb({lo + TAU, hi + TAU});
	}
	sort(intervals.begin(), intervals.end());
	int k = intervals.size();
	// for (int i = 0; i < k; ++i) {
	// 	intervals.pb({intervals[i].first + TAU, intervals[i].second + TAU});
	// }
	// k *= 2;
	// vector<pair<ld, int>> stk = {{inf, k}};
	// intervals.pb({inf, inf});
	// for (int i = k - 1; i >= 0; --i) {
	// 	auto it = lower_bound(stk.begin(), stk.end(), make_pair(intervals[i].second, k + 1), greater<pair<ld, int>>()) - 1;
	// 	if (it == stk.begin()) {
	// 		jump[i][0] = i;
	// 	} else {
	// 		jump[i][0] = it->second;
	// 	}
	// 	for (int j = 1; j < LOG; ++j) {
	// 		jump[i][j] = jump[jump[i][j - 1]][j - 1];
	// 	}
	// 	if (intervals[i].second < intervals[stk.back().second].second) {
	// 		stk.pb({intervals[i].first, i});
	// 	}
	// }
	// intervals.pb({inf, inf});
	ld min_r = inf;
	int nxt = k;
	for (int j = 0; j < LOG; ++j) {
		jump[k][j] = k;
	}
	for (int i = k - 1; i >= 0; --i) {
		if (intervals[i].second < min_r) {
			min_r = intervals[i].second;
		}
		while (intervals[nxt - 1].first > min_r) {
			--nxt;
		}
		jump[i][0] = nxt;
		for (int j = 1; j < LOG; ++j) {
			jump[i][j] = jump[jump[i][j - 1]][j - 1];
		}
	}
	for (int i = 0; i < n; ++i) {
		int p = i, left = m;
		for (int j = LOG - 1; j >= 0; --j) {
			if (left >= (1 << j)) {
				left -= (1 << j);
				p = jump[p][j];
			}
		}
		// if (intervals[p].second >= intervals[i].second + TAU) {
		// 	return true;
		// }
		if (p >= i + n) {
			return true;
		}
	}
	return false;
}