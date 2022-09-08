#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, m, a[max_n], u[max_n], vv[max_n], used[max_n], ans[max_n], sum[max_n];
vector<int> g[max_n];

void dfs(int v) {
    used[v] = 1;
    sum[v] = a[v];
    for (int num : g[v]) {
        int to = (v ^ u[num] ^ vv[num]);
        if (used[to] == 0) {
            dfs(to);
            sum[v] += sum[to];
            int x = sum[to];
            if (v != u[num]) {
                x *= -1;
            }
            ans[num] = x;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u[i], &vv[i]);
        g[u[i]].push_back(i);
        g[vv[i]].push_back(i);
    }
    dfs(1);
    if (sum[1] != 0) {
        puts("Impossible");
        return 0;
    }
    puts("Possible");
    for (int i = 0; i < m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}