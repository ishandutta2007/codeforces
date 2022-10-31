#include <bits/stdc++.h>
using namespace std;

const int N = 1<<18;

#define next asdf

long long g[N], s[N];
pair<long long, int> save[N], gmax[N];
long long lazy[N], wmin[N];
int next[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n-1; i++) cin >> g[i*2+1], g[i*2+1] *= -1;
	for (int i = 0; i < n; i++) cin >> g[i*2];
	for (int i = 1; i < 2*n; i++) s[i] = s[i-1] + g[i-1];
	const long long inf = 1LL<<60;
	function<void(int, int, int)> build = [&](int u, int l, int r) {
		lazy[u] = wmin[u] = inf, gmax[u] = {-inf, -1};
		if (l == r) {
			save[u] = {s[2*l+1], l};
			return;
		}
		int mid = l + r >> 1;
		build(u + u, l, mid);
		build(u + u + 1, mid + 1, r);
		save[u] = max(save[u + u], save[u + u + 1]);
	};
	auto change = [&](int u, long long x) {
		wmin[u] = lazy[u] = x;
		gmax[u] = {save[u].first - wmin[u], save[u].second};
	};
	auto push_down = [&](int u) {
		if (lazy[u] == inf) return;
		change(u + u, lazy[u]);
		change(u + u + 1, lazy[u]);
		lazy[u] = inf;
	};
	auto push_up = [&](int u) {
		gmax[u] = max(gmax[u + u], gmax[u + u + 1]);
	};
	function<void(int, int, int, int, int, long long)> modify = [&](int u, int l, int r, int ll, int rr, long long x) {
		if (ll <= l && r <= rr) { change(u, x); return; }
		int mid = l + r >> 1;
		push_down(u);
		if (ll <= mid) modify(u + u, l, mid, ll, rr, x);
		if (mid < rr) modify(u + u + 1, mid + 1, r, ll, rr, x);
		push_up(u);
	};
	function<pair<long long, int>(int, int, int, int, int)> query = [&](int u, int l, int r, int ll, int rr) {
		if (ll <= l && r <= rr) return gmax[u];
		int mid = l + r >> 1;
		pair<long long, int> ret = {-inf, -1};
		push_down(u);
		if (ll <= mid) ret = max(ret, query(u + u, l, mid, ll, rr));
		if (mid < rr) ret = max(ret, query(u + u + 1, mid + 1, r, ll, rr));
		return ret;
	};
	function<int(int, int, int, int, int, long long)> find = [&](int u, int l, int r, int ll, int rr, long long x) {
		if (ll <= l && r <= rr) {
			if (save[u].first < x) return -1;
			if (l == r) return r;
			push_down(u);
			int mid = l + r >> 1;
			if (save[u + u + 1].first >= x) return find(u + u + 1, mid + 1, r, ll, rr, x);
			return find(u + u, l, mid, ll, rr, x);
		}
		int mid = l + r >> 1;
		push_down(u);
		int ret = -1;
		if (mid < rr && (ret = find(u + u + 1, mid + 1, r, ll, rr, x)) >= 0) return ret;
		if (ll <= mid && (ret = find(u + u, l, mid, ll, rr, x)) >= 0) return ret;
		return ret;
	};
	build(1, 0, n-1);
	vector<pair<long long, int> > v;
	int ans = 1;
	for (int i = n-1; i >= 0; i--) {
		int j = i+1;
		while (j < n && s[2*j] > s[2*i]) {
			j = next[j];
			v.pop_back();
		}
		next[i] = j;
		v.emplace_back(s[2*i], -i);
		if (j == n) j++;
        if (max(i-1, 0) <= j-2) modify(1, 0, n-1, max(i-1, 0), j-2, s[2*i]);
		int pos = lower_bound(v.begin(), v.end(), make_pair(s[2*i]-m, -n)) - v.begin() - 1;
		int to = pos >= 0 ? -v[pos].second-1 : n-1;
        if (i == to) continue;
		auto cur = query(1, 0, n-1, i, to-1);
		int max_pos = cur.second;
		long long max_val = cur.first + s[2*i];
		ans = max(ans, find(1, 0, n-1, max_pos, to, max_val - m) - i + 1);
	}
	cout << ans << endl;
	return 0;
}