#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, max_q = 300333;
const long long inf = 1000111222000111222LL;

struct edge {
    int u, v;
    long long d;

    edge() {
    }

    edge(long long d, int u, int v): d(d), u(u), v(v) {
    }

    bool operator < (const edge &e) const {
        return d < e.d;
    }
};

int n, m, k, q, comp[max_n];
vector<int> g[max_n], d[max_n], allv[max_n], ng[max_n];
vector<pair<int, int>> allq[max_n];
int from[2][max_n], from_comp[2][max_n], used[2][max_n];
long long dist[2][max_n], ans[max_q];
edge closest[max_n];
vector<edge> all;

void dijkstra() {
    priority_queue<pair<long long, int>> q;
    for (int i = 0; i < n; ++i) {
        used[0][i] = used[1][i] = 0;
        dist[0][i] = dist[1][i] = inf;
        from[0][i] = from[1][i] = -1;
        from_comp[0][i] = from_comp[1][i] = -1;
        if (i < k) {
            from[0][i] = i;
            from_comp[0][i] = comp[i];
            dist[0][i] = 0;
            q.push({0, i});
        }
    }
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        int v = p.second;
        int tp = 0;
        if (used[0][v]) {
            if (used[1][v]) {
                continue;
            }
            tp = 1;
        }
        if (-p.first != dist[tp][v]) {
            continue;
        }
        used[tp][v] = 1;
        //cout << v << " " << tp << ": " << dist[tp][v] << ", from_comp = " << from_comp[tp][v] << endl;
        for (int i = 0; i < g[v].size(); ++i) {
            long long nd = -p.first + d[v][i];
            int to = g[v][i];
            if (dist[0][to] > nd) {
                if (from_comp[tp][v] != from_comp[0][to]) {
                    dist[1][to] = dist[0][to];
                    from[1][to] = from[0][to];
                    from_comp[1][to] = from_comp[0][to];
                }
                dist[0][to] = nd;
                from[0][to] = from[tp][v];
                from_comp[0][to] = from_comp[tp][v];
                q.push({-nd, to});
            } else if (dist[1][to] > nd && from_comp[0][to] != from_comp[tp][v]) {
                dist[1][to] = nd;
                from[1][to] = from[tp][v];
                from_comp[1][to] = from_comp[tp][v];
                q.push({-nd, to});
            }
        }
    }
}

void dfs(int v, int c) {
    comp[v] = c;
    for (int to : ng[v]) {
        if (comp[to] == -1) {
            dfs(to, c);
        }
    }
}

int find_set(int v) {
    if (v == comp[v]) {
        return v;
    }
    return comp[v] = find_set(comp[v]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &k, &q);
    while (m--) {
        int u, v, dist;
        scanf("%d%d%d", &u, &v, &dist);
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
        d[u].push_back(dist);
        d[v].push_back(dist);
    }
    for (int i = 0; i < k; ++i) {
        comp[i] = i;
    }
    int comps = k;
    int it = 0;
    while (comps != 1) {
        ++it;
        //cout << "$" << comps << endl;
        dijkstra();
        for (int i = 0; i < comps; ++i) {
            closest[i] = {inf, -1, -1};
        }
        for (int i = 0; i < k; ++i) {
            //cout << i << ": " << comp[i] << ", from = " << from_comp[0][i] << " " << from_comp[1][i] << ", dist = " << dist[0][i] << " " << dist[1][i] << endl;
            assert(from[1][i] != -1);
            closest[comp[i]] = min(closest[comp[i]], {dist[1][i], i, from[1][i]});
        }
        for (int i = 0; i < comps; ++i) {
            ng[closest[i].u].push_back(closest[i].v);
            ng[closest[i].v].push_back(closest[i].u);
            all.push_back(closest[i]);
        }
        for (int i = 0; i < k; ++i) {
            comp[i] = -1;
        }
        comps = 0;
        for (int i = 0; i < k; ++i) {
            if (comp[i] == -1) {
                dfs(i, comps);
                ++comps;
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        allq[u].push_back({v, i});
        allq[v].push_back({u, i});
    }
    sort(all.begin(), all.end());
    for (int i = 0; i < k; ++i) {
        comp[i] = i;
        allv[i].push_back(i);
    }
    for (auto e : all) {
        //cout << e.d << ": " << e.u << " " << e.v << endl;
        int u = find_set(e.u);
        int v = find_set(e.v);
        if (u != v) {
            if (allv[u].size() > allv[v].size()) {
                swap(u, v);
            }
            comp[u] = v;
            //cout << "p[" << u << "] = " << v << "; " << find_set(0) << " " << find_set(1) << " " << find_set(2) << " " << v << endl;
            for (int vert : allv[u]) {
                allv[v].push_back(vert);
                for (auto q : allq[vert]) {
                    if (ans[q.second] == 0 && find_set(q.first) == v) {
                        ans[q.second] = e.d;
                    }
                }
            }
            allv[u].clear();
        }
    }
    for (int i = 0; i < q; ++i) {
        printf("%I64d\n", ans[i]);
    }
    return 0;
}