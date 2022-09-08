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

const int max_n = 111, max_k = 25, mod = 1000000007;

int n, k, dp[max_n][2][max_k][max_k], res[max_n];
vector<int> g[max_n];

void dfs(int v, int p) {
    //vector<int> all;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            dfs(g[v][i], v);
            //all.push_back(g[v][i]);
        }
    }
    //g[v] = all;
    int q1 = 0, q2 = 1;
    for (int i = 1; i < max_k; ++i) {
        dp[v][q1][i][max_k - 1] = 1;
        //dp[v][q1][i][0] = 1;
    }
    dp[v][q1][max_k - 1][max_k - 1] = 1;
    dp[v][q1][0][0] = 1;
    //dp[v][q1][max_k - 1][max_k - 1] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] == p) {
            continue;
        }
        memset(dp[v][q2], 0, sizeof(dp[v][q2]));
        for (int last = 0; last < max_k; ++last) {
            for (int mn = 0; mn < max_k; ++mn) {
                for (int d = 0; d < max_k; ++d) {
                    int nlast = min(mn + 1, last + 1);
                    if (nlast > k) {
                        nlast = max_k - 1;
                    }
                    if (d == 0) {
                        nlast = 0;
                    }
                    /*if (last == 0 && mn == 0 && d == 0) {
                        cout << dp[v][q1][last][mn] << "   " << nlast << " " << d << endl;
                        cout << dp[g[v][i]][res[g[v][i]]][nlast][d] << endl;
                    }*/
                    dp[v][q2][last][min(mn, d + 1)] += (1LL * dp[v][q1][min(d + 1, last)][mn] * dp[g[v][i]][res[g[v][i]]][nlast][d]) % mod;
                    dp[v][q2][last][min(mn, d + 1)] %= mod;
                }
            }
        }
        swap(q1, q2);
    }
    res[v] = q1;
    for (int last = 0; last < max_k; ++last) {
        for (int mn = 0; mn < max_k; ++mn) {
            if (last > k && mn > k) {
                dp[v][res[v]][last][mn] = 0;
            }
        }
    }
}

void solve() {

}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    int ans = (dp[1][res[1]][0][0]) % mod;
    for (int i = 0; i <= k; ++i) {
        //break;
        ans += dp[1][res[1]][max_k - 1][i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}