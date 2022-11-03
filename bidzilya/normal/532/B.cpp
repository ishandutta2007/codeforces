#include <bits/stdc++.h>
using namespace std;

const long long kNotSet = -1;
const long long kNotExist = -2;

int n;
vector<vector<int> > g;
vector<long long> a;
vector<long long> dp[2];

long long Calc(int v, int gc)
{
    if (dp[gc][v] != kNotSet) {
        return dp[gc][v];
    }
    long long& ans = dp[gc][v];
    ans = kNotExist;
    int m = g[v].size();
    long long max_val[2][2];
    int cur = 0;
    max_val[0][cur] = 0;
    max_val[1][cur] = kNotExist;
    for (int i = 0; i < m; ++i) {
        int nxt = 1 - cur;
        int u = g[v][i];
        max_val[0][nxt] = max_val[0][cur];
        max_val[1][nxt] = max_val[1][cur];
        for (int c = 0; c < 2; ++c) {
            for (int lc = 0; lc < 2; ++lc) {
                int nc = (c + lc) & 1;
                if (Calc(u, c) != kNotExist && max_val[lc][cur] != kNotExist) {
                    max_val[nc][nxt] = max(max_val[nc][nxt], max_val[lc][cur] + Calc(u, c));
                }
            }
        }
        swap(nxt, cur);
    }
    if (max_val[gc][cur] != kNotExist) {
        ans = max(ans, max_val[gc][cur]);
    }
    if (gc == 1 && max_val[0][cur] != kNotExist) {
        ans = max(ans, max_val[0][cur] + a[v]);
    }
    // cout << "(" << v << ", " << gc << ") = " << ans << endl;
    return ans;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    g.resize(n);
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p >> a[i];
        if (p != -1) {
            --p;
            g[p].push_back(i);
        }
    }
    for (int c = 0; c < 2; ++c) {
        dp[c].resize(n);
    }
    for (int i = 0; i < n; ++i) {
        for (int c = 0; c < 2; ++c) {
            dp[c][i] = kNotSet;
        }
    }
    cout << max(Calc(0, 0), Calc(0, 1)) << endl;
    
    return 0;
}