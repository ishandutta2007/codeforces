#include <bits/stdc++.h>
using namespace std;

const int N = 1<<20;

long long ans[N + N], add[N + N], sum[N + N];
int a[N], b[N], chk[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	int q; cin >> q;
	int n = 1000001;
	const long long inf = 1e15;
	auto push_up = [&](int u) {
		ans[u] = max(ans[u + u], ans[u + u + 1]);
	};
	auto change = [&](int u, long long d) {
		add[u] += d;
		ans[u] += d;
	};
	auto push_down = [&](int u) {
		if (!add[u]) return;
		change(u + u, add[u]);
		change(u + u + 1, add[u]);
		add[u] = 0;
	};
	function<void(int, int, int, int)> update = [&](int u, int l, int r, int p) {
		if (l == r) {
			ans[u] = p;
			return;
		}
		int mid = l + r >> 1;
		push_down(u);
		if (p <= mid) update(u + u, l, mid, p);
		else update(u + u + 1, mid + 1, r, p);
		push_up(u);
	};
	function<void(int, int, int, int, int, long long)> modify = [&](int u, int l, int r, int ll, int rr, long long d) {
		if (ll <= l && r <= rr) {
			change(u, d);
			return;
		}
		int mid = l + r >> 1;
		push_down(u);
		if (ll <= mid) modify(u + u, l, mid, ll, rr, d);
		if (mid < rr) modify(u + u + 1, mid + 1, r, ll, rr, d);
		push_up(u);
	};
	function<long long(int, int, int, int, int)> query = [&](int u, int l, int r, int ll, int rr) {
		if (ll <= l && r <= rr) return ans[u];
		int mid = l + r >> 1;
		long long ret = -inf;
		push_down(u);
		if (ll <= mid) ret = max(ret, query(u + u, l, mid, ll, rr));
		if (mid < rr) ret = max(ret, query(u + u + 1, mid + 1, r, ll, rr));
		return ret;
	};
	auto add = [&](int t, int d) {
		for (; t <= n; t += t & -t) sum[t] += d;
	};
	auto get = [&](int t) {
		long long ret = 0;
		for (; t; t -= t & -t) ret += sum[t];
		return ret;
	};
	for (int i = 1; i <= q; i++) {
		string op; cin >> op;
		if (op[0] == '+') {
			int t, d; cin >> t >> d;
			if (!chk[t]) modify(1, 0, n, t, t, t);
			chk[t]++;
			modify(1, 0, n, t + 1, n, -d);
			a[i] = t, b[i] = d;
			add(t, d);
		} else if (op[0] == '-') {
			int id; cin >> id;
			int t = a[id], d = b[id];
			modify(1, 0, n, t + 1, n, d);
			chk[t]--;
			if (!chk[t]) modify(1, 0, n, t, t, -t);
			add(t, -d);
		} else {
			long long t; cin >> t;
			printf("%lld\n", max(t, query(1, 0, n, 0, t) + get(t)) - t);
		}
	}
	return 0;
}