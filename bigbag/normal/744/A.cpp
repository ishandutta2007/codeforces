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

const int max_n = 1111, inf = 1011111111;

int n, m, k, ok, sz, sum, f[max_n], num[max_n], used[max_n];
vector<int> g[max_n], all;

void dfs(int v) {
    used[v] = 1;
    ++sz;
    if (f[v]) {
        ok = 1;
    }
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            dfs(g[v][i]);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &num[i]);
        f[num[i]] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            ok = 0;
            sz = 0;
            dfs(i);
            if (ok) {
                all.push_back(sz);
            } else {
                sum += sz;
            }
        }
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    all[0] += sum;
    int ans = 0;
    for (int i = 0; i < all.size(); ++i) {
        ans += (all[i] * (all[i] - 1)) / 2;
    }
    printf("%d\n", ans - m);
    return 0;
}