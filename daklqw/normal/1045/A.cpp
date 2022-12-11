#include <bits/stdc++.h>

const int MAXN = 5010;
const int MAXP = MAXN * 3;
const int MAXE = 500010;
const int INF = 0x3f3f3f3f;
struct _ {
	int to, nxt, val;
} es[MAXE];
int head[MAXP], tot = 1;
void adde(int b, int e, int v) {
	es[++tot] = (_) {e, head[b], v}, head[b] = tot;
	es[++tot] = (_) {b, head[e], 0}, head[e] = tot;
	// std::cout << "ADDE " << b << ' ' << e << ' ' << v << std::endl;
}
int S, T, idx;
int dis[MAXP];
bool bfs() {
	static int que[MAXP], b, e;
	memset(dis, 0, idx + 1 << 2);
	dis[que[b = e = 1] = S] = 1;
	while (b <= e) {
		int t = que[b++];
		for (int i = head[t]; i; i = es[i].nxt)
			if (es[i].val && !dis[es[i].to])
				dis[que[++e] = es[i].to] = dis[t] + 1;
	}
	return dis[T] > 0;
}
int dinic(int u, int minv) {
	if (u == T) return minv;
	int t, res = 0;
	for (int &i = head[u]; i; i = es[i].nxt)
		if (es[i].val && dis[es[i].to] == dis[u] + 1 &&
			(t = dinic(es[i].to, std::min(es[i].val, minv)))) {
			es[i].val -= t;
			es[i ^ 1].val += t;
			res += t;
			if (!(minv -= t)) break;
		}
	if (!res) dis[u] = 0;
	return res;
}
int flow() {
	static int th[MAXP];
	memcpy(th, head, idx + 1 << 2);
	int res = 0;
	while (bfs()) {
		res += dinic(S, INF);
		memcpy(head, th, idx + 1 << 2);
	}
	return res;
}
int bel[MAXN], frm[MAXP];
int n, m;
std::vector<int> opt[MAXN];
int tr[MAXN << 2];
void build(int u, int l, int r) {
	if (l == r) return (void) (tr[u] = bel[l]);
	int mid = l + r >> 1;
	build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
	tr[u] = ++idx;
	adde(tr[u], tr[u << 1], INF);
	adde(tr[u], tr[u << 1 | 1], INF);
}
void qry(int u, int l, int r, int L, int R, int tar) {
	if (L <= l && r <= R) return adde(tar, tr[u], 1);
	int mid = l + r >> 1;
	if (L <= mid) qry(u << 1, l, mid, L, R, tar);
	if (mid < R) qry(u << 1 | 1, mid + 1, r, L, R, tar);
}
int glp(int u) {
	for (int &i = head[u]; i; i = es[i].nxt)
		if (!(i & 1) && es[i ^ 1].val) {
			es[i].val += 1, es[i ^ 1].val -= 1;
			if (es[i].to == T) return u;
			return glp(es[i].to);
		}
	assert(0);
	return -12243;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> m >> n;
	for (int i = 1, typ; i <= m; ++i) {
		std::cin >> typ;
		int sz;
		if (typ == 0) std::cin >> sz;
		else if (typ == 1) sz = 2;
		else sz = 3;
		opt[i].resize(sz + 1);
		opt[i][0] = typ;
		for (int j = 1; j <= sz; ++j)
			std::cin >> opt[i][j];
		if (typ == 2) {
			frm[++idx] = i;
			for (int j = 1; j <= 3; ++j)
				bel[opt[i][j]] = idx;
		}
	}
	for (int i = 1; i <= n; ++i)
		if (!bel[i]) frm[bel[i] = ++idx] = -i;
	S = 0, T = ++idx;
	for (int i = 1; i < idx; ++i)
		adde(i, T, 1);
	build(1, 1, n);
	for (int i = 1; i <= m; ++i)
		if (opt[i][0] <= 1) {
			frm[++idx] = i;
			adde(S, idx, 1);
			if (opt[i][0] == 0) {
				for (auto t : opt[i]) if (t)
					adde(idx, bel[t], 1);
			} else
				qry(1, 1, n, opt[i][1], opt[i][2], idx);
		}
	int fl = flow();
	std::cerr << "FIN " << fl << std::endl;
	static int lst[MAXN];
	for (int i = head[S]; i; i = es[i].nxt)
		if (es[i ^ 1].val)
			lst[frm[es[i].to]] = frm[glp(es[i].to)];
	typedef std::pair<int, int> pi;
	std::vector<pi> ansl;
	for (int i = 1; i <= m; ++i)
		if (lst[i] < 0)
			ansl.emplace_back(i, -lst[i]);
		else if (lst[i] > 0)
			lst[lst[i]] = i;
	for (int i = 1; i <= m; ++i) if (opt[i][0] == 2) {
		int cnt = 0;
		if (int v = lst[i]) {
			if (opt[v][0] == 0) {
				for (auto t : opt[v])
					for (int j = 1; j <= 3; ++j)
						if (t == opt[i][j])
							cnt = t;
			} else {
				int l = opt[v][1], r = opt[v][2];
				for (int j = 1; j <= 3; ++j)
					if (l <= opt[i][j] && opt[i][j] <= r)
						cnt = opt[i][j];
			}
			ansl.emplace_back(v, cnt);
		}
		for (int j = 1, cl = 2; j <= 3 && cl; ++j)
			if (opt[i][j] != cnt)
				--cl, ansl.emplace_back(i, opt[i][j]);
	}
	std::cout << ansl.size() << std::endl;
	for (auto t : ansl)
		std::cout << t.first << ' ' << t.second << '\n';
	return 0;
}