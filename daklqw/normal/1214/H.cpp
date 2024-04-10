#include <bits/stdc++.h>
 
const int MAXN = 200010;
void bye() { std::cout << "No\n"; exit(0); }
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
int ansl[MAXN];
int n, K;
void simpledfs(int u, int fa = 0, int col = 1) {
	ansl[u] = col;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa)
			simpledfs(to[i], u, col ^ 1);
}
int dis[MAXN];
void dfsx(int u, int fa = 0) {
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			dis[to[i]] = dis[u] + 1;
			dfsx(to[i], u);
		}
}
const int INF = 0x3f3f3f3f;
struct data {
	int a[3];
	data() { a[0] = a[1] = a[2] = -INF; }
	void insert(int x) {
		if (x >= a[0]) a[2] = a[1], a[1] = a[0], a[0] = x;
		else if (x >= a[1]) a[2] = a[1], a[1] = x;
		else if (x >= a[2]) a[2] = x;
	}
	void shift() { ++a[0], ++a[1], ++a[2]; }
} val[MAXN], vt[MAXN];
void dfs1(int u, int fa = 0) {
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			dfs1(to[i], u);
			val[u].insert(std::max(val[to[i]].a[0], 0) + 1);
		}
}
void dfs2(int u, int fa = 0, int upv = 0) {
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			int tv = std::max(upv, val[u].a[val[to[i]].a[0] + 1 == val[u].a[0]]) + 1;
			dfs2(to[i], u, tv);
		}
	vt[u] = val[u]; if (fa) vt[u].insert(upv);
	if (vt[u].a[2] + vt[u].a[1] + 1 >= K) bye();
}
int li[MAXN], inc[MAXN];
bool mark(int u, int dst, int fa = 0) {
	if (u == dst) {
		li[dis[u]] = u;
		return true;
	}
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			if (mark(to[i], dst, u)) {
				li[dis[u]] = u;
				return true;
			}
		}
	return false;
}
int R;
void dfsmk(int u, int fa, int now, int delta) {
	now = (now + delta) % K;
	ansl[u] = now;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa)
			dfsmk(to[i], u, now, delta);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K;
	for (int i = 1, t1, t2; i < n; ++i) {
		std::cin >> t1 >> t2;
		addedge(t1, t2);
	}
	if (K == 2) simpledfs(1);
	else {
		dfs1(1); dfs2(1);
		dis[1] = 0; dfsx(1);
		int at = 1, rt;
		for (int i = 2; i <= n; ++i) if (dis[i] > dis[at]) at = i;
		dis[at] = 0; dfsx(rt = at);
		at = 1;
		for (int i = 2; i <= n; ++i) if (dis[i] > dis[at]) at = i;
		R = dis[at] + 1;
		mark(rt, at);
		for (int i = 0; i < R; ++i) inc[li[i]] = true;
		for (int i = 0; i < R; ++i) {
			ansl[li[i]] = i % K;
			int dta = R - 1 - i > i ? K - 1 : 1;
			for (int j = head[li[i]]; j; j = nxt[j])
				if (!inc[to[j]])
					dfsmk(to[j], li[i], i, dta);
		}
	}
	std::cout << "Yes" << std::endl;
	for (int i = 1; i <= n; ++i) std::cout << ansl[i] + 1 << ' ';
	std::cout << std::endl;
	return 0;
}