#include <bits/stdc++.h>

const int MAXN = 200010;
int n, m, Q, t1, t2, t3;
char buf[10];
namespace tree {
    int fa[MAXN], son[MAXN], sz[MAXN], top[MAXN], TOT, dfn[MAXN], tree[MAXN << 2], head[MAXN << 1], 
        to[MAXN << 2], nxt[MAXN << 2], tot, val[MAXN << 1], typ[MAXN << 1], n, orin, dep[MAXN];
    void addedge(int b, int e) {
        nxt[++tot] = head[b]; head[b] = tot; to[tot] = e;
        nxt[++tot] = head[e]; head[e] = tot; to[tot] = b;
    }
    void dfs(int u) {
            sz[u] = 1;
            for (int i = head[u]; i; i = nxt[i])
                if (to[i] != fa[u]) {
                    dep[to[i]] = dep[u] + 1;
                    fa[to[i]] = u;
                    dfs(to[i]);
                    sz[u] += sz[to[i]];
                    if (!son[u] || sz[son[u]] < sz[to[i]]) son[u] = to[i];
                }
        }
    void dfs2(int u) {
        dfn[u] = ++TOT;
        if (son[u]) top[son[u]] = top[u], dfs2(son[u]);
        for (int i = head[u]; i; i = nxt[i])
            if (to[i] != son[u] && to[i] != fa[u])
                top[to[i]] = to[i], dfs2(to[i]);
    }
    void modify(int u, int l, int r, int tar, int v) {
        if (l == r) {
            tree[u] = v;
            return;
        }
        int mid = l + r >> 1;
        if (tar <= mid) modify(u << 1, l, mid, tar, v);
        else modify(u << 1 | 1, mid + 1, r, tar, v);
        tree[u] = std::min(tree[u << 1], tree[u << 1 | 1]);
    }
    int query(int u, int l, int r, int L, int R) {
        if (L <= l && r <= R) return tree[u];
        int mid = l + r >> 1, res = 0x3f3f3f3f;
        if (L <= mid) res = std::min(res, query(u << 1, l, mid, L, R));
        if (mid < R) res = std::min(res, query(u << 1 | 1, mid + 1, r, L, R));
        return res;
    }
    std::set<std::pair<int, int> > S[MAXN << 1];
    void addto(int tar, int u, int v) {
    	S[tar].insert(std::make_pair(v, u));
	}
	void change(int tar, int u, int v) {
		S[tar].erase(std::make_pair(val[u], u));
		S[tar].insert(std::make_pair(v, u));
		val[tar] = S[tar].begin() -> first;
		modify(1, 1, n, dfn[tar], val[tar]);
	}
    void run() {
        memset(tree, 0x3f, sizeof tree);
        dep[1] = top[1] = 1;
        dfs(1); dfs2(1);
        for (int i = 1; i <= n; ++i) if (typ[i] != 1 && fa[i]) addto(fa[i], i, val[i]);
        for (int i = 1; i <= n; ++i) if (typ[i] && S[i].size() > 0) val[i] = S[i].begin() -> first;
        for (int i = 1; i <= n; ++i) modify(1, 1, n, dfn[i], val[i]);
        while (Q --> 0) {
            scanf("%s%d%d", &buf, &t2, &t3);
            if (buf[0] == 'C') {
                modify(1, 1, n, dfn[t2], t3);
                change(fa[t2], t2, t3);
                val[t2] = t3;
            } else {
                int ans = 0x3f3f3f3f;
                while (top[t2] != top[t3]) {
                    if (dep[top[t2]] < dep[top[t3]]) std::swap(t2, t3);
                    ans = std::min(ans, query(1, 1, n, dfn[top[t2]], dfn[t2]));
                    t2 = fa[top[t2]];
                }
                if (dep[t2] < dep[t3]) std::swap(t2, t3);
                ans = std::min(ans, query(1, 1, n, dfn[t3], dfn[t2]));
                if (typ[t3] == 1 && fa[t3]) ans = std::min(ans, val[fa[t3]]);
                printf("%d\n", ans);
            }
        }
    }
}
namespace HA {
    int head[MAXN], to[MAXN << 1], nxt[MAXN << 1], tot, bel[MAXN], idx, t0t, dfn[MAXN], low[MAXN], st[MAXN], tp, tnt, val[MAXN];
    void addedge(int b, int e) {
        nxt[++tot] = head[b]; head[b] = tot; to[tot] = e;
        nxt[++tot] = head[e]; head[e] = tot; to[tot] = b;
    }
    void tarjan(int u) {
        st[++tp] = u;
        dfn[u] = low[u] = ++tot;
        for (int i = head[u]; i; i = nxt[i])
            if (!dfn[to[i]]) {
                tarjan(to[i]);
                low[u] = std::min(low[u], low[to[i]]);
                if (dfn[u] <= low[to[i]]) {
                    int v; tree::val[++idx] = 0x3f3f3f3f;
                    do {
                        v = st[tp--];
                        bel[v] = idx;
                        tree::addedge(v, idx);
                    } while (to[i] != v);
                    tree::addedge(u, idx);
                    tree::typ[idx] = 1;
                }
            } else low[u] = std::min(low[u], dfn[to[i]]);
    }
    void run() {
        for (int i = 1; i <= n; ++i) scanf("%d", &val[i]), tree::val[i] = val[i];
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d", &t1, &t2);
            addedge(t1, t2);
        }
        idx = n;
        for (int i = 1; i <= n; ++i) if (!dfn[i]) {tarjan(i); tp = 0;}
        tree::n = idx;
        tree::run();
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &Q);
    HA::run();
    return 0;
}