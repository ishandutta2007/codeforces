#include <bits/stdc++.h>

using namespace std;

const int max_n = 71, inf = 1000111222;
const int max_c = 17;

int n, m, a, b, d[max_n][max_n], ans[max_n], dist[max_n][max_n];
int num, comp[max_n], sz[max_n], p[max_n], rp[max_n], dp[1 << max_c][max_n];
vector<int> g[2][max_n], all[max_n];

void bfs(int v, int d[]) {
    for (int i = 0; i < n; ++i) {
        d[i] = inf;
    }
    queue<int> q;
    q.push(v);
    d[v] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[0][v]) {
            if (d[to] == inf) {
                d[to] = d[v] + a;
                q.push(to);
            }
        }
    }
}

void dfs(int v) {
    comp[v] = num;
    ++sz[num];
    for (int to : g[0][v]) {
        if (comp[to] == -1) {
            dfs(to);
        }
    }
}

bool cmp(int c1, int c2) {
    return sz[c1] > sz[c2];
}

int comps;

int comp_mask(int comp) {
    if (comp < comps) {
        return 1 << comp;
    }
    return 0;
}

bool get_bit(int mask, int pos) {
    return (bool) (mask & (1 << pos));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> a >> b;
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        --u;
        --v;
        int tp = 1;
        if (d == a) {
            tp = 0;
        }
        g[tp][u].push_back(v);
        g[tp][v].push_back(u);
    }
    memset(comp, -1, sizeof(comp));
    for (int i = 0; i < n; ++i) {
        bfs(i, d[i]);
        ans[i] = inf;
        if (comp[i] == -1) {
            dfs(i);
            ++num;
        }
    }
    for (int i = 0; i < num; ++i) {
        p[i] = i;
    }
    sort(p, p + num, cmp);
    for (int i = 0; i < num; ++i) {
        rp[p[i]] = i;
        if (sz[i] > 3) {
            ++comps;
        }
    }
    for (int i = 0; i < n; ++i) {
        comp[i] = rp[comp[i]];
        //cout << i << " " << comp[i] << " " << comps << endl;
    }
    for (int a = 0; a < n; ++a) {
        const int cost = b;
        for (int b = 0; b < n; ++b) {
            dist[a][b] = inf;
            if (comp[a] != comp[b]) {
                for (int c = 0; c < n; ++c) {
                    if (comp[a] == comp[c]) {
                        for (int to : g[1][c]) {
                            if (comp[b] == comp[to]) {
                                dist[a][b] = min(dist[a][b], d[a][c] + cost + d[to][b]);
                            }
                        }
                    }
                }
                if (dist[a][b] != inf) {
                    all[a].push_back(b);
                    //cout << a << " -> " << b << endl;
                }
            }
        }
    }
    for (int mask = 0; mask < (1 << comps); ++mask) {
        for (int last = 0; last < n; ++last) {
            dp[mask][last] = inf;
        }
    }
    dp[comp_mask(comp[0])][0] = 0;
    for (int i = 0; i < n; ++i) {
        if (comp[i] == comp[0]) {
            ans[i] = d[0][i];
        }
    }
    for (int mask = 0; mask < (1 << comps); ++mask) {
        for (int it = 0; it < n; ++it) {
            bool change = false;
            for (int last = 0; last < n; ++last) {
                if (dp[mask][last] == inf) {
                    continue;
                }
                //cout << mask << " " << last << ": " << dp[mask][last] << endl;
                ans[last] = min(ans[last], dp[mask][last]);
                for (int to : all[last]) {
                    if (comp[to] >= comps || !get_bit(mask, comp[to])) {
                        if (dp[mask | comp_mask(comp[to])][to] > dp[mask][last] + dist[last][to]) {
                            dp[mask | comp_mask(comp[to])][to] = dp[mask][last] + dist[last][to];
                            if (comp[to] >= comps) {
                                change = true;
                            }
                        }
                    }
                }
            }
            if (!change) {
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i]);
    }
    puts("");
    return 0;
}