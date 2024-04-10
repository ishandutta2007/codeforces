#include <bits/stdc++.h>

const int MAXN = 100010;
const int mod1 = 1234577, mod2 = 1004535809;
const int bse1 = 12243, bse2 = 31873;
typedef long long LL;
std::mt19937 rd(time(0));
struct hash {
	int x, y;
	hash() { x = y = 0; }
	hash(int a, int b) { x = a, y = b; }
	void front(const hash & a) {
		x = ((LL) x * bse1 + a.x) % mod1,
		y = ((LL) y * bse2 + a.y) % mod2;
	}
	void back(const hash & a, const hash & b) {
		x = ((LL) a.x * b.x + x) % mod1;
		y = ((LL) a.y * b.y + y) % mod2;
	}
} ch[256], pw[MAXN];
void init() {
	for (int i = 0; i < 256; ++i)
		ch[i].x = rd() % mod1, ch[i].y = rd() % mod2;
	pw[0].x = pw[0].y = 1;
	for (int i = 1; i != MAXN; ++i) {
		pw[i].x = (LL) pw[i - 1].x * bse1 % mod1;
		pw[i].y = (LL) pw[i - 1].y * bse2 % mod2;
	}
}
int head[MAXN], nxt[MAXN], fa[MAXN], fae[MAXN];
int n, Q;
int up[17][MAXN], dep[MAXN];
namespace graph {
	struct _ {
		int to, nxt, v;
	} es[MAXN << 1];
	int tot, head[MAXN];
	void dfs(int u) {
		up[0][u] = fa[u];
		for (int i = 1; i != 17; ++i)
			up[i][u] = up[i - 1][up[i - 1][u]];
		for (int i = head[u]; i; i = es[i].nxt) {
			const int v = es[i].to;
			if (v != fa[u]) {
				dep[v] = dep[u] + 1;
				fa[v] = u;
				fae[v] = es[i].v;
				nxt[v] = ::head[u];
				::head[u] = v;
				dfs(v);
			}
		}
	}
	void init() {
		for (int i = 1, b, e; i < n; ++i) {
			static char buf[10];
			std::cin >> b >> e >> buf;
			es[++tot] = (_) {e, head[b], *buf}; head[b] = tot;
			es[++tot] = (_) {b, head[e], *buf}; head[e] = tot;
		}
		dfs(1);
	}
}
inline int jump(int x, int y) {
	for (int i = 16, t = dep[x] - y; ~i; --i)
		if (t >> i & 1) x = up[i][x];
	return x;
}
inline int LCA(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	if ((x = jump(x, dep[y])) == y) return x;
	for (int i = 16; ~i; --i)
		if (up[i][x] != up[i][y])
			x = up[i][x], y = up[i][y];
	return up[0][x];
}
hash qstr[MAXN], up1[MAXN], up2[MAXN];
int pcur[MAXN];
int ansl[MAXN];
struct QR { int x, y, id, c; } ;
std::vector<QR> qs[MAXN];
QR th[MAXN << 1], tq[MAXN << 1]; int buc[MAXN];
struct hashtable {
	int head[mod1], tot;
	struct _ { int nxt, key; } es[MAXN << 1];
	int getid(const hash & x, bool nx = true) {
		for (int i = head[x.x]; i; i = es[i].nxt)
			if (es[i].key == x.y) return i;
		if (nx) {
			es[++tot] = (_) {head[x.x], x.y};
			return head[x.x] = tot;
		}
		return 0;
	}
} ha0, ha1;
int hav0[MAXN], hav1[MAXN];
void dfs2(int u) {
	int h0 = ha0.getid(up1[u]), h1 = ha1.getid(up2[u]);
	++hav0[h0], ++hav1[h1];
	for (int i = buc[u] + 1; i <= buc[u + 1]; ++i) {
		int hx = (tq[i].y == 1 ? ha0 : ha1).getid(qstr[tq[i].id], false);
		ansl[tq[i].id] += (tq[i].y == 1 ? hav0[hx] : hav1[hx]) * tq[i].c;
	}
	for (int i = head[u]; i; i = nxt[i]) dfs2(i);
	--hav0[h0], --hav1[h1];
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	init();
	std::cin >> n;
	graph::init();
	std::cin >> Q;
	for (int i = 1; i <= Q; ++i) {
		static char buf[110], str[210];
		int x, y, _x, _y, L, lca;
		std::cin >> x >> y >> buf + 1;
		lca = LCA(x, y), L = strlen(buf + 1);
		if (dep[x] + dep[y] - dep[lca] * 2 < L) continue;
		for (int j = L; j; --j)
			qstr[i].front(ch[buf[j]]);
		if (dep[x] - dep[lca] >= L)  {
			_x = jump(x, dep[lca] + L - 1);
			qs[L].push_back((QR) {x, _x, i, 1});
		} else _x = x;
		if (dep[y] - dep[lca] >= L)  {
			_y = jump(y, dep[lca] + L - 1);
			qs[L].push_back((QR) {y, _y, i, 2});
		} else _y = y;
		int bak = 0, tx;
		while (_x != lca) str[bak++] = fae[_x], _x = fa[_x];
		tx = bak;
		while (_y != lca) str[bak++] = fae[_y], _y = fa[_y];
		std::reverse(str + tx, str + bak); str[bak] = 0;
		static int fail[MAXN];
		for (int j = 1; j <= L; ++j) {
			int now = fail[j - 1];
			while (now && (now + 1 == j || buf[j] != buf[now + 1]))
				now = fail[now];
			fail[j] = now + 1 != j && buf[j] == buf[now + 1] ? now + 1 : 0;
		}
		int cur = 0;
		for (int j = 0; j < bak; ++j) {
			while (cur && str[j] != buf[cur + 1]) cur = fail[cur];
			if (str[j] == buf[cur + 1]) ++cur;
			ansl[i] += cur == L;
		}
	}
	for (int i = 1; i <= n; ++i) pcur[i] = i;
	for (int T = 1; T <= 100; ++T) {
		for (int i = 1; i <= n; ++i) {
			const hash & c = ch[fae[pcur[i]]];
			up1[i].back(c, pw[T - 1]);
			up2[i].front(c);
			pcur[i] = fa[pcur[i]];
		}
		if (!qs[T].empty()) {
			memset(buc, 0, n + 2 << 2);
			int bak = 0;
			for (auto t : qs[T]) {
				th[++bak] = (QR) {t.x, t.c, t.id, 1};
				th[++bak] = (QR) {t.y, t.c, t.id, -1};
				++buc[t.x], ++buc[t.y];
			}
			for (int i = 1; i <= n + 1; ++i) buc[i] += buc[i - 1];
			for (int i = bak; i; --i)
				tq[buc[th[i].x]--] = th[i];
			dfs2(1);
			for (int i = 1; i <= n; ++i)
				ha0.head[up1[i].x] = ha1.head[up2[i].x] = 0;
			ha0.tot = ha1.tot = 0;
		}
	}
	for (int i = 1; i <= Q; ++i)
		std::cout << ansl[i] << '\n';
	return 0;
}