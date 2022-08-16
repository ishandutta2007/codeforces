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
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

typedef tree<
pii,
null_type,
less<pii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int N = 1e5 + 10, inf = 2e9 + 42;

struct event_t {
	int t, idx, type;
	bool operator<(const event_t &o) const {
		return tie(t, type) < tie(o.t, o.type);
	}
};

ordered_set seg[4 * N];
int p[N], s[N], b[N], inc[N], pref[N], ans[N];
vector<event_t> events;
map<int, int> mp;
int T = 0;

void update(int i, int l, int r, int x, int y, int t);
int query(int i, int l, int r, int ql, int qr, int y);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> inc[i];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> pref[i];
	}
	for (int i = 1; i <= n; ++i) {
		events.push_back({p[i], i, 1});
		events.push_back({s[i] + 1, i, -1});
		mp[b[i] - p[i]];
	}
	for (int i = 1; i <= m; ++i) {
		events.push_back({inc[i], i, 2});
	}
	int id = 0;
	for (auto &i : mp) {
		i.second = ++id;
	}
	mp[inf] = id + 1;
	sort(events.begin(), events.end());
	for (auto &e : events) {
		int i = e.idx;
		if (e.type == 2) {
			auto it = mp.lower_bound(pref[i] - inc[i]);
			ans[i] = query(1, 1, id, it->second, id, pref[i] + inc[i]);
		} else {
			update(1, 1, id, mp[b[i] - p[i]], b[i] + p[i], e.type);
		}
	}
	for (int i = 1; i <= m; ++i) {
		cout << ans[i] << ' ';
	}
}

void update(int i, int l, int r, int x, int y, int t) {
	if (x < l or x > r) {
		return;
	}
	if (t == 1) {
		seg[i].insert({y, T++});
	} else {
		seg[i].erase(seg[i].lower_bound({y, 0}));
	}
	if (l < r) {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		update(lc, l, mid, x, y, t);
		update(rc, mid + 1, r, x, y, t);
	}
}

int query(int i, int l, int r, int ql, int qr, int y) {
	if (l > qr or ql > r) {
		return 0;
	} else if (ql <= l and r <= qr) {
		return seg[i].order_of_key({y, T});
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		return query(lc, l, mid, ql, qr, y) + query(rc, mid + 1, r, ql, qr, y);
	}
}