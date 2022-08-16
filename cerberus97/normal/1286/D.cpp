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
typedef vector<vector<ll>> ways_t;

const int N = 1e5 + 10, mod = 998244353;

ll pwr(ll x, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) {
			res = (res * x) % mod;
		}
		x = (x * x) % mod;
		e /= 2;
	}
	return res;
}

struct time_unit {
	ll dist, speed;
	bool operator<(const time_unit& o) const {
		return dist * o.speed < o.dist * speed;
	}
	ll operator-(const time_unit& o) const {
		ll ans = dist * o.speed - speed * o.dist;
		ans = (ans % mod) + mod;
		ans %= mod;
		ans *= pwr(speed, mod - 2);
		ans %= mod;
		ans *= pwr(o.speed, mod - 2);
		ans %= mod;
		return ans;
	}
};

struct event_t {
	time_unit t;
	int i;
	bool b1, b2;
	bool operator<(const event_t& o) {
		return t < o.t;
	}
};

ll x[N], v[N], p[N], prob[N][2];
bool banned[N][2][2];
ways_t tree[4 * N];

void build(int i, int l, int r);
void update(int i, int l, int r, int p);
void merge(ways_t& w, ways_t& w1, ways_t& w2, bool ban[2][2]);
ll query();

int main() {
	fast_cin();
	int n; cin >> n;
	ll den = pwr(100, mod - 2);
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> v[i] >> p[i];
		p[i] = (p[i] * den) % mod;
		prob[i][0] = (mod + 1 - p[i]) % mod;
		prob[i][1] = p[i];
	}
	vector<event_t> events;
	for (int i = 1; i < n; ++i) {
		for (int b1 = 0; b1 < 2; ++b1) {
			for (int b2 = 0; b2 < 2; ++b2) {
				int vel = (b1 ? v[i] : -v[i]);
				vel += (b2 ? -v[i + 1] : v[i + 1]);
				if (vel > 0) {
					time_unit t = {x[i + 1] - x[i], vel};
					events.pb({t, i, b1, b2});
				}
			}
		}
	}
	sort(events.begin(), events.end());
	build(1, 1, n);
	time_unit cur_time = {0, 1};
	ll ans = 0;
	for (auto& e : events) {
		if (cur_time < e.t) {
			ans += (e.t - cur_time) * query();
			ans %= mod;
			cur_time = e.t;
		}
		banned[e.i][e.b1][e.b2] = true;
		update(1, 1, n, e.i);
	}
	time_unit zero = {0, 1};
	ans += (zero - cur_time) * query();
	ans = (ans % mod) + mod;
	cout << ans % mod << endl;
}

void build(int i, int l, int r) {
	tree[i].resize(2, vector<ll>(2, 0));
	if (l == r) {
		tree[i][0][0] = prob[l][0];
		tree[i][1][1] = prob[l][1];
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		build(lc, l, mid);
		build(rc, mid + 1, r);
		merge(tree[i], tree[lc], tree[rc], banned[mid]);
	}
}

void update(int i, int l, int r, int p) {
	if (p < l or p > r) {
		return;
	} else if (l == r) {
		return;
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		update(lc, l, mid, p);
		update(rc, mid + 1, r, p);
		merge(tree[i], tree[lc], tree[rc], banned[mid]);
	}
}

void merge(ways_t& w, ways_t& w1, ways_t& w2, bool ban[2][2]) {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			w[i][j] = 0;
			for (int k = 0; k < 2; ++k) {
				for (int l = 0; l < 2; ++l) {
					if (!ban[k][l]) {
						w[i][j] += w1[i][k] * w2[l][j];
					}
				}
			}
			w[i][j] %= mod;
		}
	}
}

ll query() {
	ll ans = 0;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			ans += tree[1][i][j];
		}
	}
	return ans % mod;
}