#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int n, x, y, nums[max_n], sz[max_n];
vector<int> g[max_n];
long long ans;

void dfs(int v, int num, int p) {
    nums[v] = num;
    sz[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p) {
            int to_num = num;
            if (p == -1) {
                to_num = i;
            }
            dfs(to, to_num, v);
            sz[v] += sz[to];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(x, -1, -1);
    ans = 1LL * n * (n - 1);
    ans -= 1LL * (n - sz[g[x][nums[y]]]) * (sz[y]);
    printf("%I64d\n", ans);
    return 0;
}