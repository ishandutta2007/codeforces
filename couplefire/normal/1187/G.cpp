#include <bits/stdc++.h>
using namespace std;

struct mincost {
    static const int maxn = 6000 + 5;
    static const int inf = 1e9;
    struct edge {
        int dest, cap, w, rev;
        edge(int a, int b, int c, int d): dest(a), cap(b), w(c), rev(d) {}
    };
    vector<edge> g[maxn];
    int d[maxn], p[maxn], ed[maxn];
    bool inq[maxn];
    void init() {
        for (int i = 0; i < maxn; ++i) g[i].clear();
    }
    void add_edge(int a, int b, int c, int d) {
        g[a].emplace_back(b, c, +d, g[b].size() - 0);
        g[b].emplace_back(a, 0, -d, g[a].size() - 1);
    }
    bool spfa(int s, int t, int &f, int &c) {
        for (int i = 0; i < maxn; ++i) {
            d[i] = inf;
            p[i] = ed[i] = -1;
            inq[i] = false;
        }
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while (q.size()) {
            int x = q.front(); q.pop();
            inq[x] = false;
            for (int i = 0; i < g[x].size(); ++i) {
                edge &e = g[x][i];
                if (e.cap > 0 && d[e.dest] > d[x] + e.w) {
                    d[e.dest] = d[x] + e.w;
                    p[e.dest] = x;
                    ed[e.dest] = i;
                    if (!inq[e.dest]) q.push(e.dest), inq[e.dest] = true;
                }
            }
        }
        if (d[t] == inf) return false;
        int dlt = inf;
        for (int x = t; x != s; x = p[x]) dlt = min(dlt, g[p[x]][ed[x]].cap);
        for (int x = t; x != s; x = p[x]) {
            edge &e = g[p[x]][ed[x]];
            e.cap -= dlt;
            g[e.dest][e.rev].cap += dlt;
        }
        f += dlt; c += d[t] * dlt;
        return true;
    }
    pair<int, int> operator()(int s, int t) {
        int f = 0, c = 0;
        while (spfa(s, t, f, c));
        return make_pair(f, c);
    }
};

const int maxn = 50 + 5;
const int maxd = 100 + 5;
int cap[maxn], rep[maxn][maxd], adj[maxn][maxn];

int main() {
    int n, m, k, c, d; scanf("%d%d%d%d%d", &n, &m, &k, &c, &d);
    for (int i = 0; i < k; ++i) {
        int x; scanf("%d", &x);
        cap[x - 1]++;
    }
    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        --u, --v;
        ++adj[u][v];
        ++adj[v][u];
    }

    mincost flow;

    int sz = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < maxd; ++j)
            rep[i][j] = sz++;
    }

    int st = sz++, ed = sz++;
    for (int i = 0; i < n; ++i) flow.add_edge(st, rep[i][0], cap[i], 0);
    for (int j = 0; j < maxd; ++j)
        flow.add_edge(rep[0][j], ed, 1e9, j * c);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j || !adj[i][j]) continue;
            for (int r = 0; r < adj[i][j]; ++r) {
                for (int k = 0; k + 1 < maxd; ++k) {
                    for (int p = 0; p < maxn; ++p) {
                        int cost = (2 * p + 1) * d;
                        flow.add_edge(rep[i][k], rep[j][k + 1], 1, cost);
                    }
                }
            }
        }
        for (int k = 0; k + 1 < maxd; ++k)
            flow.add_edge(rep[i][k], rep[i][k + 1], 1e9, 0);
    }

    pair<int, int> res = flow(st, ed);
    assert(res.first == k);
    printf("%d\n", res.second);
    return 0;
}