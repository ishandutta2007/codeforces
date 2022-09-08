#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, a, b, da, db, h[max_n];
vector<int> g[max_n];

void clr() {
    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }
}

void dfs(int v, int p) {
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        h[to] = h[v] + 1;
        dfs(to, v);
    }
}

bool solve() {
    h[a] = 0;
    dfs(a, -1);
    if (h[b] <= da) {
        return true;
    }
    int root = 0;
    for (int i = 0; i < n; ++i) {
        if (h[i] > h[root]) {
            root = i;
        }
    }
    h[root] = 0;
    dfs(root, -1);
    const int d = *max_element(h, h + n);
    return 2 * da >= min(d, db);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
        --a;
        --b;
        for (int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u;
            --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if (solve()) {
            puts("Alice");
        } else {
            puts("Bob");
        }
        clr();
    }
    return 0;
}