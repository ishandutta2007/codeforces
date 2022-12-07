#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;
const int MAXN = 5005;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int f[MAXN];
    int inv[MAXN];
    f[0] = f[1] = 1;
    inv[0] = inv[1] = 1;
    for(int i = 2; i < MAXN; i++) {
        f[i] = (f[i - 1] * i) % MOD;
        inv[i] = binpow(f[i], MOD - 2);
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> v(n + 1, 0); // v[i] --> Count of blocks of size i
        vector <int> c(n + 1, 0); // c[i] --> Number of blocks strictly less than size i
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            v[x]++;
        }
        for(int i = 1; i <= n; i++) {
            c[i] = c[i - 1] + v[i - 1];
        }
        // for(int i = 1; i <= n; i++) {
            // cerr << c[i] << " ";
        // }
        // cerr << '\n';
        int m = n/2;
        vector<vector<int>> dp(m, vector<int>(n + 1, 0));
        // dp[i][j] --> The answer assuming the i^th even block from top has value j.
        for(int i = 0; i <= n; i++) {
            if(v[i] > 0) {
                dp[0][i] = c[i] * v[i];      
            }
        }
        for(int i = 1; i < m; i++) {
            int x = 0;
            for(int j = 1; j <= n; j++) {
                if(c[j] - 2*(i - 1) - 1 < 0) continue;
                // dp[i][j] --> dp[i - 1][all lower values]
                if(v[j] != 0) {
                    dp[i][j] = x * v[j] % MOD;
                    x = (x + dp[i - 1][j] * (c[j] - 2*(i - 1) - 1)) % MOD;
                }
                // cerr << i << " " << j << " " << x << '\n';    
            }
        }
        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j <= n; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        int ans = 0;
        for(int j = 0; j <= n; j++) {
            ans = (ans + dp[m - 1][j]) % MOD;
        }
        for(int j = 0; j <= n; j++) {
            ans = (ans * inv[v[j]]) % MOD;
        }
        cout << ans << '\n';
    }
    
    return 0;
}