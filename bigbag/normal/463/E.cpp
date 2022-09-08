#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 100001, inf = 1111111111;
const int max_p = 1416;

int used[2000002], op[2000002], num[2222], sqr[255];
vector<long long> p;

void get_all_primes() {
    for (int i = 2; i < max_p; ++i) {
        if (used[i] == 0) {
            p.push_back(i);
            num[i] = p.size() - 1;
            sqr[p.size() - 1] = p.back() * p.back();
            for (int j = i * i; j < max_p; j += i) {
                used[j] = 1;
            }
        }
    }
}

int n, q, a[max_n], aa[max_n], f[max_n][223], f1[max_n], dist[max_n];
vector<int> g[max_n];

void dfs(int v, int len, int par) {
    aa[v] = op[a[v]];
    if (used[aa[v]]) {
        f1[v] = used[aa[v]];
    }
    int ku = used[aa[v]];
    used[aa[v]] = v;
    dist[v] = len;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != par) {
            for (int j = 0; j < p.size(); ++j) {
                if (a[v] % p[j] == 0) {
                    f[g[v][i]][j] = v;
                } else {
                    f[g[v][i]][j] = f[v][j];
                }
            }
            dfs(g[v][i], len + 1, v);
        }
    }
    used[aa[v]] = ku;
}

void build() {
    memset(f, 0, sizeof(f));
    memset(f1, 0, sizeof(f1));
    memset(used, 0, sizeof(used));
    dfs(1, 1, -1);
}

void dfs2(int v, int par, int nv, int value, bool ok) {
    if (v == nv) {
        ok = true;
        a[v] = value;
    }
    aa[v] = op[a[v]];
    if (used[aa[v]]) {
        f1[v] = used[aa[v]];
    }
    int ku = used[aa[v]];
    used[aa[v]] = v;
    if (ok) {
        for (int i = 0; i < g[v].size(); ++i) {
            if (g[v][i] != par) {
                for (int j = 0; j < p.size(); ++j) {
                    if (a[v] % p[j] == 0) {
                        f[g[v][i]][j] = v;
                    } else {
                        f[g[v][i]][j] = f[v][j];
                    }
                }
                dfs2(g[v][i], v, nv, value, ok);
            }
        }
    } else {
        for (int i = 0; i < g[v].size(); ++i) {
            if (g[v][i] != par) {
                dfs2(g[v][i], v, nv, value, ok);
            }
        }
    }
    used[aa[v]] = ku;
}

void rebuild(int v, int value) {
    memset(f1, 0, sizeof(f1));
    memset(used, 0, sizeof(used));
    dfs2(1, -1, v, value, false);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_primes();
    for (int i = 1; i <= 2000000; ++i) {
        op[i] = i;
        for (int j = 0; j < p.size() && op[i] > 1; ++j) {
            while (op[i] % p[j] == 0) {
                op[i] /= p[j];
            }
        }
    }
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    build();
    while (q--) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int v;
            scanf("%d", &v);
            int ans = -1, poz = -1;
            for (int i = 0; i < p.size(); ++i) {
                if (a[v] % p[i] == 0 && f[v][i]) {
                    if (poz < dist[f[v][i]]) {
                        poz = dist[f[v][i]];
                        ans = f[v][i];
                    }
                }
            }
            if (aa[v] > 1 && f1[v]) {
                if (poz < dist[f1[v]]) {
                    ans = f1[v];
                }
            }
            printf("%d\n", ans);
        } else {
            int v, value;
            scanf("%d%d", &v, &value);
            rebuild(v, value);
        }
    }
    return 0;
}