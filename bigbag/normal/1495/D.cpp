/**
 *  created: 10/03/2021, 15:40:56
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 444, max_m = 666, mod = 998244353, inf = 1000111222;

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int n, m, from[max_m], to[max_m];
int dist[max_n][max_n], res[max_n][max_n], tot[max_n];
vector<int> g[max_n];

bool used[max_n], taken[max_n];
int par[max_n];

bool dfs(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = 1;
    for (int to : g[v]) {
        if (par[to] == -1) {
            par[to] = v;
            return true;
        }
    }
    for (int to : g[v]) {
        if (dfs(par[to])) {
            par[to] = v;
            return true;
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = inf;
        }
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &from[i], &to[i]);
        --from[i];
        --to[i];
        dist[from[i]][to[i]] = 1;
        dist[to[i]][from[i]] = 1;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int s = 0; s < n; ++s) {
        for (int t = s; t < n; ++t) {
            //if (s != 0 || t != 2) continue;
            memset(tot, 0, sizeof(tot));
            for (int i = 0; i < n; ++i) {
                g[i].clear();
            }

            for (int i = 0; i < m; ++i) {
                if (abs(dist[s][from[i]] - dist[s][to[i]]) != 1 || abs(dist[t][from[i]] - dist[t][to[i]]) != 1) {
                    continue;
                }
                int v1 = from[i], v2 = from[i];
                if (dist[s][from[i]] < dist[s][to[i]]) {
                    v1 = to[i];
                }
                if (dist[t][from[i]] < dist[t][to[i]]) {
                    v2 = to[i];
                }
                //cout << v1 << " -> " << v2 << endl;
                if (v1 == v2) {
                    ++tot[v1];
                }
            }


            for (int i = 0; i < m; ++i) {
                if (abs(dist[s][from[i]] - dist[s][to[i]]) != 1 || abs(dist[t][from[i]] - dist[t][to[i]]) != 1) {
                    continue;
                }
                int v1 = from[i], v2 = from[i];
                if (dist[s][from[i]] < dist[s][to[i]]) {
                    v1 = to[i];
                }
                if (dist[t][from[i]] < dist[t][to[i]]) {
                    v2 = to[i];
                }
                //cout << v1 << " -> " << v2 << endl;
                if (v1 != v2 && !tot[v1] && !tot[v2]) {
                    g[v1].push_back(v2);
                }
            }


            int ans = 1, sz = 0;
            memset(par, -1, sizeof(par));
            memset(taken, 0, sizeof(taken));
            for (int i = 0; i < n; ++i) {
                if (!taken[i] && i != s && !tot[i]) {
                    for (int to : g[i]) {
                        if (par[to] == -1) {
                            par[to] = i;
                            taken[i] = 1;
                            ++sz;
                            break;
                        }
                    }
                }
            }
            for (int ok = 1; ok; ) {
                ok = 0;
                memset(used, 0, sizeof(used));
                for (int i = 0; i < n; ++i) {
                    if (!taken[i] && i != s && !tot[i] && dfs(i)) {
                        ok = 1;
                        taken[i] = 1;
                        ++sz;
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                if (tot[i]) {
                    ans = mul(ans, tot[i]);
                    ++sz;
                }
            }
            //cout << "#" << sz << endl;
            if (sz != n - 1) {
                assert(sz < n - 1);
                ans = 0;
            }
            res[s][t] = res[t][s] = ans;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", res[i][j]);
        }
        puts("");
    }
    return 0;
}