#include <bits/stdc++.h>

using namespace std;
typedef int ll;
const ll INFLL = 0x3f3f3f3f;

ll dp[1010][55][55];
ll f[55];
ll g[55];

char s[55], t[55];
int n, m;

char c[1010];
int x;

void setup() {
    for (int i=0; i<1010; ++i) {
        for (int j = 0; j<55; ++j) {
            for (int k = 0; k<55; ++k) {
                dp[i][j][k] = -INFLL;
            }
        }
    }
}

void build(char *s, ll *f, int n) {
    f[0] = 0;
    for (int i=1; i<n; ++i) {
        int j = f[i-1];
        while (j && s[i] != s[j]) {
            j = f[j-1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        f[i] = j;
    }
}

void update_from(int i, int j, int k, char d) {
    int jj = j;
    int kk = k;
    ll a = dp[i][j][k];

    while (jj && d != s[jj]) {
        jj = f[jj-1];
    }
    if (d == s[jj]) ++jj;

    while (kk && d != t[kk]) {
        kk = g[kk-1];
    }
    if (d == t[kk]) ++ kk;

    if (jj == n) {
        ++a;
        jj = f[jj-1];
    }
    if (kk == m) {
        --a;
        kk = g[kk-1];
    }
    dp[i+1][jj][kk] = max(a, dp[i+1][jj][kk]);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> c;
    cin >> s;
    cin >> t;
    x = strlen(c);
    n = strlen(s);
    m = strlen(t);

    setup();
    build(s, f, n);
    build(t, g, m);

    dp[0][0][0] = 0;

    for (int i=0; i<x; ++i) {
        for (int j=0; j<n; ++j) {
            for (int k=0; k<m; ++k) {
                if (dp[i][j][k] == -INFLL) continue;
                //cerr << " dp[" << i << "][" << j << "][" << k << "] = " << dp[i][j][k] << endl;
                if (c[i] == '*') {
                    update_from(i, j, k, 0);
                    update_from(i, j, k, s[j]);
                    update_from(i, j, k, t[k]);
                } else {
                    update_from(i, j, k, c[i]);
                }
            }
        }
    }
    ll ans = -INFLL;
    for (int j=0; j<n; ++j) {
        for (int k=0; k<m; ++k) {
            ans = max(ans, dp[x][j][k]);
        }
    }
    cout << ans << "\n";

    return 0;
}