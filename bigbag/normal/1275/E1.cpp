#include <bits/stdc++.h>

using namespace std;

const int max_n = 55, inf = 1000111222;

namespace min_cost_max_flow {

const int max_v = max_n * max_n;
const int DIJKSTRA_N2 = 1;
const int DIJKSTRA_MLOGN = 2;
const int DIJKSTRA_TYPE = DIJKSTRA_MLOGN;

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

void init_phi(int v, int s) {
    if (v == s) {
        phi[v] = 0;
        return;
    }
    if (phi[v] != inf) {
        return;
    }
    for (int id : g[v]) {
        if (edges[id].residual_capacity != 0) {
            continue;
        }
        init_phi(edges[id].v, s);
        phi[v] = min(phi[v], phi[edges[id].v] - edges[id].cost);
    }
}

long long min_cost_max_flow(int s, int t) {
    for (int i = 0; i <= t; ++i) {
        phi[i] = inf;
    }
    init_phi(t, s);
    long long res = 0;
    int it = 0;
    while (dijkstra(s, t)) {
        //cout << "#" << endl;
        memset(start, 0, sizeof(int) * (t + 1));
        while (int x = dfs(s, t, inf)) {
            //cout << "$" << x << endl;
            res += 1LL * x * dist[t];
            break;
        }
    }
    return res;
}

}

int n, m, sz[max_n];
vector<pair<int, int>> e;
char ans[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        ans[u][v] = '1';
        ans[v][u] = '0';
        ++sz[v];
    }
    for (int i = 0; i < n; ++i) {
        ans[i][i] = '0';
        for (int j = i + 1; j < n; ++j) {
            if (!ans[i][j]) {
                e.push_back({i, j});
            }
        }
    }
    int s = e.size() + n;
    int t = s + 1;
    for (int i = 0; i < e.size(); ++i) {
        min_cost_max_flow::add_edge(s, i, 1, 0);
        min_cost_max_flow::add_edge(i, e.size() + e[i].first, 1, 0);
        min_cost_max_flow::add_edge(i, e.size() + e[i].second, 1, 0);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = sz[i] + 1; j < n; ++j) {
            min_cost_max_flow::add_edge(e.size() + i, t, 1, j);
        }
    }
    min_cost_max_flow::min_cost_max_flow(s, t);
    for (int i = 0; i < e.size(); ++i) {
        for (int id : min_cost_max_flow::g[i]) {
            if (min_cost_max_flow::edges[id].residual_capacity == 0) {
                int to = min_cost_max_flow::edges[id].v - e.size();
                if (to == e[i].first || to == e[i].second) {
                    int from = e[i].first ^ e[i].second ^ to;
                    //cout << "@" << from << " " << to << endl;
                    ans[from][to] = '1';
                    ans[to][from] = '0';
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        puts(ans[i]);
    }
    return 0;
}