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

const int N = 2e5 + 10, S = 450;

struct line_t {
	ll slope, val; int id;
	bool operator>(const line_t &o) const {
		return slope > o.slope;
	}
};

vector<int> g[N];
ll a[N], b[N];
int ent[N], ext[N], at_time[N], nxt = 1;
int lo[S], hi[S];
ll upd[S];
vector<line_t> cht[S], lines[S];

void dfs(int u);
void reconstruct_block(int k);
ll query(int k);

int main() {
	fast_cin();
	int n, q;
	cin >> n >> q;
	for (int i = 2; i <= n; ++i) {
		int p; cin >> p;
		g[p].pb(i);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	dfs(1);
	int B = (n + S - 1) / S;
	for (int k = 1; k <= B; ++k) {
		lo[k] = (k - 1) * S + 1;
		hi[k] = min(k * S, n);
		for (int i = lo[k]; i <= hi[k]; ++i) {
			int u = at_time[i];
			lines[k].pb({b[u], a[u] * b[u], u});
			lines[k].pb({-b[u], -a[u] * b[u], u});
		}
		sort(lines[k].begin(), lines[k].end(), greater<line_t>());
		reconstruct_block(k);
	}
	for (int j = 1; j <= q; ++j) {
		int t; cin >> t;
		if (t == 1) {
			int v, x;
			cin >> v >> x;
			int l = ent[v], r = ext[v] - 1;
			for (int k = 1; k <= B; ++k) {
				if (hi[k] < l or lo[k] > r) {
					continue;
				} else if (l <= lo[k] and hi[k] <= r) {
					upd[k] += x;
				} else {
					for (int i = max(lo[k], l); i <= min(hi[k], r); ++i) {
						a[at_time[i]] += x;
					}
					reconstruct_block(k);
				}
			}
		} else {
			int v; cin >> v;
			int l = ent[v], r = ext[v] - 1;
			ll ans = 0;
			for (int k = 1; k <= B; ++k) {
				if (hi[k] < l or lo[k] > r) {
					continue;
				} else if (l <= lo[k] and hi[k] <= r) {
					ans = max(ans, query(k));
				} else {
					for (int i = max(lo[k], l); i <= min(hi[k], r); ++i) {
						int u = at_time[i];
						ans = max(ans, abs((a[u] + upd[k]) * b[u]));
					}
				}
			}
			cout << ans << '\n';
		}
	}
}

void dfs(int u) {
	at_time[nxt] = u;
	ent[u] = nxt++;
	for (auto &v : g[u]) {
		a[v] += a[u];
		b[v] += b[u];
		dfs(v);
	}
	ext[u] = nxt;
}

void reconstruct_block(int k) {
	cht[k].clear();
	for (int i = lo[k]; i <= hi[k]; ++i) {
		a[at_time[i]] += upd[k];
	}
	upd[k] = 0;
	int n = 0;
	for (auto &line : lines[k]) {
		line.val = a[line.id] * line.slope;
		while (n >= 2) {
			auto &l1 = cht[k][n - 1];
			auto &l2 = cht[k][n - 2];
			if (l1.slope == l2.slope) {
				break;
			}
			ll p = (l1.val - l2.val) / (l2.slope - l1.slope);
			if (line.val + p * line.slope >= l1.val + p * l1.slope) {
				cht[k].pop_back();
				--n;
			} else {
				break;
			}
		}
		if (cht[k].empty() or line.val > cht[k].back().val) {
			cht[k].pb(line);
			++n;
		}
	}
	// cout << "cht: \n";
	// for (auto &line : cht[k]) {
	// 	cout << line.slope << ' ' << line.val << endl;
	// }
}

ll query(int k) {
	int n = cht[k].size();
	while (n >= 2) {
		auto &l1 = cht[k][n - 1];
		auto &l2 = cht[k][n - 2];
		if (l2.val + upd[k] * l2.slope > l1.val + upd[k] * l1.slope) {
			cht[k].pop_back();
			--n;
		} else {
			break;
		}
	}
	auto &l = cht[k].back();
	return l.val + upd[k] * l.slope;
}