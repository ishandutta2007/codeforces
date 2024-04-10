#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 450;
char s[N], g1[N], g2[N];
int dp[N][N];

int check(int n, int m) {
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    for (int i=1; i<=n; ++i) {
        for (int j=0; j<=m; ++j) {
            dp[i][j] = dp[i-1][j];
            if (j > 0 && s[i] == g1[j]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            }
            int k = dp[i-1][j];
            if (s[i] == g2[k+1] && k >= 0) {
                dp[i][j] = max(dp[i][j], k+1);
            }
        }
    }

    return dp[n][m];
}

char t[N];

void solve() {
    cin >> (s+1) >> (t+1);
    int n = strlen(s+1);
    int q = strlen(t+1);
    for (int i=0; i<=q; ++i) {
        memset(g1, 0, sizeof g1);
        memset(g2, 0, sizeof g2);
        for (int j=1; j<=i; ++j) {
            g1[j] = t[j];
        }
        for (int j=i+1; j<=q; ++j) {
            g2[j-i] = t[j];
        }
        int res = check(n, i);
        if (res == q-i) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO" << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        solve();
    }
    return 0;
}