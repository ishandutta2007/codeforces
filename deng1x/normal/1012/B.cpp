#include <bits/stdc++.h>

const int MAXN = 200010;

int n, m, q;
int vis[MAXN << 1];
std::vector<int> vec[MAXN << 1];

void dfs(int u) {
    vis[u] = true;
    for (auto v : vec[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    while (q--) {
        int u, v;
        scanf("%d%d", &u, &v);
        vec[u].push_back(v + n);
        vec[v + n].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n + m; ++i) {
        if (!vis[i]) {
            ++ans;
            dfs(i);
        }
    }
    printf("%d\n", ans - 1);
    return 0;
}