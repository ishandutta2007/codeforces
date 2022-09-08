#include <bits/stdc++.h>

using namespace std;

const int max_n = 202, inf = 1000111222;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

namespace max_flow {

typedef int CapacityType;
const CapacityType infCapacity = 1000111222;

const int max_v = max_n * max_n;

struct edge {
    int to;
    CapacityType residual_capacity;

    edge(int to, CapacityType residual_capacity): to(to), residual_capacity(residual_capacity) {
    }
};

vector<edge> edges;
vector<int> g[max_v];

template<bool bidirectional = false>
void add_edge(int u, int v, CapacityType capacity) {
    g[u].push_back(edges.size());
    edges.push_back({v, capacity});
    g[v].push_back(edges.size());
    edges.push_back({u, bidirectional ? capacity : 0});
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

CapacityType dfs(int v, int t, CapacityType f) {
    if (v == t) {
        return f;
    }
    for (int &i = num[v]; i < g[v].size(); ++i) {
        const int id = g[v][i];
        if (edges[id].residual_capacity && h[v] + 1 == h[edges[id].to]) {
            CapacityType res = dfs(edges[id].to, t, min(f, edges[id].residual_capacity));
            if (res) {
                edges[id].residual_capacity -= res;
                edges[id ^ 1].residual_capacity += res;
                return res;
            }
        }
    }
    return 0;
}

long long dinic(int s, int t) {
    long long res = 0;
    while (bfs(s, t)) {
        memset(num, 0, sizeof(num[0]) * (t + 1));
        while (CapacityType f = dfs(s, t, infCapacity)) {
            res += f;
        }
    }
    return res;
}

bool reachable[max_v];

void dfs(int v) {
    reachable[v] = 1;
    for (int id : g[v]) {
        if (!reachable[edges[id].to] && edges[id].residual_capacity) {
            dfs(edges[id].to);
        }
    }
}

/**
 * call after dinic(s, t)
 * res[v] = 1 for vertices in "s" set
 * res[v] = 0 for vertices in "t" set
**/
vector<int> get_cut(int s, int t) {
    memset(reachable, 0, sizeof(reachable[0]) * (t + 1));
    dfs(s);
    return {reachable, reachable + t + 1};
}

void clr(int t) {
    edges.clear();
    for (int i = 0; i <= t; ++i) {
        g[i].clear();
    }
}

}

int n, a[max_n][max_n], num[max_n][max_n], from[max_n][max_n], to[max_n][max_n];
vector<int> v;

bool is_in(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < n;
}

void solve(const vector<pair<int, int>> &cur) {
    if (cur.empty() || to[cur[0].first][cur[0].second] - from[cur[0].first][cur[0].second] <= 1) {
        return;
    }
    vector<pair<int, int>> small, big;
    for (int j = 0; j < cur.size(); ++j) {
        num[cur[j].first][cur[j].second] = j;
    }
    const int mid = (from[cur[0].first][cur[0].second] + to[cur[0].first][cur[0].second]) / 2;
    const int cur_val = v[mid + 1];
    const int nxt_val = v[mid];
    //cout << cur.size() << "  " << cur_val << " -> " << nxt_val << endl;
    const int s = cur.size(), t = cur.size() + 1;
    max_flow::clr(t);
    for (auto p : cur) {
        int bal = 0;
        for (int k = 0; k < 4; ++k) {
            const int x = p.first + dx[k], y = p.second + dy[k];
            if (is_in(x, y) && a[x][y] != -1) {
                if (a[x][y] == 0 && k < 2 && from[p.first][p.second] == from[x][y] && to[p.first][p.second] == to[x][y]) {
                    max_flow::add_edge<true>(num[p.first][p.second], num[x][y], cur_val - nxt_val);
                }
                if (a[x][y]) {
                    int curd = abs(cur_val - a[x][y]);
                    int nxtd = abs(nxt_val - a[x][y]);
                    bal += nxtd - curd;
                } else if (from[p.first][p.second] != from[x][y] || to[p.first][p.second] != to[x][y]) {
                    int curd = abs(cur_val - v[to[x][y]]);
                    int nxtd = abs(nxt_val - v[to[x][y]]);
                    bal += nxtd - curd;
                }
            }
        }
        //if (cur.size() == 8 && v[mid] == 2) cout << "#" << p.first << " " << p.second << "  bal = " << bal << endl;
        if (bal < 0) {
            max_flow::add_edge(s, num[p.first][p.second], -bal);
        } else {
            max_flow::add_edge(num[p.first][p.second], t, bal);
        }
    }
    max_flow::dinic(s, t);
    for (int j = 0; j < cur.size(); ++j) {
        if (max_flow::h[j] == -1) {
            from[cur[j].first][cur[j].second] = mid;
            big.push_back(cur[j]);
        } else {
            to[cur[j].first][cur[j].second] = mid;
            small.push_back(cur[j]);
        }
    }
    solve(big);
    solve(small);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    vector<pair<int, int>> cur;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (i == 0 || j == 0 || i + 1 == n || j + 1 == n) {
                v.push_back(a[i][j]);
            } else if (a[i][j] != -1) {
                cur.push_back({i, j});
            }
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!a[i][j]) {
                from[i][j] = -1;
                to[i][j] = v.size() - 1;
            }
        }
    }
    solve(cur);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 0) {
                a[i][j] = v[to[i][j]];
            }
        }
    }
    if (0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 2; ++k) {
                const int x = i + dx[k], y = j + dy[k];
                if (is_in(x, y) && a[i][j] != -1 && a[x][y] != -1) {
                    ans += abs(a[i][j] - a[x][y]);
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}