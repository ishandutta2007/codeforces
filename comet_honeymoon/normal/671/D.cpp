#include<bits/stdc++.h>
using namespace std;

struct node;
node *merge(node *x, node *y);

struct node {
    int pos, val;
    node *c[2];
    int lzy, dis;
    void add(int k) { lzy += k; val += k; }
    void pushdown() {
        if (c[0]) c[0] -> add(lzy);
        if (c[1]) c[1] -> add(lzy);
        lzy = 0;
    }
    node *del() { return merge(c[0], c[1]); }
};
int get_dis(node *x) {
    return x ? x -> dis : 0;
}
node *merge(node *x, node *y) {
    if (!x) return y; if (!y) return x;
    x -> pushdown(); y -> pushdown();
    if (x -> val > y -> val) swap(x, y);
    x -> c[1] = merge(x -> c[1], y);
    if (get_dis(x -> c[0]) < get_dis(x -> c[1])) swap(x -> c[0], x -> c[1]);
    x -> dis = get_dis(x -> c[0]) + 1;
    return x;
}

int n, m;
vector<int> G[300005];
int dep[300005];
node *rt[300005];
long long ans;
void solve(int x, int fa) {
    dep[x] = dep[fa] + 1;
    for (int y : G[x]) if (y != fa) solve(y, x), rt[x] = merge(rt[x], rt[y]);
    if (x == 1) return;
    while (rt[x] && dep[rt[x] -> pos] >= dep[x]) rt[x] = rt[x] -> del();
    if (!rt[x]) { printf("-1\n"); exit(0); }
    ans += rt[x] -> val; rt[x] -> add(-rt[x] -> val);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v); G[v].push_back(u);
    }
    while (m--) {
        int u, v, c; scanf("%d%d%d", &u, &v, &c);
        node *p = new node;
        *p = (node){v, c, NULL, NULL, 0, 0};
        rt[u] = merge(rt[u], p);
    }
    solve(1, 0);
    printf("%lld\n", ans);
}