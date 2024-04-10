#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, m, a, b, used[max_n];
vector<int> g[max_n];

void clr() {
    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }
}

int cnt;

void dfs(int v, int bad) {
    used[v] = 1;
    ++cnt;
    for (int to : g[v]) {
        if (to == bad || used[to]) {
            continue;
        }
        dfs(to, bad);
    }
}

int solve(int a, int b) {
    for (int i = 0; i < n; ++i) {
        used[i] = 0;
    }
    cnt = 0;
    dfs(a, b);
    return n - cnt - 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d", &n, &m, &a, &b);
        --a;
        --b;
        while (m--) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u;
            --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        long long x = solve(a, b);
        long long y = solve(b, a);
        printf("%I64d\n", x * y);
        clr();
    }
    return 0;
}