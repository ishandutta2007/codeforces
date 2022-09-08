#include <bits/stdc++.h>

using namespace std;

const int max_n = 55, inf = 1000111222;


namespace min_cost_max_flow {

const int max_v = max_n;
const int DIJKSTRA_N2 = 1;
const int DIJKSTRA_MLOGN = 2;
const int DIJKSTRA_TYPE = DIJKSTRA_N2;

struct edge {
    int v, residual_capacity, cost;

    edge(int v, int residual_capacity, int cost): v(v), residual_capacity(residual_capacity), cost(cost) {
    }
};

vector<edge> edges;
vector<int> g[max_v];

void add_edge(int u, int v, int f, int c) {
    g[u].push_back(edges.size());
    edges.push_back({v, f, c});
    g[v].push_back(edges.size());
    edges.push_back({u, 0, -c});
}

int phi[max_v], dist[max_v];
char used[max_v];

bool dijkstra_mlogn(int s, int t) {
    for (int i = 0; i <= t; ++i) {
        dist[i] = inf;
    }
    dist[s] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, s});
    while (!q.empty()) {
        pair<int, int> p = q.top();
        q.pop();
        const int v = p.second;
        if (-p.first != dist[v]) {
            continue;
        }
        //cout << v << ": " << dist[v] << ", phi = " << phi[v] << endl;
        for (int id : g[v]) {
            if (edges[id].residual_capacity == 0) {
                continue;
            }
            const int to = edges[id].v;
            if (dist[v] + phi[v] - phi[to] + edges[id].cost < dist[to]) {
                dist[to] = dist[v] + phi[v] - phi[to] + edges[id].cost;
                q.push({-dist[to], to});
            }
        }
    }
    for (int i = 0; i <= t; ++i) {
        dist[i] = min(inf, dist[i] + phi[i]);
        phi[i] = dist[i];
    }
    return dist[t] != inf;
}

bool dijkstra_n2(int s, int t) {
    for (int i = 0; i <= t; ++i) {
        dist[i] = inf;
    }
    dist[s] = 0;
    for (int i = 0; i <= t; ++i) {
        int v = -1;
        for (int j = 0; j <= t; ++j) {
            if (!used[j] && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }
        used[v] = 1;
        for (int id : g[v]) {
            if (edges[id].residual_capacity == 0) {
                continue;
            }
            const int to = edges[id].v;
            if (dist[v] + phi[v] - phi[to] + edges[id].cost < dist[to]) {
                dist[to] = dist[v] + phi[v] - phi[to] + edges[id].cost;
            }
        }
    }
    for (int i = 0; i <= t; ++i) {
        dist[i] = min(inf, dist[i] + phi[i]);
        phi[i] = dist[i];
        used[i] = 0;
    }
    return dist[t] != inf;
}

bool dijkstra(int s, int t) {
    if (DIJKSTRA_TYPE == 0) {
        puts("Select dijkstra type");
        exit(1);
    }
    if (DIJKSTRA_TYPE == DIJKSTRA_N2) {
        return dijkstra_n2(s, t);
    } else if (DIJKSTRA_TYPE == DIJKSTRA_MLOGN) {
        return dijkstra_mlogn(s, t);
    }
    puts("Unsupported dijkstra type");
    exit(2);
}

int start[max_v];

int dfs(int v, int t, int f) {
    if (v == t) {
        return f;
    }
    used[v] = 1;
    for (int &i = start[v]; i < g[v].size(); ++i) {
        const int id = g[v][i];
        if (edges[id].residual_capacity && dist[v] + edges[id].cost == dist[edges[id].v] && !used[edges[id].v]) {
            int res = dfs(edges[id].v, t, min(f, edges[id].residual_capacity));
            if (res) {
                f -= res;
                edges[id].residual_capacity -= res;
                edges[id ^ 1].residual_capacity += res;
                used[v] = 0;
                return res;
            }
        }
    }
    used[v] = 0;
    return 0;
}

vector<int> min_cost_max_flow(int s, int t) {
    for (int i = 0; i <= t; ++i) {
        phi[i] = 0;
    }
    int res = 0;
    int it = 0;
    vector<int> v;
    while (dijkstra(s, t)) {
        memset(start, 0, sizeof(int) * (t + 1));
        int x = dfs(s, t, 1);
        res += 1LL * x * dist[t];
        v.push_back(res);
    }
    return v;
}

}

int n, m;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v, x;
        scanf("%d%d%d", &u, &v, &x);
        --u;
        --v;
        min_cost_max_flow::add_edge(u, v, 1, x);
    }
    vector<int> all = min_cost_max_flow::min_cost_max_flow(0, n - 1);
    for (int i = all.size() - 1; i; --i) {
        all[i] -= all[i - 1];
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        int x;
        scanf("%d", &x);
        int i;
        for (i = 0; i + 1 < all.size(); ++i) {
            int need = (i + 1) * (all[i + 1] - all[i]);
            if (x >= need) {
                x -= need;
            } else {
                break;
            }
        }
        double res = all[i] + 1.0 * x / (i + 1);
        printf("%.12f\n", res);
    }
    return 0;
}