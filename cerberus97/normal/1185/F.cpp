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

const int N = 1e5 + 10, P = 600, inf = 2e9 + 42;

struct ans_t {
	int num, cost, i1, i2;
	bool operator<(const ans_t &o) const {
		return tie(num, o.cost) < tie(o.num, cost);
	}
};

int a[N];
int cost[P], id[P];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int f; cin >> f;
		for (int j = 0; j < f; ++j) {
			int x; cin >> x;
			a[i] |= (1 << (x - 1));
		}
	}
	int subsets = (1 << 9);
	for (int mask = 0; mask < subsets; ++mask) {
		cost[mask] = inf;
	}
	vector<pii> all_pizzas;
	for (int i = 1; i <= m; ++i) {
		int c, r; cin >> c >> r;
		all_pizzas.pb({c, i});
		int mask = 0;
		for (int j = 0; j < r; ++j) {
			int x; cin >> x;
			mask |= (1 << (x - 1));
		}
		if (c < cost[mask]) {
			cost[mask] = c;
			id[mask] = i;
		}
	}
	sort(all_pizzas.begin(), all_pizzas.end());
	ans_t ans = {-1, 0, 0, 0};
	for (int mask = 0; mask < subsets; ++mask) {
		int num = 0;
		for (int i = 1; i <= n; ++i) {
			if ((a[i] & mask) == a[i]) {
				++num;
			}
		}
		if (id[mask]) {
			ans_t cand = {num, cost[mask], id[mask], 0};
			for (auto &p : all_pizzas) {
				if (p.second != id[mask]) {
					cand.cost += p.first;
					cand.i2 = p.second;
					break;
				}
			}
			ans = max(ans, cand);
		}
		for (int m1 = 0; m1 < mask; ++m1) {
			for (int m2 = 0; m2 < m1; ++m2) {
				if (id[m1] and id[m2] and (m1 | m2) == mask) {
					ans_t cand = {num, cost[m1] + cost[m2], id[m1], id[m2]};
					ans = max(ans, cand);
				}
			}
		}
	}
	cout << ans.i1 << ' ' << ans.i2 << endl;
}