#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int mxN = 211111;
const int mxM = 4*mxN;

long long sum[mxM], add[mxM], mul[mxM], lft[mxM], rht[mxM];

void build(int u, int l, int r) {
	sum[u] = 0, add[u] = 0;
	mul[u] = 1;
	lft[u] = l, rht[u] = r;
	if (l == r) return;
	int m = l + r >> 1;
	build(u + u, l, m);
	build(u + u + 1, m + 1, r);
}

void up(int u) {
	sum[u] = (sum[u+u] + sum[u+u+1]) % MOD;
}

void down(int u) {
	int l = lft[u], r = rht[u];
	int m = l+r >> 1;
	if (mul[u] != 1) {
		sum[u+u] *= mul[u]; sum[u+u] %= MOD;
		mul[u+u] *= mul[u]; mul[u+u] %= MOD;
		sum[u+u+1] *= mul[u]; sum[u+u+1] %= MOD;
		mul[u+u+1] *= mul[u]; mul[u+u+1] %= MOD;
		add[u+u] *= mul[u]; add[u+u] %= MOD;
		add[u+u+1] *= mul[u]; add[u+u+1] %= MOD;
		mul[u] = 1;
	}
	if (add[u]) {
		sum[u+u] += add[u]*(m-l+1); sum[u+u] %= MOD;
		add[u+u] += add[u]; add[u+u] %= MOD;
		sum[1+u+u] += add[u]*(r-m); sum[u+u+1] %= MOD;
		add[1+u+u] += add[u]; add[u+u+1] %= MOD;
		add[u] = 0;
	}
}

long long query(int u, int ll, int rr) {
	if (rr < ll) return 0;
	int l = lft[u], r = rht[u];
	if (ll <= l && r <= rr) {
		return sum[u];
	}
	int m = l + r >> 1;
	down(u);
	long long ret = 0;
	if (ll <= m) ret += query(u + u, ll, rr);
	if (m < rr) ret += query(u + u + 1, ll, rr);
	up(u);
	return (ret%MOD+MOD)%MOD;
}

void update_add(int u, int ll, int rr, long long x) {
	if (rr < ll) return;
	int l = lft[u], r = rht[u];
	if (ll <= l && r <= rr) {
		sum[u] += x*(r-l+1); sum[u] %= MOD;
		add[u] += x; add[u] %= MOD;
		return;
	}
	int m = l + r >> 1;
	down(u);
	if (ll <= m) update_add(u + u, ll, rr, x);
	if (m < rr) update_add(u + u + 1, ll, rr, x);
	up(u);
}

void update_mul(int u, int ll, int rr, long long x) {
	if (rr < ll) return;
	int l = lft[u], r = rht[u];
	if (ll <= l && r <= rr) {
		sum[u] *= x; sum[u] %= MOD;
		mul[u] *= x; mul[u] %= MOD;
		add[u] *= x; add[u] %= MOD;
		return;
	}
	int m = l + r >> 1;
	down(u);
	if (ll <= m) update_mul(u + u, ll, rr, x);
	if (m < rr) update_mul(u + u + 1, ll, rr, x);
	up(u);
}

using pii = pair<int, int>;
set<pii> S[mxN];

int main() {
	int n, q; scanf("%d%d", &n, &q);
	build(1, 0, n + 1);
	while (q--) {
		int t, l, r; scanf("%d%d%d", &t, &l, &r);
		if (t == 1) {
			int x; scanf("%d", &x);
			auto lw = S[x].lower_bound(pii(l, l));
			auto hi = S[x].lower_bound(pii(r + 1, r + 1));
			if (lw != S[x].begin()) lw--;
			if (lw != S[x].end() && lw->second < l) lw++;
			vector<pii> del;
			if (lw != S[x].end()) {
				for (auto it = lw; it != hi; it++) del.push_back(*it);
			}
			for (auto a : del) {
				S[x].erase(a);
				int ll = max(a.first, l), rr = min(a.second, r);
				update_mul(1, ll, rr, 2);
			}
			if (!del.size()) {
				update_add(1, l, r, 1);
			}
			if (del.size() > 1) {
				for (int i = 0; i < del.size() - 1; i++) {
					pii a = del[i], b = del[i + 1];
					update_add(1, a.second + 1, b.first - 1, 1);
				}
			}
			int L = l, R = r;
			if (del.size()) {
				L = min(l, del[0].first), R = max(r, del.back().second);
				update_add(1, l, del[0].first - 1, 1);
				update_add(1, del.back().second + 1, r, 1);
			}
			S[x].insert(pii(L, R));
		} else {
			printf("%lld\n", query(1, l, r));
		}
	}
}