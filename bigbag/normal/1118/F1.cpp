#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int n, ans, a[max_n], cnt[3][max_n];
vector<int> g[max_n];

void dfs(int v, int p) {
    cnt[a[v]][v] = 1;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
        cnt[0][v] += cnt[0][to];
        cnt[1][v] += cnt[1][to];
        cnt[2][v] += cnt[2][to];
    }
}

void solve(int v, int p) {
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        solve(to, v);
        int x = cnt[1][to], y = cnt[2][to];
        int q = cnt[1][1] - x, w = cnt[2][1] - y;
        // cout << v << " -> " << to << ": " << x << " " << y << ", " << q << " " << w << endl;
        if (1LL * x * y == 0 && 1LL * q * w == 0) {
            ++ans;
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
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    solve(1, -1);
    printf("%d\n", ans);
    return 0;
}