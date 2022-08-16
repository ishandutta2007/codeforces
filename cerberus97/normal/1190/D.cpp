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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

template<typename has_less>
using ordered_set =
tree<has_less,
	null_type,
	less<has_less>,
	rb_tree_tag,
	tree_order_statistics_node_update>;

const int N = 2e5 + 10, inf = 1e9 + 42;

struct point {
	ll x, y;
	bool operator<(const point &o) const {
		return tie(o.y, o.x) < tie(y, x);
	}
};

ordered_set<int> all_x;
point p[N];

ll in_range(int lo, int hi);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i].x >> p[i].y;
	}
	sort(p + 1, p + 1 + n);
	p[n + 1] = {0, 0};
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		all_x.insert(p[i].x);
		int l = ((p[i + 1].y == p[i].y) ? (p[i + 1].x + 1) : 1);
		int r = inf;
		ans += in_range(l, p[i].x + 1) * in_range(p[i].x, r);
	}
	cout << ans << endl;
}

// Counts number of points in all_x in [lo, hi)
ll in_range(int lo, int hi) {
	if (lo > hi) {
		return 0;
	} else {
		return all_x.order_of_key(hi) - all_x.order_of_key(lo);
	}
}