#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

const int maxn = 1 << 20;

struct LCT {
	int fa[maxn], ch[maxn][2];
	bool inv[maxn];
	int val[maxn], mx[maxn], tag[maxn];
#define LS ch[now][0]
#define RS ch[now][1]

	void inline init_node(int now, int x) {
		val[now] = mx[now] = x;
		tag[now] = -1;
	}
	
	void inline push_inv(int now) {
		inv[now] ^= 1;
		swap(LS, RS);
	}
	
	void inline push_tag(int now, int x) {
		if (~mx[now]) {
			if (~val[now]) val[now] = x;
			tag[now] = x; mx[now] = x;
		}
	}
	
	void inline pu(int now) {
		mx[now] = max(val[now], max(mx[LS], mx[RS]));
	}

	void inline pd(int now) {
		if (inv[now]) {
			if (LS) push_inv(LS);
			if (RS) push_inv(RS);
			inv[now] = 0;
		}
		if (~tag[now]) {
			if (LS) push_tag(LS, tag[now]);
			if (RS) push_tag(RS, tag[now]);
			tag[now] = -1;
		}
	}

	int inline get(int now) {
		return ch[fa[now]][1] == now;
	}

	bool inline isroot(int now) {
		return ch[fa[now]][0] != now && ch[fa[now]][1] != now;
	}

	void inline rotate(int x) {
		int y = fa[x], z = fa[y], g = get(x);
		if (!isroot(y)) ch[z][get(y)] = x;
		ch[y][g] = ch[x][!g]; fa[ch[x][!g]] = y;
		ch[x][!g] = y; fa[y] = x; fa[x] = z;
		pu(y); pu(x);
	}

	void inline upd(int x) {
		if (!isroot(x)) upd(fa[x]);
		pd(x);
	}

	void inline splay(int x) {
		upd(x);
		for (int f; f = fa[x], !isroot(x); rotate(x)) {
			if (!isroot(f)) rotate(get(f) == get(x) ? f : x);
		}
	}

	int inline access(int x) {
		int y;
		for (y = 0; x; y = x, x = fa[x]) {
			splay(x);
			ch[x][1] = y;
			pu(x);
		}
		return y;
	}

	void inline enroot(int x) {
		access(x);
		splay(x);
		push_inv(x);
		pd(x);
	}

	void inline link(int f, int x) {
		enroot(x);
		fa[x] = f;
	}

	void inline split(int x, int y) {
		enroot(x);
		access(y);
		splay(y);
	}

	void inline cut(int x, int now) {
		split(x, now);
		fa[x] = LS = RS = 0;
	}

	int inline find(int now) {
		access(now); splay(now);
		while (LS) now = LS;
		return splay(now), now;
	}

	int inline query(int u, int v) {
		split(u, v);
		return mx[v];
	}

	void inline modify(int u, int v, int x) {
		split(u, v);
		push_tag(v, x);
	}
} t;

int N, M;
int u[maxn], v[maxn];
bool ise[maxn];

void addedge(int i) {
	int u = ::u[i], v = ::v[i];
	if (t.find(u) == t.find(v)) {
		t.modify(u, v, i);
		ise[i] = 0;
	}
	else {
		t.link(u, i + N);
		t.link(v, i + N);
		ise[i] = 1;
	}
}

void remedge(int i) {
	int u = ::u[i], v = ::v[i];
	if (!ise[i]) {
		t.modify(u, v, 0);
		return;
	}
	int ni = t.query(u, v);
	if (ni > 0) {
		int nu = ::u[ni], nv = ::v[ni];
		t.modify(nu, nv, 0);
		t.cut(u, i + N);
		t.cut(v, i + N);
		t.link(nu, ni + N);
		t.link(nv, ni + N);
		ise[ni] = 1;
	}
	else {
		t.cut(u, i + N);
		t.cut(v, i + N);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; ++i) {
		scanf("%d%d", u + i, v + i);
	}
	for (int i = 1; i <= N; ++i) t.init_node(i, -1);
	for (int i = 1; i <= M; ++i) t.init_node(i + N, 0);
	int lptr = 1;
	ll ans = 0;
	for (int i = 1; i <= M; ++i) {
		int u = ::u[i], v = ::v[i];
		while (t.find(u) == t.find(v) && t.query(u, v) > 0) remedge(lptr++);
		addedge(i);
		ans += i - lptr + 1;
	}
	printf("%lld\n", ans);
	return 0;
}