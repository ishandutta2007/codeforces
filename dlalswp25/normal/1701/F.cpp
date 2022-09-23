#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MX = 200000;

int Q, D;
bool chk[202020];

struct Node {
	int cnt, lz;
	ll sum;

	Node() : cnt(0), sum(0), lz(0) {}

	Node operator+ (const Node& o) const {
		Node ret;
		ret.cnt = cnt + o.cnt;
		ret.sum = sum + o.sum;
		return ret;
	}
};

struct SegTree {
	Node T[4 * 202020];

	void propa(int idx, int s, int e) {
		T[idx].sum += (ll)T[idx].cnt * T[idx].lz;
		if(s != e) {
			T[idx << 1].lz += T[idx].lz;
			T[idx << 1 | 1].lz += T[idx].lz;
		}
		T[idx].lz = 0;
	}

	void upd(int idx, int s, int e, int p, int q, int x) {
		propa(idx, s, e);
		if(q < p || q < s || e < p) return;
		if(p <= s && e <= q) {
			T[idx].lz += x;
			propa(idx, s, e);
			return;
		}
		int m = s + e >> 1;
		upd(idx << 1, s, m, p, q, x);
		upd(idx << 1 | 1, m + 1, e, p, q, x);
		T[idx] = T[idx << 1] + T[idx << 1 | 1];
	}

	void add(int idx, int s, int e, int p, int x) {
		propa(idx, s, e);
		if(p < s || e < p) return;
		if(s == e) {
			T[idx].cnt = 1;
			T[idx].sum = x;
			return;
		}
		int m = s + e >> 1;
		add(idx << 1, s, m, p, x);
		add(idx << 1 | 1, m + 1, e, p, x);
		T[idx] = T[idx << 1] + T[idx << 1 | 1];
	}

	void ers(int idx, int s, int e, int p) {
		propa(idx, s, e);
		if(p < s || e < p) return;
		if(s == e) {
			T[idx].cnt = T[idx].sum = 0;
			return;
		}
		int m = s + e >> 1;
		ers(idx << 1, s, m, p);
		ers(idx << 1 | 1, m + 1, e, p);
		T[idx] = T[idx << 1] + T[idx << 1 | 1];
	}

	ll get(int idx, int s, int e, int p, int q) {
		propa(idx, s, e);
		if(q < p || q < s || e < p) return 0;
		if(p <= s && e <= q) return T[idx].sum;
		int m = s + e >> 1;
		return get(idx << 1, s, m, p, q) + get(idx << 1 | 1, m + 1, e, p, q);
	}
}seg;

struct BIT {
	int T[202020];

	void upd(int x, int v) {
		for(int i = x; i <= MX; i += i&-i) T[i] += v;
	}

	int get(int x) {
		int ret = 0;
		for(int i = x; i; i -= i&-i) ret += T[i];
		return ret;
	}

	int query(int l, int r) {
		if(r < l) return 0;
		return get(r) - get(l - 1);
	}
}fwt;

int main() {
	scanf("%d%d", &Q, &D);
	ll ans = 0;
	while(Q--) {
		int a; scanf("%d", &a);
		if(chk[a]) {
			fwt.upd(a, -1);
			seg.upd(1, 1, MX, max(1, a - D), a - 1, -1);
			seg.ers(1, 1, MX, a);

			ll t = fwt.query(a + 1, min(MX, a + D));
			ll c3 = t * (t - 1) / 2;
			ll c2 = seg.get(1, 1, MX, max(1, a - D), a - 1);
			ans -= c2 + c3;
		}
		else {
			ll t = fwt.query(a + 1, min(MX, a + D));
			ll c3 = t * (t - 1) / 2;
			ll c2 = seg.get(1, 1, MX, max(1, a - D), a - 1);
			ans += c2 + c3;

			fwt.upd(a, 1);
			seg.upd(1, 1, MX, max(1, a - D), a - 1, 1);
			seg.add(1, 1, MX, a, t);
		}
		printf("%lld\n", ans);
		chk[a] = !chk[a];
	}
	return 0;
}