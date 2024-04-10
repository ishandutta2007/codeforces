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

const int max_n = 333333, inf = 1111111111;

int n, m, st, fin, used[max_n], ff[max_n];
set<pair<int, int> > q;
vector<int> g[max_n], g2[max_n], g3[max_n], g4[max_n], f[max_n], f4[max_n], a;

void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (!q.count(make_pair(g[v][i], v))) {
            q.insert(make_pair(v, g[v][i]));
            g2[v].push_back(g[v][i]);
            g3[g[v][i]].push_back(v);
        }
        if (used[g[v][i]] == 0) {
            dfs(g[v][i]);
        }
    }
}

void dfs2(int v) {
    used[v] = 1;
    for (int i = 0; i < g2[v].size(); ++i) {
        if (used[g2[v][i]] == 0) {
            dfs2(g2[v][i]);
        }
    }
    a.push_back(v);
}

void dfs3(int v, int c) {
    used[v] = c;
    //cout << v << " col = " << c << endl;
    for (int i = 0; i < g3[v].size(); ++i) {
        if (used[g3[v][i]] == 0) {
            dfs3(g3[v][i], c);
        }
    }
}

void dfs4(int v, int p, int fin, int res) {
    res |= ff[v];
    if (v == fin) {
        if (res) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        exit(0);
    }
    for (int i = 0; i < g4[v].size(); ++i) {
        if (g4[v][i] != p) {
            dfs4(g4[v][i], v, fin, res | f4[v][i]);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v, x;
        scanf("%d%d%d", &u, &v, &x);
        g[u].push_back(v);
        g[v].push_back(u);
        f[u].push_back(x);
        f[v].push_back(x);
    }
    dfs(1);
    memset(used, 0, sizeof(used));
    dfs2(1);
    reverse(a.begin(), a.end());
    memset(used, 0, sizeof(used));
    int c = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (used[a[i]] == 0) {
            ++c;
            dfs3(a[i], c);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            int a = used[i];
            int b = used[g[i][j]];
            if (a != b) {
                g4[a].push_back(b);
                f4[a].push_back(f[i][j]);
            } else {
                ff[a] |= f[i][j];
            }
        }
    }
    int st, fin;
    scanf("%d%d", &st, &fin);
    dfs4(used[st], -1, used[fin], 0);
    return 0;
}