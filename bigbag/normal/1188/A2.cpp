#include <bits/stdc++.h>

using namespace std;

const int max_n = 100011, inf = 1000111222;

int n, leaf[max_n];
vector<int> g[max_n], val[max_n], num[max_n], ans_u, ans_v, ans_x;

void dfs1(int v, int p = -1) {
    leaf[v] = v;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs1(to, v);
        leaf[v] = leaf[to];
    }
}

bool add(int v, int v2, int x, int p = -1) {
    if (v == v2) {
        return true;
    }
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] == p) {
            continue;
        }
        if (add(g[v][i], v2, x, v)) {
            val[v][i] -= x;
            val[g[v][i]][num[v][i]] -= x;
            return true;
        }
    }
    return false;
}

void add_edge(int v, int v2, int x) {
    ans_u.push_back(v);
    ans_v.push_back(v2);
    ans_x.push_back(x);
    add(v, v2, x);
}

void dfs(int v, int p = -1) {
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] == p) {
            continue;
        }
        if (val[v][i]) {
            int v1 = g[v][0];
            int v2 = g[v][1];
            if (v1 == g[v][i]) {
                v1 = g[v][2];
            } else if (v2 == g[v][i]) {
                v2 = g[v][2];
            }
            if (v1 == p) {
                if (g[v1][0] != v) {
                    v1 = g[v1][0];
                } else {
                    v1 = g[v1][1];
                }
                v1 = leaf[v1];
            }
            if (v2 == p) {
                if (g[v2][0] != v) {
                    v2 = g[v2][0];
                } else {
                    v2 = g[v2][1];
                }
                v2 = leaf[v2];
            }
            v1 = leaf[v1];
            v2 = leaf[v2];
            int x = val[v][i];
            add_edge(leaf[g[v][i]], v1, x / 2);
            add_edge(leaf[g[v][i]], v2, x / 2);
            add_edge(v1, v2, -x / 2);
        }
    }
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] == p) {
            continue;
        }
        dfs(g[v][i], v);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v, x;
        scanf("%d%d%d", &u, &v, &x);
        num[u].push_back(g[v].size());
        num[v].push_back(g[u].size());
        g[u].push_back(v);
        g[v].push_back(u);
        val[u].push_back(x);
        val[v].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 2) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    if (n == 2) {
        puts("1");
        printf("1 2 %d\n", val[1][0]);
        return 0;
    }
    int root;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() != 1) {
            root = i;
            break;
        }
    }
    dfs1(root);
    dfs(root);
    printf("%d\n", ans_u.size());
    for (int i = 0; i < ans_u.size(); ++i) {
        printf("%d %d %d\n", ans_u[i], ans_v[i], ans_x[i]);
    }
    return 0;
}