#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, cnt[2];
vector<int> g[max_n];

void dfs(int v, int p, int col) {
    ++cnt[col];
    for (int to : g[v]) {
        if (p != to) {
            dfs(to, v, col ^ 1);
        }
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
    dfs(0, -1, 0);
    printf("%d\n", min(cnt[0], cnt[1]) - 1);
    return 0;
}