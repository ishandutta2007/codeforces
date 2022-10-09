#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 101010;
const int maxk = 555;

using DP = vector<ll>;

int n, k;
vector<int> gr[maxn];
ll total_ans;
ll dp[maxn][maxk];

void dfs(int u, int p) {
    dp[u][0] = 1;
    for (auto v: gr[u]) {
        if (v == p) continue;
        dfs(v, u);
        for (int i = 0; i < k; ++i) {
            int x = k - i - 1;
            total_ans += dp[u][i] * dp[v][x];
        }
        for (int i = 0; i < k; ++i) {
            dp[u][i + 1] += dp[v][i];
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    dfs(1, 1);
    cout << total_ans;
    return 0;
}