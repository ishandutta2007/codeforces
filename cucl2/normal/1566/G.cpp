#include <bits/stdc++.h>
#include <chrono>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

mt19937 Rand(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
	tuple<int, int, int> val;
	int siz, fix;
	int l, r;
} t[2000005];
int nds;

int inline newnode(tuple<int, int, int> x) {
	++nds;
	t[nds].val = x;
	t[nds].siz = 1;
	t[nds].l = t[nds].r = 0;
	t[nds].fix = Rand();
	return nds;
}

void inline pu(int now) {
	t[now].siz = t[t[now].l].siz + 1 + t[t[now].r].siz;
}

int inline merge(int a, int b) {
	if (!a || !b) return a + b;
	int now;
	if (t[a].fix < t[b].fix) {
		now = a;
		t[now].r = merge(t[a].r, b);
	}
	else {
		now = b;
		t[now].l = merge(a, t[b].l);
	}
	pu(now); return now;
}

void inline split_k(int now, int k, int &a, int &b) {
	if (!now) return a = b = 0, void();
	if (t[t[now].l].siz >= k) {
		b = now;
		split_k(t[now].l, k, a, t[b].l);
	}
	else {
		a = now;
		split_k(t[now].r, k - t[t[now].l].siz - 1, t[a].r, b);
	}
	pu(now);
}

void inline split_v(int now, tuple<int, int, int> v, int &a, int &b) {
	if (!now) return a = b = 0, void();
	if (t[now].val >= v) {
		b = now;
		split_v(t[now].l, v, a, t[b].l);
	}
	else {
		a = now;
		split_v(t[now].r, v, t[a].r, b);
	}
	pu(now);
}

void inline insert(int &rt, tuple<int, int, int> v) {
	int L, R; split_v(rt, v, L, R);
	rt = merge(L, merge(newnode(v), R));
}

void inline erase(int &rt, tuple<int, int, int> v) {
	int L, M, R;
	split_v(rt, v, L, R);
	split_k(R, 1, M, R);
	rt = merge(L, R);
}

int inline getrank(int &rt, tuple<int, int, int> v) {
	int L, R;
	split_v(rt, v, L, R);
	int res = t[L].siz;
	rt = merge(L, R);
	return res;
}

tuple<int, int, int> inline getkth(int &rt, int k) {
	int L, M, R;
	split_k(rt, k - 1, L, R);
	split_k(R, 1, M, R);
	auto res = t[M].val;
	rt = merge(L, merge(M, R));
	return res;
}

int rts[100005], rta;
int N, M;

ll query() {
	auto mne = getkth(rta, 1);
	int u, v, w; tie(w, u, v) = mne;
	ll ans = 1e18;
	if (t[rts[u]].siz >= 3) ans = min(ans, (ll)get<0>(getkth(rts[u], 1)) + get<0>(getkth(rts[u], 2)) + get<0>(getkth(rts[u], 3)));
	if (t[rts[v]].siz >= 3) ans = min(ans, (ll)get<0>(getkth(rts[v], 1)) + get<0>(getkth(rts[v], 2)) + get<0>(getkth(rts[v], 3)));
	if (t[rts[u]].siz >= 2 && t[rts[v]].siz >= 2) {
		if (get<2>(getkth(rts[u], 2)) == get<2>(getkth(rts[v], 2))) {
			if (t[rts[u]].siz >= 3) ans = min(ans, (ll)get<0>(getkth(rts[u], 3)) + get<0>(getkth(rts[v], 2)));
			if (t[rts[v]].siz >= 3) ans = min(ans, (ll)get<0>(getkth(rts[u], 2)) + get<0>(getkth(rts[v], 3)));
		}
		else ans = min(ans, (ll)get<0>(getkth(rts[u], 2)) + get<0>(getkth(rts[v], 2)));
	}
	int l = 0, r = t[rta].siz + 1;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		auto mth = getkth(rta, m);
		int q = get<0>(mth);
		int val = getrank(rta, make_tuple(q, Inf, Inf)) - getrank(rts[u], make_tuple(q, Inf, Inf)) - getrank(rts[v], make_tuple(q, Inf, Inf)) + 1;
		if (val) r = m;
		else l = m;
	}
	if (r <= t[rta].siz) ans = min(ans, (ll)w + get<0>(getkth(rta, r)));
	return ans;
}

map<pair<int, int>, int> qs;

void inline add(int u, int v, int w) {
	insert(rta, make_tuple(w, u, v));
	qs[make_pair(u, v)] = w;
	insert(rts[u], make_tuple(w, u, v));
	insert(rts[v], make_tuple(w, v, u));
}

void inline del(int u, int v, int w) {
	erase(rta, make_tuple(w, u, v));
	qs.erase(make_pair(u, v));
	erase(rts[u], make_tuple(w, u, v));
	erase(rts[v], make_tuple(w, v, u));
}

int main() {
	scanf("%d%d", &N, &M);
	repi(i, M) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		if (u > v) swap(u, v);
		add(u, v, w);
	}
	printf("%lld\n", query());
	int q; scanf("%d", &q);
	while (q--) {
		int op; scanf("%d", &op);
		if (op == 0) {
			int u, v; scanf("%d%d", &u, &v);
			if (u > v) swap(u, v);
			del(u, v, qs[make_pair(u, v)]);
		}
		else {
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			if (u > v) swap(u, v);
			add(u, v, w);
		}
		printf("%lld\n", query());
	}
	return 0;
}