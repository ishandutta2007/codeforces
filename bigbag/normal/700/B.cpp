#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 222222, inf = 1111111111;

int n, k, f[max_n], len[max_n], sz[max_n];
long long ans;
vector<int> g[max_n];

void dfs(int v, int p) {
    sz[v] = f[v];
    if (f[v]) {
        ans += len[v];
    }
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            len[g[v][i]] = len[v] + 1;
            dfs(g[v][i], v);
            sz[v] += sz[g[v][i]];
        }
    }
}

void dfs2(int v, int p, int cnt) {
    int sum = sz[v] - cnt, mx = 0;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            mx = max(mx, sz[g[v][i]] - cnt);
        }
    }
    sum -= mx;
    if (sum >= mx) {
        ans -= 1LL * len[v] * (sz[v] - cnt);
    } else {
        ans -= 2LL * len[v] * sum;
        for (int i = 0; i < g[v].size(); ++i) {
            if (g[v][i] != p && mx == sz[g[v][i]] - cnt) {
                dfs2(g[v][i], v, cnt + sum);
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= 2 * k; ++i) {
        int v;
        scanf("%d", &v);
        f[v] = 1;
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    //cout << "$" << ans << endl;
    dfs2(1, -1, 0);
    printf("%I64d\n", ans);
    return 0;
}