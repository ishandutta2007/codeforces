/**
 *  created: 13/06/2021, 18:47:29
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 400444, mod = 1000000007;

int t, n, a[2][max_n], pos[2][max_n], used[max_n], sz;
vector<int> g[max_n];

void dfs(int v) {
    used[v] = 1;
    ++sz;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &a[i][j]);
                --a[i][j];
                pos[i][a[i][j]] = j;
            }
        }
        for (int i = 0; i < n; ++i) {
            used[i] = 0;
            g[i].clear();
            g[i].push_back(pos[0][a[1][i]]);
            g[i].push_back(pos[1][a[0][i]]);
        }
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                sz = 0;
                dfs(i);
                if (sz > 1) {
                    ans = 2LL * ans % mod;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}