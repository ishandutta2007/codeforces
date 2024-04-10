#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, k, sz[max_n], h[max_n];
vector<int> g[max_n];

int get_root() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 1) {
            q.push(i);
        }
        sz[i] = g[i].size();
    }
    int root = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        root = v;
        for (int to : g[v]) {
            --sz[to];
            if (sz[to] == 1) {
                q.push(to);
            }
        }
    }
    return root;
}

void dfs(int v, int p) {
    int cnt = 0;
    for (int to : g[v]) {
        if (to != p) {
            ++cnt;
            h[to] = h[v] + 1;
            dfs(to, v);
        }
    }
    if (cnt != 0 && cnt < 3) {
        puts("No");
        exit(0);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    if (n == 1) {
        puts("No");
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int root = get_root();
    dfs(root, -1);
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 1 && h[i] != k) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}