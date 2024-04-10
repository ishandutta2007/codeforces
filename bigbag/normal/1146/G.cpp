#include <bits/stdc++.h>

using namespace std;

namespace max_flow {

const int max_v = 55 * 55, inf = 1000111222;

struct edge {
    int to, residual_capacity;

    edge(int to, int residual_capacity): to(to), residual_capacity(residual_capacity) {
    }
};

vector<edge> edges;
vector<int> g[max_v];

void add_edge(int u, int v, int capacity) {
    g[u].push_back(edges.size());
    edges.push_back({v, capacity});
    g[v].push_back(edges.size());
    edges.push_back({u, 0});
}

int h[max_v];

bool bfs(int s, int t) {
    for (int i = 0; i <= t; ++i) {
        h[i] = -1;
    }
    h[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int id : g[v]) {
            if (edges[id].residual_capacity && h[edges[id].to] == -1) {
                h[edges[id].to] = h[v] + 1;
                q.push(edges[id].to);
            }
        }
    }
    return h[t] != -1;
}

int dfs(int v, int t, int f) {
    if (v == t) {
        return f;
    }
    for (int id : g[v]) {
        if (edges[id].residual_capacity  && h[v] + 1 == h[edges[id].to]) {
            int res = dfs(edges[id].to, t, min(f, edges[id].residual_capacity));
            if (res) {
                edges[id].residual_capacity -= res;
                edges[id ^ 1].residual_capacity += res;
                return res;
            }
        }
    }
    return 0;
}

int dinic(int s, int t) {
    int res = 0;
    while (bfs(s, t)) {
        while (int f = dfs(s, t, inf)) {
            res += f;
        }
    }
    return res;
}

}

const int max_n = 51, inf = 1000111222;

struct constraint {
    int l, r, h, c;

    void read() {
        scanf("%d%d%d%d", &l, &r, &h, &c);
        --l;
        --r;
    }
};

int n, mx_h, m;
constraint a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &mx_h, &m);
    for (int i = 0; i < m; ++i) {
        a[i].read();
    }
    int s = n * (mx_h + 1) + m;
    int t = s + 1;
    for (int i = 0; i < n; ++i) {
        max_flow::add_edge(s, i * (mx_h + 1), inf);
        for (int j = 0; j < mx_h; ++j) {
            max_flow::add_edge(i * (mx_h + 1) + j, i * (mx_h + 1) + j + 1, mx_h * mx_h - j * j);
        }
        for (int j = 0; j < m; ++j) {
            if (a[j].l <= i && i <= a[j].r && a[j].h < mx_h) {
                max_flow::add_edge(i * (mx_h + 1) + a[j].h + 1, n * (mx_h + 1) + j, inf);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        max_flow::add_edge(n * (mx_h + 1) + i, t, a[i].c);
    }
    int ans = n * mx_h * mx_h - max_flow::dinic(s, t);
    printf("%d\n", ans);
    return 0;
}