/**********
*         *
*  HELLO  *
*         *
**********/

#include <bits/stdc++.h>

using namespace std;

const int mx = 2000;
int n, m, wmax, w[mx], b[mx], kk, kw[mx], kb[mx], dp[mx][mx];
bool used[mx];
vector<int> g[mx], kbb[mx], kww[mx];

int dfs(int v) {
    used[v] = 1;
    kw[kk] += w[v];
    kb[kk] += b[v];
    kww[kk].push_back(w[v]);
    kbb[kk].push_back(b[v]);
    int v1 = 0;
    for (int i = 0; i < g[v].size(); i++) {
        v1 = g[v][i];
        if (used[v1] == 0) {
            dfs(v1);
        }
    }
}

int main()
{
    cin >> n >> m >> wmax;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        g[i].clear();
        kbb[i].clear();
        kww[i].clear();
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int u, v;
    for (int i = 0; i < m; ++i){
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    kk = 0;
    for (int i = 0; i < n; ++i) {
        kw[kk] = 0;
        kb[kk] = 0;
        if (used[i] == 0) {
            dfs(i);
            kk++;
        }
    }
    for (int i = 0; i <= wmax; ++i) {
        dp[i][0] = 0;
        for (int a = 0; a < kbb[0].size(); ++a) {
            if (kww[0][a] <= i) dp[i][0] = max(dp[i][0], kbb[0][a]);
        }
        if (kw[0] <= i) dp[i][0] = max(dp[i][0], kb[0]);
        for (int j = 1; j < kk; ++j) {
            dp[i][j] = dp[i][j - 1];
            for (int a = 0; a < kbb[j].size(); ++a) {
                if (kww[j][a] <= i) dp[i][j] = max(dp[i][j], kbb[j][a] + dp[i - kww[j][a]][j - 1]);
            }
            if (kw[j] <= i) dp[i][j] = max(dp[i][j], kb[j] + dp[i - kw[j]][j - 1]);
        }
    }
    cout << dp[wmax][kk - 1];
    return 0;
}