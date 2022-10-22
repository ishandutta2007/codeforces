//
// Created by Junjie Wu on 2021/2/20.
//

#include <bits/stdc++.h>

const int N = 3e5 + 10;
const int M = 12e6 + 10;
const int BIT = 20;
const int MAX = 1 << BIT;

using ull = unsigned long long;

int n, q;
int a[N];
ull w[N];
std::vector<int> e[N];
// pst
int ch[M][2], rt[N], sz = 0;
ull value[M];
// lca
int top[N][BIT], dep[N];

int copy(int v) {
    int u = ++sz;
    memcpy(ch[u], ch[v], sizeof ch[0]);
    value[u] = value[v];
    return u;
}

void insert(int u, int sit, ull v) {
    for (int i = BIT - 1; i >= 0; --i) {
        value[u] ^= v;
        int pos = (sit >> i) & 1;
        ch[u][pos] = copy(ch[u][pos]);
        u = ch[u][pos];
    }
    value[u] ^= v;
}

void dfs(int u, int fa) {
    insert(rt[u] = copy(rt[fa]), a[u], w[a[u]]);
    top[u][0] = fa;
    for (int i = 1; i < BIT; ++i) {
        top[u][i] = top[top[u][i - 1]][i - 1];
    }
    for (auto &v : e[u]) {
        if (v == fa) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int get_lca(int u, int v) {
    if (dep[u] < dep[v]) std::swap(u, v);
    for (int i = BIT - 1; i >= 0; --i) {
        if (((dep[u] - dep[v]) >> i) & 1) {
            u = top[u][i];
        }
    }
    if (u == v) return u;
    for (int i = BIT - 1; i >= 0; --i) {
        if (top[u][i] != top[v][i]) {
            u = top[u][i];
            v = top[v][i];
        }
    }
    return top[u][0];
}

int query(int t1, int t2, int t3, int t4, int l, int r, int ql, int qr) {
    if ((value[t1] ^ value[t2] ^ value[t3] ^ value[t4]) == 0) return -1;
    if (qr < l || r < ql) return -1;
    if (l == r) return l;
    int mid = (l + r) >> 1;
    int ret = query(ch[t1][0], ch[t2][0], ch[t3][0], ch[t4][0], l, mid, ql, qr);
    if (ret != -1) return ret;
    return query(ch[t1][1], ch[t2][1], ch[t3][1], ch[t4][1], mid + 1, r, ql, qr);
}

int main() {
    std::mt19937_64 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        w[i] = rnd();
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);

    while (q--) {
        int u, v, l, r;
        scanf("%d%d%d%d", &u, &v, &l, &r);
        int lca = get_lca(u, v);
        printf("%d\n", query(rt[u], rt[v], rt[lca], rt[top[lca][0]], 0, MAX - 1, l, r));
    }
    return 0;
}