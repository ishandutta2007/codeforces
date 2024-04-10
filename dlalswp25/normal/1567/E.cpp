#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, Q;

int A[202020];

struct Node {
	int ln, rn, len, lv, rv;
	ll x;

	Node() : ln(0), rn(0), len(0), lv(1010101010), rv(0), x(0) {}
	Node(int v) : ln(1), rn(1), len(1), lv(v), rv(v), x(1) {}

	Node operator+ (const Node& o) const {
		Node ret;
		ret.len = len + o.len;
		ret.lv = lv; ret.rv = o.rv;
		ret.x = x + o.x;
		if(ln < len || rv > o.lv) ret.ln = ln;
		else ret.ln = ln + o.ln;
		if(o.rn < o.len || o.lv < rv) ret.rn = o.rn;
		else ret.rn = o.rn + rn;
		if(rv <= o.lv) ret.x += (ll)rn * o.ln;
		return ret;
	}
};

struct SegTree {
	Node T[4 * 202020];

	void upd(int idx, int s, int e, int p, int x) {
		if(p < s || e < p) return;
		if(s == e) {
			T[idx] = Node(x);
			return;
		}
		int m = s + e >> 1;
		upd(idx << 1, s, m, p, x);
		upd(idx << 1 | 1, m + 1, e, p, x);
		T[idx] = T[idx << 1] + T[idx << 1 | 1];
	}

	Node get(int idx, int s, int e, int p, int q) {
		if(q < p || q < s || e < p) return Node();
		if(p <= s && e <= q) return T[idx];
		int m = s + e >> 1;
		return get(idx << 1, s, m, p, q) + get(idx << 1 | 1, m + 1, e, p, q);
	}
}seg;

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		seg.upd(1, 1, N, i, A[i]);
	}

	while(Q--) {
		int t, a, b; scanf("%d%d%d", &t, &a, &b);
		if(t == 1) seg.upd(1, 1, N, a, b);
		else printf("%lld\n", seg.get(1, 1, N, a, b).x);
	}
	return 0;
}