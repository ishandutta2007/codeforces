#include <bits/stdc++.h>

const int MAXN = 510;
const int MAXP = MAXN * 2;
const int MAXE = MAXP * 50;
const int HUGENUM = 100000000;
typedef long long LL;
struct _ {
	int to, nxt, val, cost;
} es[MAXE];
int head[MAXP], tot = 1;
void adde(int b, int e, int v, int c) {
	es[++tot] = (_) {e, head[b], v, c}; head[b] = tot;
	es[++tot] = (_) {b, head[e], 0, -c}; head[e] = tot;
}
LL dis[MAXP];
int S, T, inq[MAXP], idx;
std::queue<int> q;
const LL NINF = 0xcfcfcfcfcfcfcfcfLL;
bool bellmanford() {
	memset(dis, 0xcf, idx + 1 << 3);
	dis[S] = 0, q.push(S);
	while (!q.empty()) {
		int t = q.front(); q.pop(); inq[t] = false;
		for (int i = head[t]; i; i = es[i].nxt) {
			const int v = es[i].to;
			if (es[i].val && dis[v] < dis[t] + es[i].cost) {
				dis[v] = dis[t] + es[i].cost;
				if (!inq[v]) {
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}
	return dis[T] != NINF;
}
int dinic(int u, int minv) {
	if (u == T) return minv;
	int res = 0, t;
	inq[u] = true;
	for (int & i = head[u]; i; i = es[i].nxt)
		if (es[i].val && !inq[es[i].to] && dis[es[i].to] == dis[u] + es[i].cost && (t = dinic(es[i].to, std::min(es[i].val, minv)))) {
			es[i].val -= t;
			es[i ^ 1].val += t;
			res += t;
			minv -= t;
			if (!minv) break;
		}
	inq[u] = false;
	if (!res) dis[u] = NINF;
	return res;
}
std::pair<int, LL> flow() {
	LL co = 0; int fl = 0;
	static int qh[MAXP];
	memcpy(qh, head, idx + 1 << 2);
	while (bellmanford()) {
		int t = dinic(S, 0x3f3f3f3f);
		fl += t, co += (LL) t * dis[T];
		memcpy(head, qh, idx + 1 << 2);
	}
	return std::make_pair(fl, co);
}
std::vector<int> tr1[MAXN], tr2[MAXN];
int l1[MAXN], l2[MAXN];
inline int tr(int x) { return x > 1000 ? 0 : HUGENUM; }
void dfs(int u, int dta, int fa) {
	if (dta) adde(u + dta, fa, l2[u], tr(l2[u]));
	else adde(fa, u + dta, l1[u], tr(l1[u]));
	for (auto t : (dta ? tr2[u] : tr1[u]))
		if (t + dta != fa)
			dfs(t, dta, u + dta);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int n, rt1, rt2;
	std::cin >> n >> rt1 >> rt2;
	S = 0, T = idx = n * 2 + 1;
	for (int i = 1, t; i <= n; ++i)
		std::cin >> t, adde(i, i + n, 1, t);
	for (int i = 1, b, e; i < n; ++i)
		std::cin >> b >> e, tr1[b].push_back(e), tr1[e].push_back(b);
	for (int i = 1, b, e; i < n; ++i)
		std::cin >> b >> e, tr2[b].push_back(e), tr2[e].push_back(b);
	memset(l1, 0x3f, sizeof l1);
	memset(l2, 0x3f, sizeof l2);
	int ddsm = 0;
	int Q; std::cin >> Q;
	for (int i = 1, x, y; i <= Q; ++i)
		std::cin >> x >> y, l1[x] = y, ddsm += y;
	std::cin >> Q;
	for (int i = 1, x, y; i <= Q; ++i)
		std::cin >> x >> y, l2[x] = y, ddsm += y;
	dfs(rt1, 0, S), dfs(rt2, n, T);
	auto res = flow();
	if (res.first != l1[rt1] || res.first != l2[rt2] ||
		res.second / HUGENUM != ddsm)
		res.second = -1;
	else res.second %= HUGENUM;
	std::cout << res.second << std::endl;
	return 0;
}