#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, mx, f[2], used[max_n];
vector<int> g[max_n];

void dfs(int v, int p, int col) {
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v, col ^ 1);
        }
    }
    if (g[v].size() == 1) {
        f[col] = 1;
        if (used[p]) {
            --mx;
        }
        used[p] = 1;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int root;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() != 1) {
            root = i;
            break;
        }
    }
    mx = n - 1;
    dfs(root, -1, 0);
    int mn = 1;
    if (f[0] && f[1]) {
        mn = 3;
    }
    printf("%d %d\n", mn, mx);
    return 0;
}