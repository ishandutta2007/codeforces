#include <bits/stdc++.h>
using namespace std;

const int M = 19999;
const int N = 2200;

#define next asdf

int dp[N][M];
vector<int> suf[M];
int next[M][10], go[M][10], q[M], par[M], dep[M];
int cnt[N][M];
bool chk[N][M];

int main() {
    string L, R; int n; cin >> L >> R >> n;
    int m = 1;
    if (L.length() != R.length()) {
        {
            int u = 1;
            for (int i = 0; i < L.length(); i++) {
                for (int j = L[i] - '0' + 1; j <= 9; j++) {
                    int &v = next[u][j];
                    if (!v) v = ++m;
                    suf[v].push_back(L.length() - i - 1);
                }
                {
                    int &v = next[u][L[i] - '0'];
                    if (!v) v = ++m;
                    u = v;
                }
            }
            suf[u].push_back(0);
        }
        {
            int u = 1;
            for (int i = 0; i < R.length(); i++) {
                for (int j = R[i] - '0' - 1; j >= 0; j--) {
                    if (i == 0 && j == 0) continue;
                    int &v = next[u][j];
                    if (!v) v = ++m;
                    suf[v].push_back(R.length() - i - 1);
                }
                {
                    int &v = next[u][R[i] - '0'];
                    if (!v) v = ++m;
                    u = v;
                }
            }
            suf[u].push_back(0);
        }
        for (int i = L.length()+1; i < R.length(); i++) {
            int u = 1;
            for (int j = 1; j <= 9; j++) {
                int &v = next[u][j];
                if (!v) v = ++m;
                suf[v].push_back(i - 1);
            }
        }
    } else {
        int l = 1, r = 1;
        for (int i = 0; i < L.length(); i++) {
            if (l == r) {
                for (int j = L[i] - '0' + 1; j < R[i] - '0'; j++) {
                    int &v = next[l][j];
                    if (!v) v = ++m;
                    suf[v].push_back(L.length() - i - 1);
//                    cerr << "ok" << endl;
                }
            } else {
                for (int j = L[i] - '0' + 1; j <= 9; j++) {
                    int &v = next[l][j];
                    if (!v) v = ++m;
                    suf[v].push_back(L.length() - i - 1);
//                    cerr << "ok1" << endl;
                }
                for (int j = R[i] - '0' - 1; j >= 0; j--) {
                    int &v = next[r][j];
                    if (!v) v = ++m;
                    suf[v].push_back(L.length() - i - 1);
//                    cerr << "ok2" << endl;
                }
            }
            {
                int &v = next[l][L[i] - '0'];
                if (!v) v = ++m;
                l = v;
            }
            {
                int &v = next[r][R[i] - '0'];
                if (!v) v = ++m;
                r = v;
            }
        }
        suf[l].push_back(0);
        if (l != r) suf[r].push_back(0);
    }
    par[1] = 1;
    int qn = 0;
    for (int i = 1; i < 10; i++) {
        int u = next[1][i];
        if (u) {
            q[qn++] = u;
            par[u] = 1;
        }
    }
    for (int i = 0; i < qn; i++) {
        int cur = q[i];
        for (int j = 0; j < 10; j++) if (next[cur][j]) {
            int u = next[cur][j];
            int v = par[cur];
            while (v > 1 && !next[v][j]) v = par[v];
            if (next[v][j]) v = next[v][j];
            assert(v >= 1);
            par[u] = v;
            q[qn++] = u;
        }
    }
    for (int j = 0; j < 10; j++) {
        if (next[1][j]) go[1][j] = next[1][j];
        else go[1][j] = 1;
    }
    for (int i = 0; i < qn; i++) {
        int u = q[i];
        for (int j = 0; j < 10; j++) {
            if (next[u][j]) go[u][j] = next[u][j];
            else go[u][j] = go[par[u]][j];
        }
    }
    for (int i = 0; i < qn; i++) {
        int u = q[i];
        sort(suf[u].begin(), suf[u].end());
        for (int j = 0, k = 0; j <= n; j++) {
            while (k < suf[u].size() && suf[u][k] <= j) k++;
            cnt[j][u] += cnt[j][par[u]] + k;
        }
    }
    memset(dp, -1, sizeof dp);
    dp[0][1] = 0;
    for (int i = 0; i < n; i++) {
        for (int u = 1; u <= m; u++) if (dp[i][u] >= 0) {
            for (int k = 0; k < 10; k++) {
                int v = go[u][k];
                dp[i+1][v] = max(dp[i+1][v], dp[i][u] + cnt[n-i-1][v]);
            }
        }
    }
    int ans = -1;
    for (int i = 1; i <= m; i++) ans = max(ans, dp[n][i]);
    for (int i = 1; i <= m; i++) if (dp[n][i] == ans) chk[n][i] = 1;
    for (int i = n-1; i >= 0; i--) {
        for (int u = 1; u <= m; u++) if (dp[i][u] >= 0) {
            for (int k = 0; k < 10; k++) {
                int v = go[u][k];
                if (chk[i+1][v] && dp[i][u] + cnt[n-i-1][v] == dp[i+1][v]) {
                    chk[i][u] = 1;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    int cur = 1;
    for (int i = 0; i < n; i++) {
        bool flag = 0;
        for (int j = 0; j < 10; j++) {
            int ncur = go[cur][j];
            if (chk[i+1][ncur] && dp[i+1][ncur] == dp[i][cur] + cnt[n-i-1][ncur]) {
                cur = ncur;
                flag = 1;
                putchar(j + '0');
                break;
            }
        }
        assert(flag);
    }
    puts("");
    return 0;
}