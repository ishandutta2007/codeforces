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

const int N = 3e5 + 10;

struct participant {
	ll x, y; int idx;
	bool operator<(const participant &o) const {
		return (x - y) < (o.x - o.y);
	}
};

participant p[N];
ll pref_x[N], pref_y[N];
ll suff_x[N], suff_y[N];
ll ans[N];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i].x >> p[i].y;
		p[i].idx = i;
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		ll temp = min(p[u].x + p[v].y, p[v].x + p[u].y);
		ans[u] -= temp;
		ans[v] -= temp;
	}
	sort(p + 1, p + 1 + n);
	for (int i = 1; i <= n; ++i) {
		pref_x[i] = pref_x[i - 1] + p[i].x;
		pref_y[i] = pref_y[i - 1] + p[i].y;
	}
	for (int i = n; i >= 1; --i) {
		suff_x[i] = suff_x[i + 1] + p[i].x;
		suff_y[i] = suff_y[i + 1] + p[i].y;
	}
	for (int i = 1; i <= n; ++i) {
		ll lc = i - 1, rc = n - i;
		ll temp = p[i].y * lc + pref_x[i - 1];
		temp   += p[i].x * rc + suff_y[i + 1];
		ans[p[i].idx] += temp;
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
}