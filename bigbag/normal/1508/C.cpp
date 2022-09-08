/**
 *  created: 16/04/2021, 18:28:17
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1333111222;
const int max_comp = 700;

int n, m, comp[max_n], from[max_n], to[max_n], w[max_n];
int tot_xor, comps, dist[max_comp][max_comp], closest[max_comp], used[max_comp];
long long all_dist[max_comp][max_comp];
set<int> edges[max_n], not_visited;

void dfs(int v) {
    comp[v] = comps;
    vector<int> go;
    for (int to : not_visited) {
        if (!edges[v].count(to)) {
            go.push_back(to);
        }
    }
    for (int to : go) {
        not_visited.erase(to);
    }
    for (int to : go) {
        dfs(to);
    }
}

void calc_dist() {
    assert(comps < max_comp);
    for (int i = 0; i < comps; ++i) {
        for (int j = 0; j < comps; ++j) {
            dist[i][j] = inf;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int it = 0; it < 2; ++it) {
            dist[comp[from[i]]][comp[to[i]]] = min(dist[comp[from[i]]][comp[to[i]]], w[i]);
            swap(from[i], to[i]);
        }
    }
}

long long mst(int comps) {
    for (int i = 0; i < comps; ++i) {
        used[i] = 0;
    }
    used[0] = 1;
    for (int i = 1; i < comps; ++i) {
        closest[i] = dist[0][i];
    }
    long long ans = 0;
    for (int it = 1; it < comps; ++it) {
        int v = -1;
        for (int i = 0; i < comps; ++i) {
            if (!used[i] && (v == -1 || closest[v] > closest[i])) {
                v = i;
            }
        }
        ans += closest[v];
        used[v] = 1;
        for (int i = 0; i < comps; ++i) {
            closest[i] = min(closest[i], dist[v][i]);
        }
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &from[i], &to[i], &w[i]);
        --from[i];
        --to[i];
        edges[from[i]].insert(to[i]);
        edges[to[i]].insert(from[i]);
        tot_xor ^= w[i];
    }
    memset(comp, -1, sizeof(comp));
    for (int i = 0; i < n; ++i) {
        not_visited.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        if (comp[i] == -1) {
            not_visited.erase(i);
            dfs(i);
            ++comps;
        }
    }
    if (0) {
        cout << comps << endl;
        for (int i = 0; i < n; ++i) {
            cout << comp[i] << " ";
        }
    }
    calc_dist();
    long long ans = mst(comps);
    long long edges = 1LL * n * (n - 1) / 2 - m;
    if (edges == n - comps) {
        assert(n < max_comp);
        memset(all_dist, -1, sizeof(all_dist));
        for (int i = 0; i < m; ++i) {
            if (from[i] > to[i]) {
                swap(from[i], to[i]);
            }
            all_dist[from[i]][to[i]] = all_dist[to[i]][from[i]] = w[i];
        }
        vector<pair<int, int>> all;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (all_dist[i][j] == -1) {
                    all.push_back({i, j});
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (all_dist[i][j] == -1) {
                    all_dist[i][j] = 0;
                }
                dist[i][j] = all_dist[i][j];
            }
        }
        ans = 1e18;
        for (auto p : all) {
            dist[p.first][p.second] = dist[p.second][p.first] = tot_xor;
            //cout << "#" << p.first << " " << p.second << ": " << mst(n) << endl;
            ans = min(ans, mst(n));
            dist[p.first][p.second] = dist[p.second][p.first] = 0;
        }
    }
    cout << ans << "\n";
    return 0;
}