#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n;
vector<int> g[max_n], ans;

void dfs(int v, int p) {
    bool was = false;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
            was = true;
        }
    }
    if (!was) {
        ans.push_back(v);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += (g[i].size() > 2);
    }
    if (cnt > 1) {
        puts("No\n");
        return 0;
    }
    int root = 1;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() > 2) {
            root = i;
            break;
        }
    }
    dfs(root, -1);
    printf("Yes\n%d\n", ans.size());
    for (int x : ans) {
        printf("%d %d\n", root, x);
    }
    return 0;
}