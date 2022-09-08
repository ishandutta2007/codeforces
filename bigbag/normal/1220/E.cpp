#include <bits/stdc++.h>

using namespace std;

const int max_n = 200111, inf = 1000111222;

int n, m, a[max_n], used[max_n];
int up[max_n], h[max_n], l[max_n], r[max_n], cur;
long long dp[max_n], S[max_n];
vector<int> g[max_n], gt[max_n], order;
vector<long long> sum[max_n];

void dfs(int v, int p) {
    used[v] = 1;
    up[v] = h[v];
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        if (!used[to]) {
            h[to] = h[v] + 1;
            gt[v].push_back(to);
            //cout << v + 1 << " -> " << to + 1 << endl;
            dfs(to, v);
            if (up[to] <= h[v]) {
                up[v] = 0;
            }
        } else {
            //cout << "up " << v + 1 << " -> " << to + 1 << endl;
            //up[v] = min(up[v], h[to]);
            up[v] = 0;
        }
    }
}

void dfs2(int v) {
    l[v] = order.size();
    order.push_back(v);
    for (int to : gt[v]) {
        dfs2(to);
    }
    r[v] = order.size();
}

void calc_dp(int v) {
    S[v] = 0;
    if (up[v] == 0) {
        S[v] = a[v];
    }
    for (int to : gt[v]) {
        calc_dp(to);
        S[v] += S[to];
    }
    for (int to : gt[v]) {
        /*long long x = 0;
        for (int i = l[to]; i < r[to]; ++i) {
            if (up[order[i]] <= h[v]) {
                x += a[order[i]];
            }
        }*/
        sum[v].push_back(S[to]);
    }
    long long best = 0;
    dp[v] = a[v];
    for (int i = 0; i < gt[v].size(); ++i) {
        dp[v] += sum[v][i];
        best = max(best, dp[gt[v][i]] - sum[v][i]);
    }
    dp[v] += best;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int root;
    scanf("%d", &root);
    --root;
    dfs(root, -1);
    dfs2(root);
    calc_dp(root);
    printf("%I64d\n", dp[root]);
    return 0;
}