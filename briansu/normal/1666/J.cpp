#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int N = 205;
ll C[N][N], PC[N][N], W[N][N], S[N], PS[N], dp[N][N], pi[N][N];

int p[N];

void dfs(int l, int r, int x) {
    if (r < l)
        return;
    if (r == l) {
        p[l] = x;
        return;
    }
    int k = pi[l][r];
    p[k] = x;
    dfs(l, k - 1, k);
    dfs(k + 1, r, k);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> C[i][j], S[i] += C[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            PC[i][j] = C[i][j] + PC[i - 1][j] + PC[i][j - 1] - PC[i - 1][j - 1];

    for (int i = 1; i <= n; i++)
        PS[i] = PS[i - 1] + S[i];
        
    for (int l = 1; l <= n; l++)
        for (int r = l; r <= n; r++)
            W[l][r] = -(PC[r][r] - PC[r][l - 1] - PC[l - 1][r] + PC[l - 1][l - 1]) + (PS[r] - PS[l - 1]);

    for (int L = 2; L <= n; L++)
        for (int l = 1; l + L - 1 <= n; l++) {
            int r = l + L - 1;
            dp[l][r] = 1e18, pi[l][r] = -1;
            for (int k = l; k <= r; k++) {
                ll x = dp[l][k - 1] + dp[k + 1][r] + W[l][k - 1] + W[k + 1][r]; 
                if (x < dp[l][r])
                    dp[l][r] = x, pi[l][r] = k;
            }
        }

    // cerr << dp[1][n] << "\n";
        
    dfs(1, n, 0);
    for (int i = 1; i <= n; i++)
        cout << p[i] << " \n"[i == n];
}