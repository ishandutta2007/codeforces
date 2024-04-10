#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int den = binpow(2, MOD - 2);
    int dp[n+1][n+1]; // Assuming i turns are left and Bob has to choose m in j turns.
    memset(dp, 0, sizeof(dp));
    forn(i, 0, n + 1) dp[i][i] = (i*k) % MOD;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            // Calculate dp[i][j]
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD * den % MOD;
        }
    }
    cout << dp[n][m] % MOD << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}