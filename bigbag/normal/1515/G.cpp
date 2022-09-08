/**
 *  created: 02/05/2021, 19:47:42
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, m, used[max_n];
vector<int> g[max_n], rg[max_n], order, comp[max_n];
vector<pair<int, int>> edg[max_n];
long long res[max_n], dist[max_n];

void dfs(int v) {
    used[v] = 1;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
    order.push_back(v);
}

void dfs2(int v, int col) {
    used[v] = col;
    for (int to : rg[v]) {
        if (!used[to]) {
            dfs2(to, col);
        }
    }
}

long long solve(int v) {
    for (int i : comp[used[v]]) {
        dist[i] = 0;
    }
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (const auto &e : edg[v]) {
            const int to = e.first;
            if (used[v] != used[to]) {
                continue;
            }
            if (!dist[to]) {
                dist[to] = dist[v] + e.second;
                q.push(to);
            }
        }
    }
    long long res = dist[v];
    if (!res) {
        return 0;
    }
    while (true) {
        //cout << "#" << res << endl;
        bool ok = 1;
        for (int i : comp[used[v]]) {
            dist[i] %= res;
            //cout << i << ": " << dist[i] << " res = " << res << endl;
        }
        for (int i : comp[used[v]]) {
            for (const auto &e : edg[i]) {
                const int to = e.first;
                if (used[v] != used[to]) {
                    continue;
                }
                long long len = (dist[i] + e.second) % res;
                if (len != dist[to]) {
                    //cout << i << " -> " << to << " " << e.second << "              " << "   " << len << "      " << dist[i] << endl;
                    long long nres = __gcd(res, (len + res - dist[to]) % res);
                    assert(res != nres);
                    res = nres;
                    ok = 0;
                    break;
                }
            }
            if (!ok) {
                break;
            }
        }
        if (ok) {
            break;
        }
    }
    assert(res);
    return res;
}

bool can_zero(int s, int t, long long g) {
    if (!s) {
        return true;
    }
    if (!g) {
        return false;
    }
    g = __gcd(g, 1LL * t);
    return s % g == 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        --u;
        --v;
        //cout << u << " " << v << " " << d << endl;
        g[u].push_back(v);
        rg[v].push_back(u);
        edg[u].push_back({v, d});
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    reverse(order.begin(), order.end());
    memset(used, 0, sizeof(used));
    int col = 0;
    for (int v : order) {
        if (!used[v]) {
            ++col;
            dfs2(v, col);
        }
    }
    memset(res, -1, sizeof(res));
    /*for (int i = 0; i < n; ++i) {
        cout << used[i];
    }
    cout << endl;*/
    for (int i = 0; i < n; ++i) {
        comp[used[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        if (res[used[i]] == -1) {
            res[used[i]] = solve(i);
            //cout << i << ": " << res[used[i]] << endl;
        }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int v, s, t;
        scanf("%d%d%d", &v, &s, &t);
        --v;
        long long g = res[used[v]];
        if (can_zero(s, t, g)) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}