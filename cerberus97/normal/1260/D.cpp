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

const int N = 2e5 + 10;

struct trap {
	int l, r, d;
	bool operator<(const trap &o) const {
		return tie(l, r) < tie(o.l, o.r);
	};
};

trap tr[N];
int a[N];

int main() {
	fast_cin();
	int m, n, k, t;
	cin >> m >> n >> k >> t;
	for (int i = 1; i <= m; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + m, greater<int>());
	for (int i = 1; i <= k; ++i) {
		cin >> tr[i].l >> tr[i].r >> tr[i].d;
	}
	sort(tr + 1, tr + 1 + k);
	int lo = 1, hi = m;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int min_a = a[mid];
		vector<pii> events;
		for (int i = 1; i <= k; ++i) {
			if (tr[i].d > min_a) {
				events.pb({tr[i].l, tr[i].r});
			}
		}
		ll cost = n + 1;
		int cur_r = -1;
		for (auto &p : events) {
			if (p.first > cur_r) {
				cur_r = p.second;
				cost += 2 * (p.second - p.first + 1);
			} else {
				int inc = max(cur_r, p.second) - cur_r;
				cur_r += inc;
				cost += 2 * inc;
			}
		}
		if (cost > t) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << lo - 1 << '\n';
}