/**
 *  created: 24/12/2021, 17:56:54
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222;
const long long inf = 1000111222000111222LL;

int n, k;
vector<int> g[max_n];
multiset<int> dp[max_n];

void get_dp(int v, int p) {
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        get_dp(to, v);
        if (dp[v].size() < dp[to].size()) {
            dp[v].swap(dp[to]);
        }
        dp[v].insert(dp[to].begin(), dp[to].end());
    }
    dp[v].insert(0);
    int x = *dp[v].begin();
    dp[v].erase(dp[v].begin());
    dp[v].insert(x - 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (0) {
        for (int n = 2; n < 111; ++n) {
            for (int r = 0; r <= n; ++r) {
                for (int mx = 0; mx <= n - r; ++mx) {
                    long long b = min(n / 2, mx);
                    long long res = 1LL * (n - r - b) * (r - b);
                    long long tr = inf;
                    for (int b = 0; b <= mx; ++b) {
                        tr = min(tr, 1LL * (n - r - b) * (r - b));
                    }
                    assert(res == tr);
                }
            }
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    get_dp(0, -1);
    vector<int> all(dp[0].rbegin(), dp[0].rend());
    vector<int> v;
    {
        int x = 0;
        v.push_back(x);
        for (int add : all) {
            x -= add;
            v.push_back(x);
        }
        reverse(v.begin(), v.end());
    }
    long long ans = -inf;
    for (int i = 0; i <= k; ++i) {
        long long b = min(n / 2, v[i]);
        long long res = 1LL * (n - i - b) * (i - b);
        //cout << i << " " << b << ": " << res << endl;
        ans = max(ans, res);
    }
    cout << ans << "\n";
    return 0;
}