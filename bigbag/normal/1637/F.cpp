/**
 *  created: 12/02/2022, 17:38:42
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222;
const long long inf = 1000111222000111222LL;

int n, a[max_n], mx[max_n];
vector<int> g[max_n];
multiset<int> mxs[max_n];
long long dp[max_n];
long long ans = inf;

int get_max(int v) {
    if (mxs[v].empty()) {
        return 0;
    }
    return *mxs[v].rbegin();
}

void dfs(int v, int p) {
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
    }
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dp[v] += dp[to];
        mxs[v].insert(mx[to]);
    }
    dp[v] += max(0, a[v] - get_max(v));
    mx[v] = max(get_max(v), a[v]);
}

void proc(int v, int p) {
    ans = min(ans, dp[v]);
    //cout << v << ": " << dp[v] << endl;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        const long long mx_to = mx[to], dp_old = dp[v], mx_old = mx[v];
        dp[v] -= max(0, a[v] - get_max(v));
        mxs[v].erase(mxs[v].find(mx_to));
        dp[v] += max(0, a[v] - get_max(v));
        dp[v] -= dp[to];
        mx[v] = max(get_max(v), a[v]);

        dp[to] += dp[v];
        dp[to] -= max(0, a[to] - get_max(to));
        mxs[to].insert(mx[v]);
        dp[to] += max(0, a[to] - get_max(to));
        mx[to] = max(get_max(to), a[to]);

        proc(to, v);

        dp[v] = dp_old;
        mx[v] = mx_old;
        mxs[v].insert(mx_to);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    proc(0, -1);
    cout << ans + *max_element(a, a + n) << "\n";
    return 0;
}