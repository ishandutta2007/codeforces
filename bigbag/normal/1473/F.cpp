/**
 *  created: 14/01/2021, 17:29:23
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 3033, inf = 1000111222;

namespace max_flow {

const int max_v = max_n, inf = 1000111222;

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

int h[max_v], num[max_v];

bool bfs(int s, int t) {
    memset(h, -1, sizeof(h[0]) * (t + 1));
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
                if (edges[id].to == t) {
                    return true;
                }
            }
        }
    }
    return h[t] != -1;
}

int dfs(int v, int t, int f) {
    if (v == t) {
        return f;
    }
    for (int &i = num[v]; i < g[v].size(); ++i) {
        const int id = g[v][i];
        if (edges[id].residual_capacity && h[v] + 1 == h[edges[id].to]) {
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
        memset(num, 0, sizeof(num[0]) * (t + 1));
        while (int f = dfs(s, t, inf)) {
            res += f;
        }
    }
    return res;
}

void clr(int t) {
    edges.clear();
    for (int i = 0; i <= t; ++i) {
        g[i].clear();
    }
}

}

int n, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (0) {
        mt19937 gen;
        n = 3000;
        for (int i = 0; i < n; ++i) {
            a[i] = rand() % 100 + 1;
            b[i] = gen() % 200000 - 100000;
        }
    } else {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &b[i]);
        }
    }
    const int s = n, t = n + 1;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        b[i] *= -1;
        if (b[i] < 0) {
            ans += b[i];
            max_flow::add_edge(s, i, -b[i]);
        } else {
            max_flow::add_edge(i, t, b[i]);
        }
        vector<int> v;
        for (int j = i - 1; j >= 0; --j) {
            if (a[i] % a[j] == 0) {
                bool need_add = true;
                for (int x : v) {
                    need_add &= x % a[j] != 0;
                }
                if (need_add) {
                    max_flow::add_edge(i, j, inf);
                    v.push_back(a[j]);
                }
            }
        }
    }
    //cout << max_flow::edges.size() << endl;
    ans += max_flow::dinic(s, t);
    ans *= -1;
    printf("%d\n", ans);
    return 0;
}