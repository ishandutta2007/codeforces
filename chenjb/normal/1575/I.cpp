#include <bits/stdc++.h>

using namespace std;

struct RootedTree {
    using len_type = long long;
    using pr = pair<len_type, int>;
    static const int MAXD = 21; // for LCA; (1 << (MAXD - 1)) >= N
    vector<vector<pr> >e;
    vector<int> fa;
    vector<len_type> dis_to_root; // dis from root
    vector<int> dep; // Root has a dep of 1
    vector<vector<int> > anc; // anc[i][j] is the (2^j) ancestor of i
    vector<int> dfn, dfnL, dfnR;

    int N, Root;
    RootedTree() {}
    RootedTree(int _N, int _Root = 1) : N(_N), Root(_Root) {
        e.assign(N + 1, vector<pr>());
        fa.assign(N + 1, 0);
        dis_to_root.assign(N + 1, 0);
        dep.assign(N + 1, 0);
        dfn.assign(N + 1, 0); // If need multiple dfn, modify to 2 * N + 1?
        dfnL.assign(N + 1, 0);
        dfnR.assign(N + 1, 0);
    }
    void add_edge(int u, int v, len_type w = 1) {
        e[u].push_back(pr(w, v));
        e[v].push_back(pr(w, u));
    }
    void dfs(int x, int FA, bool calc_lca, int &time_tag) {
        dfn[++time_tag] = x;
        dfnL[x] = time_tag;
        fa[x] = FA;
        if (calc_lca) {
            anc[x][0] = FA;
            for (int i = 1; i < MAXD; i++) anc[x][i] = anc[anc[x][i - 1]][i - 1];
        }
        for (auto &t : e[x]) {
            if (t.second == FA) continue;
            dep[t.second] = dep[x] + 1;
            dis_to_root[t.second] = dis_to_root[x] + t.first;
            dfs(t.second, x, calc_lca, time_tag);
        }
        dfnR[x] = time_tag;
    }
    void init(bool calc_lca = false) {
        dep[Root] = 1;
        dis_to_root[Root] = 0;
        if (calc_lca) anc.assign(N + 1, vector<int>(MAXD, 0));
        int time_tag = 0;
        dfs(Root, 0, calc_lca, time_tag);
    }
    int lca(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        int delta = dep[u] - dep[v];
        for (int i = MAXD - 1; i >= 0; i--) {
            if (delta & (1 << i)) {
                u = anc[u][i];
            }
        }
        if (u == v) return u;
        for (int i = MAXD - 1; i >= 0; i--) {
            if (anc[u][i] != anc[v][i]) {
                u = anc[u][i];
                v = anc[v][i];
            }
        }
        return anc[u][0];
    }
    int K_ancestor(int x, int K) {
        for (int i = 0; i < MAXD; i++) {
            if ((K >> i) & 1) x = anc[x][i];
        }
        return x;
    }
    int unweighted_dis(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    len_type weighted_dis(int u, int v) {
        return dis_to_root[u] + dis_to_root[v] - 2 * dis_to_root[lca(u, v)];
    }
};

int n, m;
typedef long long LL;
LL tr[200010];
int lowbit(int x) {
    return x & - x;
}
void add(int x, LL y) {
    while(x <= n) {
        tr[x] += y;
        x += lowbit(x);
    }
}
LL getsum(int x) {
    LL ret = 0;
    while(x) {
        ret += tr[x];
        x -= lowbit(x);
    }
    return ret;
}
void range_add(int L, int R, LL delta) {
    add(L, delta);
    add(R + 1, -delta);
}

LL c[100010];

int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld",&c[i]);
        c[i] = abs(c[i]);
    }
    RootedTree T(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        T.add_edge(u, v);
    }
    T.init(true);
    for (int i = 1; i <= n; i++) {
        range_add(T.dfnL[i], T.dfnR[i], c[i]);
    }
    while(m--) {
        int tp, u, v;
        scanf("%d%d%d",&tp,&u,&v);
        if (tp == 1) {
            v = abs(v);
            range_add(T.dfnL[u], T.dfnR[u], v - c[u]);
            c[u] = v;
        } else {
            int LCA = T.lca(u, v);
            LL ans = getsum(T.dfnL[u]) + getsum(T.dfnL[v]);
            ans -= getsum(T.dfnL[LCA]);
            if (LCA != 1) ans -= getsum(T.dfnL[T.fa[LCA]]);
            ans *= 2;
            ans -= c[u] + c[v];
            printf("%lld\n",ans);
        }
    }
}