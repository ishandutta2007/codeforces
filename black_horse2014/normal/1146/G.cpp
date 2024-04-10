#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 55;

int s[N], e[N], x[N], c[N], a[N][N];

namespace Dinic {
    const int N = 55000;
    const int M = 5500000;

    int V, E;

    int fst[N];
    int to[M], cap[M], nxt[M];

    void init() {
        memset(fst, -1, sizeof fst);
        V = E = 0;
    }
    inline int add_node() {
        V++;
        return V - 1;
    }
    void add_edge(int u, int v, int w) {
        to[E] = v, cap[E] = w, nxt[E] = fst[u], fst[u] = E++;
        to[E] = u, cap[E] = 0, nxt[E] = fst[v], fst[v] = E++;
    }
    int q[N], dis[N];
    inline int bfs(int S, int T) {
        int qn = 0;
        memset(dis, -1, sizeof dis);
        q[qn++] = S; dis[S] = 0;
        for (int i = 0; i < qn; i++) {
            int u = q[i];
            for (int e = fst[u]; ~e; e = nxt[e]) if (cap[e]) {
                int v = to[e];
                if (dis[v] == -1) {
                    dis[v] = dis[u] + 1;
                    q[qn++] = v;
                }
            }
        }
        return dis[T] != -1;
    }
    int ptr[N];
    inline int dfs(int u, int T, int F) {
        if (u == T) return F;
        for (int e = ptr[u]; ~e; e = nxt[e]) if (cap[e] && dis[to[e]] == dis[u] + 1) {
            int cur = dfs(to[e], T, min(F, cap[e]));
            if (cur) {
                cap[e] -= cur;
                cap[e ^ 1] += cur;
                return cur;
            }
        }
        return 0;
    }
    inline int dinic(int S, int T, int n) {
        int ret = 0;
        while (bfs(S, T)) {
            memcpy(ptr, fst, sizeof(int) * n);
            for (int cur = 0; (cur = dfs(S, T, INF)) > 0; ret += cur);
        }
        return ret;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, h, m; cin >> n >> h >> m;
    Dinic::init();
    int S = Dinic::add_node();
    int T = Dinic::add_node();
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < h; j++) a[i][j] = Dinic::add_node();
        a[i][h] = T;
        int P = S;
        for (int j = 0; j <= h; j++) {
            Dinic::add_edge(P, a[i][j], h * h - j * j);
            P = a[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> s[i] >> e[i] >> x[i] >> c[i];
        if (x[i] >= h) continue;
        int cur = Dinic::add_node();
        for (int j = s[i]; j <= e[i]; j++) Dinic::add_edge(a[j][x[i]], cur, INF);
        Dinic::add_edge(cur, T, c[i]);
    }
    cout << -(Dinic::dinic(S, T, Dinic::V) - h * h * n) << endl;
    return 0;
}