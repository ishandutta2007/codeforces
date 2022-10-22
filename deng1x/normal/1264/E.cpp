#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <cassert>

namespace MCMF {
    const int max_N = 1500;
    const int inf = 0x3f3f3f3f;

    int M, dis[max_N], vis[max_N], pre[max_N], flow, cost;

    struct edge {
        int v, c, w;
    };

    std::vector<edge> e;
    std::vector<int> vec[max_N];

    bool spfa(int n, int s, int t) {
        static int Q[max_N];
        int head = 0, tail = 0;
        memset(dis + 1, 0x3f, n * sizeof(int));
        memset(vis + 1, 0, n * sizeof(int));
        dis[s] = 0, vis[s] = 1, Q[tail++] = s;
        while (head != tail) {
            int u = Q[head++];
            vis[u] = 0;
            if (head == max_N) head = 0;
            for (auto it : vec[u]) {
                if (!e[it].c) continue;
                int v = e[it].v;
                auto tmp = dis[u] + e[it].w;
                if (tmp < dis[v]) {
                    pre[v] = it, dis[v] = tmp;
                    if (!vis[v]) {
                        vis[v] = 1, Q[tail++] = v;
                        if (tail == max_N) tail = 0;
                    }
                }
            }
        }
        return dis[t] < inf;
    }

    int addEdge(int u, int v, int c, int w) {
        int ret;
        e.push_back({v, c, w});
        ret = M;
        vec[u].push_back(M++);
        e.push_back({u, 0, -w});
        vec[v].push_back(M++);
        return ret;
    }

    void minCost(int n, int s, int t) {
        while (spfa(n, s, t)) {
            int adt = ~0U >> 1;
            for (int x = t; x != s; x = e[pre[x] ^ 1].v) {
                adt = std::min(adt, e[pre[x]].c);
            }
            flow += adt;
            cost += adt * dis[t];
            for (int x = t; x != s; x = e[pre[x] ^ 1].v) {
                e[pre[x]].c -= adt;
                e[pre[x] ^ 1].c += adt;
            }
        }
    }
};

const int max_N = 60;

int n, m;

int e1[max_N][max_N];
int e2[max_N][max_N];
int d[max_N];

int main() {
    memset(e1, -1, sizeof(e1));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        e1[i][i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        ++d[u];
        e1[u][v] = 1;
        e1[v][u] = 0;
    }
    int base = n * (n - 1) / 2, S = base + n + 1, T = S + 1;
    for (int i = 1, tot = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j, ++tot) {
            if (e1[i][j] != -1 || e1[j][i] != -1) {
                continue;
            }
            MCMF::addEdge(S, tot, 1, 0);
            e2[i][j] = MCMF::addEdge(tot, base + i, 1, 0);
            e2[j][i] = MCMF::addEdge(tot, base + j, 1, 0);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = d[i]; j < n; ++j) {
            MCMF::addEdge(base + i, T, 1, j);
        }
    }
    MCMF::minCost(T, S, T);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int now = e1[i][j] == -1 ? (1 - MCMF::e[e2[i][j]].c) : e1[i][j];
            printf("%d", now);
        }
        printf("\n");
    }
    return 0;
}