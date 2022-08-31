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

const int N = 6e5 + 10;

struct p_t {
	int a, b, idx;
	bool operator<(const p_t &o) const {
		return b < o.b;
	}
};

pii tree[4 * N];
vector<pii> b[N];

pair<int, vector<int>> solve(vector<p_t> &p, int n);
void update(int i, int l, int r, int p, int x);
pii query(int i, int l, int r, int ql, int qr);

int main() {
	fast_cin();
	int n; cin >> n;
	vector<p_t> p1, p2;
	for (int i = 1; i <= n; ++i) {
		int a, b;
		cin >> a >> b;
		if (a < b) {
			p1.pb({a, b, i});
		} else if (a > b) {
			p2.pb({b, a, i});
		}
	}
	auto c1 = solve(p1, 2 * n), c2 = solve(p2, 2 * n);
	auto ans = c1;
	if (c2 > c1) {
		ans = c2;
		reverse(ans.second.begin(), ans.second.end());
	}
	cout << ans.first << '\n';
	for (auto &i : ans.second) {
		cout << i << ' ';
	}
}

pair<int, vector<int>> solve(vector<p_t> &p, int n) {
	int ans = 0;
	memset(tree, 0, sizeof(tree));
	for (int i = 1; i <= n; ++i) {
		b[i].clear();
	}
	sort(p.begin(), p.end());
	for (auto &i : p) {
		b[i.a].pb({i.b, i.idx});
		update(1, 1, n, i.a, i.b);
	}
	int cur_b = n + 1;
	vector<int> ret;
	while (true) {
		int cur_a = query(1, 1, n, 1, cur_b - 1).second;
		// cout << cur_a << endl;
		if (b[cur_a].empty()) {
			break;
		}
		cur_b = b[cur_a].back().first;
		ret.pb(b[cur_a].back().second);
		b[cur_a].pop_back();
		if (b[cur_a].empty()) {
			update(1, 1, n, cur_a, 0);
		} else {
			update(1, 1, n, cur_a, b[cur_a].back().first);
		}
		++ans;
	}
	return {ans, ret};
}

void update(int i, int l, int r, int p, int x) {
	if (p < l or p > r) {
		return;
	} else if (l == r) {
		tree[i] = {x, l};
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		update(lc, l, mid, p, x);
		update(rc, mid + 1, r, p, x);
		tree[i] = max(tree[lc], tree[rc]);
	}
}

pii query(int i, int l, int r, int ql, int qr) {
	if (l > qr or ql > r) {
		return {0, 1};
	} else if (ql <= l and r <= qr) {
		return tree[i];
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		return max(query(lc, l, mid, ql, qr), query(rc, mid + 1, r, ql, qr));
	}
}