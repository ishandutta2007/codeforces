#include <bits/stdc++.h>

const int MAXN = 3e5 + 10;

char buf[MAXN];
int head[MAXN], nxt[MAXN];
int fa[MAXN];
int ST[20][MAXN << 1], idx;
int in[MAXN];
inline int gmi(int x, int y) { return in[x] < in[y] ? x : y;
}
int LCA(int x, int y) {
	if ((x = in[x]) > (y = in[y])) std::swap(x, y);
	const int L = std::__lg(++y - x);
	return gmi(ST[L][x], ST[L][y - (1 << L)]);
}

int dep[MAXN];

const int mod1 = 1004535809;
// const int bse1 = 114514;
// const int ibse1 = 891822249;
const int bse1 = 1919810;
const int ibse1 = 539515802;
typedef long long LL;

int pw1[MAXN], ipw1[MAXN];
void inithash(int n) {
	for (int i = *pw1 = 1; i <= n; ++i)
		pw1[i] = (LL) pw1[i - 1] * bse1 % mod1;
	for (int i = *ipw1 = 1; i <= n; ++i)
		ipw1[i] = (LL) ipw1[i - 1] * ibse1 % mod1;
}
struct Hash {
	int a, L;
	void push_back(int x) {
		a = ((LL) a * bse1 + x) % mod1, ++L;
	}
	void push_front(int x) {
		a = ((LL) x * pw1[L] + a) % mod1, ++L;
	}
	Hash operator + (Hash b) {
		b.a = ((LL) a * pw1[b.L] + b.a) % mod1;
		b.L += L;
		return b;
	}
	bool operator == (Hash b) {
		return a == b.a; // L == b.L
	}
} ud[MAXN], du[MAXN];

Hash dug(int x, int y) {
	Hash r;
	r.L = du[x].L - du[y].L;
	r.a = (LL) (du[x].a - du[y].a + mod1) * ipw1[du[y].L] % mod1;
	return r;
}

Hash udg(int x, int y) {
	Hash r;
	r.L = ud[x].L - ud[y].L;
	r.a = (ud[x].a - (LL) ud[y].a * pw1[r.L]) % mod1;
	r.a += r.a >> 31 & mod1;
	return r;
}
namespace gr {
	int head[MAXN], to[MAXN << 1], nxt[MAXN << 1], tot;
	void adde(int b, int e) {
		nxt[++tot] = head[b]; to[head[b] = tot] = e;
		nxt[++tot] = head[e]; to[head[e] = tot] = b;
	}
	void dfs(int u) {
		(ud[u] = ud[fa[u]]).push_back(buf[u]);
		(du[u] = du[fa[u]]).push_front(buf[u]);
		ST[0][++idx] = u;
		in[u] = idx;
		for (int i = head[u]; i; i = nxt[i])
			if (to[i] != fa[u]) {
				dep[to[i]] = dep[u] + 1;
				fa[to[i]] = u;
				dfs(to[i]);
				ST[0][++idx] = u;
			}
	}
}
const int MAXM = 2e6 + 10;
typedef std::pair<int, int> pi;

struct chain {
	int x, y, L;
	int l, r, lhs, len;
	Hash tol;
	pi getq(int a) {
		return a <= lhs ? pi(x, a - 1) : pi(y, len - a);
	}
	Hash getha(int a, int u) {
		return a <= lhs ? dug(x, fa[u]) : tol + udg(u, L);
	}
	void init() {
		L = LCA(x, y);
		len = dep[x] + dep[y] - dep[L] * 2 + 1;
		l = 1;
		lhs = dep[x] - dep[L] + 1;
		tol = dug(x, fa[L]);
	}
} qs[MAXM];

struct _ {
	int nxt, k, id;
} ls[MAXM];
int qh[MAXN], tot;
void addq(pi q, int id) {
	ls[++tot] = (_) {qh[q.first], q.second, id};
	qh[q.first] = tot;
}
int st[MAXN], qtar[MAXM];
void dfs(int u) {
	st[dep[u]] = u;
	for (int i = head[u]; i; i = nxt[i]) dfs(i);
	for (int & i = qh[u]; i; i = ls[i].nxt)
		qtar[ls[i].id] = st[dep[u] - ls[i].k];
}

int ansl[MAXM];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int n; std::cin >> n >> buf + 1;
	for (int i = 1, b, e; i < n; ++i)
		std::cin >> b >> e, gr::adde(b, e);
	inithash(n); gr::dfs(1);
	for (int i = 2; i <= n; ++i)
		nxt[i] = head[fa[i]], head[fa[i]] = i;
	for (int i = 1; i != 20; ++i)
		for (int j = 1; j + (1 << i) - 1 <= idx; ++j)
			ST[i][j] = gmi(ST[i - 1][j], ST[i - 1][j + (1 << i - 1)]);
	int Q; std::cin >> Q;
	for (int i = 1; i <= Q; ++i) {
		const int a = i * 2 - 1, b = i * 2;
		std::cin >> qs[a].x >> qs[a].y >> qs[b].x >> qs[b].y;
		qs[a].init(), qs[b].init();
		qs[a].r = qs[b].r = std::min(qs[a].len, qs[b].len);
	}
	for (int T = 1; (1 << T - 1) <= n; ++T) {
		tot = 0;
		for (int i = 1; i <= Q; ++i) {
			const int a = i * 2 - 1, b = i * 2;
			int l = qs[a].l, r = qs[a].r;
			if (l > r) continue;
			int mid = l + r >> 1;
			addq(qs[a].getq(mid), a);
			addq(qs[b].getq(mid), b);
		}
		dfs(1);
		for (int i = 1; i <= Q; ++i) {
			const int a = i * 2 - 1, b = i * 2;
			int l = qs[a].l, r = qs[a].r;
			if (l > r) continue;
			int mid = l + r >> 1;
			Hash x = qs[a].getha(mid, qtar[a]);
			Hash y = qs[b].getha(mid, qtar[b]);
			if (x == y) {
				ansl[i] = mid;
				qs[a].l = qs[b].l = mid + 1;
			} else {
				qs[a].r = qs[b].r = mid - 1;
			}
		}
	}
	for (int i = 1; i <= Q; ++i)
		std::cout << ansl[i] << '\n';
	return 0;
}