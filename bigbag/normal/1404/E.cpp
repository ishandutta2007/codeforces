#include <bits/stdc++.h>

using namespace std;

const int max_n = 222, inf = 1000111222;

namespace max_flow {

const int max_v = 2 * max_n * max_n, inf = 1000111222;

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
        memset(num, 0, sizeof(num));
        while (int f = dfs(s, t, inf)) {
            res += f;
        }
    }
    return res;
}

}

int n, m, num_hor[max_n][max_n], num_ver[max_n][max_n];
string s[max_n];
vector<pair<int, int>> hor, ver;

bool is_in(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int ss = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            if (s[i][j] == '#' && s[i][j + 1] == '#') {
                num_hor[i][j] = ss++;
                hor.push_back({i, j});
            }
        }
    }
    memset(num_ver, -1, sizeof(num_ver));
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '#' && s[i + 1][j] == '#') {
                num_ver[i][j] = ss++;
                ver.push_back({i, j});
            }
        }
    }
    int tt = ss + 1;
    for (const auto &p : hor) {
        max_flow::add_edge(ss, num_hor[p.first][p.second], 1);
    }
    for (const auto &p : ver) {
        max_flow::add_edge(num_ver[p.first][p.second], tt, 1);
    }
    for (const auto &p : hor) {
        int x = p.first, y = p.second;
        const int from = num_hor[x][y];
        for (int dx = -1; dx <= 0; ++dx) {
            for (int dy = 0; dy <= 1; ++dy) {
                int nx = x + dx, ny = y + dy;
                if (is_in(nx, ny) && num_ver[nx][ny] != -1) {
                    max_flow::add_edge(from, num_ver[nx][ny], inf);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans += s[i][j] == '#';
        }
    }
    ans -= ((int) hor.size());
    ans -= ((int) ver.size());
    ans += max_flow::dinic(ss, tt);
    cout << ans << "\n";
    return 0;
}