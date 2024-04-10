#include <bits/stdc++.h>

const int MAXN = 1000010;
typedef std::vector<int> VI;
int n, m, idx;
int head[MAXN], nxt[MAXN], to[MAXN], tot;
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
}
inline int get(int x, int b) { return x * 2 + b; }
int pre[MAXN], suc[MAXN];
int xs[MAXN], ys[MAXN], cs[MAXN], vs[MAXN];
void build(VI li, int typ) {
	const int sz = li.size();
	memset(pre, 0, sz + 2 << 2);
	memset(suc, 0, sz + 2 << 2);
	for (int i = 1; i <  sz; ++i) pre[i] = ++idx;
	for (int i = 2; i <= sz; ++i) suc[i] = ++idx;
	for (int i = 2; i <  sz; ++i) addedge(pre[i], pre[i - 1]);
	for (int i = 2; i <  sz; ++i) addedge(suc[i], suc[i + 1]);
	for (int i = 1; i <  sz; ++i) addedge(pre[i], get(li[i - 1], typ ^ 1));
	for (int i = 2; i <= sz; ++i) addedge(suc[i], get(li[i - 1], typ ^ 1));
	for (int i = 2; i <= sz; ++i) addedge(get(li[i - 1], typ), pre[i - 1]);
	for (int i = 1; i <  sz; ++i) addedge(get(li[i - 1], typ), suc[i + 1]);
}
VI out[MAXN];
std::map<int, VI> ouc;
void link(int u) {
	for (auto t : out[u]) ouc[cs[t]].push_back(t);
	build(out[u], 0);
	for (auto t : ouc) build(t.second, 1);
	ouc.clear();
}
int nowh[MAXN], nowt;
int dfn[MAXN], low[MAXN], bel[MAXN], cnt, st[MAXN], top, ins[MAXN], t0t;
void tarjan(int u) {
	dfn[u] = low[u] = ++t0t;
	ins[st[++top] = u] = true;
	for (int i = head[u]; i; i = nxt[i])
		if (!dfn[to[i]]) {
			tarjan(to[i]);
			low[u] = std::min(low[u], low[to[i]]);
		} else if (ins[to[i]]) low[u] = std::min(low[u], dfn[to[i]]);
	if (low[u] == dfn[u]) {
		int v; ++cnt;
		do ins[v = st[top--]] = false, bel[v] = cnt; while (v != u);
	}
}
int solve(int lim) {
	memcpy(head, nowh, idx + 1 << 2); tot = nowt;
	for (int i = 1; i <= m; ++i) if (vs[i] > lim)
		addedge(get(i, 0), get(i, 1));
	t0t = cnt = 0;
	memset(dfn, 0, idx + 1 << 2);
	for (int i = 1; i <= idx; ++i) if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= m; ++i)
		if (bel[get(i, 0)] == bel[get(i, 1)])
			return false;
	return true;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	static int li[MAXN], bak;
	for (int i = 1; i <= m; ++i) {
		std::cin >> xs[i] >> ys[i] >> cs[i] >> vs[i];
		out[xs[i]].push_back(i);
		out[ys[i]].push_back(i);
		li[++bak] = vs[i];
	}
	li[++bak] = 0;
	idx = get(m, 1);
	for (int i = 1; i <= n; ++i) link(i);
	memcpy(nowh, head, idx + 1 << 2); nowt = tot;
	std::sort(li + 1, li + 1 + bak);
	bak = std::unique(li + 1, li + 1 + bak) - li - 1;
	int ans = bak;
	if (!solve(li[bak])) {
		std::cout << "No" << std::endl;
		return 0;
	}
	int l = 1, r = bak - 1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (solve(li[mid])) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	solve(li[ans]);
	int cnx = 0;
	for (int i = 1; i <= m; ++i)
		if (bel[get(i, 0)] < bel[get(i, 1)])
			++cnx;
	std::cout << "Yes" << std::endl;
	std::cout << li[ans] << ' ' << cnx << std::endl;
	for (int i = 1; i <= m; ++i)
		if (bel[get(i, 0)] < bel[get(i, 1)])
			std::cout << i << ' ';
	std::cout << std::endl;
	return 0;
}