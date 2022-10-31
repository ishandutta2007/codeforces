#include <bits/stdc++.h>
using namespace std;

const int N = 1<<20;
const int P = 1e9 + 7;

int q[330], prm[330], prn;
long long s[330];
long long state[N];
int val[N];

pair<int, long long> added[N];
int a[N];
int r[N], p[N], sz[N];

int modExp(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1, a = 1LL * a * a % P) if (n & 1) ret = 1LL * ret * a % P;
    return ret;
}

int main() {
    for (int i = 2; i <= 300; i++) {
        if (!q[i]) {
            q[i] = i;
            prm[prn++] = i;
        }
        for (int j = 0; j < prn && i * prm[j] <= 300; j++) {
            q[prm[j] * i] = prm[j];
            if (prm[j] == q[i]) break;
        }
    }
    for (int i = 1; i <= 300; i++) {
        for (int j = 0; j < prn; j++) {
            if (i % prm[j] == 0) s[i] |= 1LL<<j;
        }
    }
    for (int i = 1; i <= 300; i++) r[i] = i == 1 ? i : r[P % i] * 1LL * (P - P / i) % P;
    for (int j = 0; j < prn; j++) p[j] = (1 + P - r[prm[j]]) % P;
    ios::sync_with_stdio(0);
    int n, Q; cin >> n >> Q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    auto change = [&](int u, pair<int, long long> add) {
        val[u] = val[u] * 1LL * modExp(add.first, sz[u]) % P;
        state[u] |= add.second;
        added[u].first = added[u].first * 1LL * add.first % P;
        added[u].second |= add.second;
    };
    auto push_down = [&](int u) {
		if (added[u].second == 0) return;
		change(u + u, added[u]);
		change(u + u + 1, added[u]);
		added[u] = make_pair(1, 0LL);
	};
	auto push_up = [&](int u) {
        val[u] = val[u + u] * 1LL * val[u + u + 1] % P;
        state[u] = state[u + u] | state[u + u + 1];
	};
	function<void(int, int, int)> build = [&](int u, int l, int r) {
	    sz[u] = r - l + 1;
	    added[u] = {1, 0LL};
		if (l == r) {
		    state[u] = s[a[l]];
            val[u] = a[l];
			return;
		}
		int mid = l + r >> 1;
		build(u + u, l, mid);
		build(u + u + 1, mid + 1, r);
		push_up(u);
	};
	function<void(int, int, int, int, int, int, long long)> modify = [&](int u, int l, int r, int ll, int rr, int x, long long y) {
		if (ll <= l && r <= rr) { change(u, make_pair(x, y)); return; }
		int mid = l + r >> 1;
		push_down(u);
		if (ll <= mid) modify(u + u, l, mid, ll, rr, x, y);
		if (mid < rr) modify(u + u + 1, mid + 1, r, ll, rr, x, y);
		push_up(u);
	};
	auto merge = [&](pair<int, long long> a, pair<int, long long> b) {
	    pair<int, long long> ret = {1, 0LL};
        ret.first = 1LL * ret.first * b.first % P;
        ret.second = a.second | b.second;
        return ret;
	};
	function<pair<int, long long>(int, int, int, int, int)> query = [&](int u, int l, int r, int ll, int rr) {
		if (ll <= l && r <= rr) return make_pair(val[u], state[u]);
		int mid = l + r >> 1;
		pair<int, long long> ret = make_pair(1, 0LL);
		push_down(u);
		if (ll <= mid) {
            auto cur = query(u + u, l, mid, ll, rr);
            ret.first = ret.first * 1LL * cur.first % P;
            ret.second |= cur.second;
		}
		if (mid < rr) {
            auto cur = query(u + u + 1, mid + 1, r, ll, rr);
            ret.first = ret.first * 1LL * cur.first % P;
            ret.second |= cur.second;
		}
		push_up(u);
		return ret;
	};
    build(1, 1, n);
    while (Q--) {
        string op; cin >> op;
        if (op[0] == 'T') {
            int l, r; cin >> l >> r;
            auto ans = query(1, 1, n, l, r);
            long long state = ans.second;
            for (int j = 0; j < prn; j++) {
                if (state >> j & 1) {
                    ans.first = 1LL * ans.first * p[j] % P;
                }
            }
            printf("%d\n", ans.first);
        } else {
            int l, r, x; cin >> l >> r >> x;
            modify(1, 1, n, l, r, x, s[x]);
        }
    }
    return 0;
}