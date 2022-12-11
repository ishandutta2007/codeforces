#include <bits/stdc++.h>

const int MAXN = 400010;
typedef long long LL;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], val[MAXN << 1], tot;
void addedge(int b, int e, int v) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e; val[tot] = v;
	nxt[++tot] = head[e]; to[head[e] = tot] = b; val[tot] = v;
}
int n, t1, t2, t3;
int vis[MAXN], dep[MAXN], rt[MAXN];
int totcir, nodes[MAXN], pre[MAXN], bak;
void getcircle(int u, int tar, int fa = 0, int dep = 0, int len = 0) {
	pre[dep] = len, nodes[dep] = u;
	if (dep && u == tar) {
		bak = dep;
		return ;
	}
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			if (bak) return ;
			getcircle(to[i], tar, u, dep + 1, len + val[i]);
		}
}
void findcircle(int u, int fa = 0) {
	vis[u] = true;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			if (bak) return ;
			if (vis[to[i]]) {
				getcircle(u, u, 0, 0, 0);
				return ;
			}
			findcircle(to[i], u);
		}
}
LL sum[MAXN]; int sz[MAXN];
void dfs1(int u, int fa = 0) {
	sz[u] = 1;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa && !vis[to[i]]) {
			dep[to[i]] = dep[u] + val[i];
			rt[to[i]] = rt[u];
			dfs1(to[i], u);
			sum[u] += sum[to[i]] + (LL) sz[to[i]] * val[i];
			sz[u] += sz[to[i]];
		}
}
LL totsum[MAXN], rtv[MAXN];
void dfs2(int u, LL tsum, int tsz, int fa = 0) {
	totsum[u] = tsum;
	for (int i = head[u]; i; i = nxt[i]) if (to[i] != fa && !vis[to[i]])
		dfs2(to[i], tsum + (tsz - sz[to[i]] * 2ll) * val[i], tsz, u);
}
LL szmul[MAXN], totvl, szpre[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> t1 >> t2 >> t3;
		addedge(t1, t2, t3);
	}
	findcircle(1);
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= bak; ++i) vis[nodes[i]] = true;
	for (int i = 1; i <= bak; ++i) {
		int u = nodes[i];
		rt[u] = u;
		dfs1(u);
		dfs2(u, sum[u], sz[u]);
		totvl += sum[u];
	}
	int cur = 1;
	totcir = pre[bak];
	for (int i = bak + 1; i <= bak * 2; ++i) {
		nodes[i] = nodes[i - bak];
		pre[i] = pre[i - 1] + pre[i - bak] - pre[i - bak - 1];
	}
	for (int i = 1; i <= bak * 2; ++i) {
		szpre[i] = szpre[i - 1] + sz[nodes[i]];
		szmul[i] = szmul[i - 1] + sz[nodes[i]] * (LL) pre[i];
	}
	for (int i = 1; i <= bak; ++i) {
		while (pre[cur] - pre[i] <= totcir / 2) ++cur;
		LL v = totvl - sum[nodes[i]];
		v += szmul[cur - 1] - szmul[i];
		v -= szmul[i + bak - 1] - szmul[cur - 1];
		v -= (szpre[cur - 1] - szpre[i]) * (LL) pre[i];
		v += (szpre[i + bak - 1] - szpre[cur - 1]) * (LL) (totcir + pre[i]);
		rtv[nodes[i]] = v;
	}
	for (int i = 1; i <= n; ++i) {
		LL val = totsum[i] + rtv[rt[i]] + (LL) dep[i] * (n - sz[rt[i]]);
		std::cout << val << " ";
	}
	std::cout << std::endl;
	return 0;
}