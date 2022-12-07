#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int MOD = 998244353;
const int MAXN = 255;
int fact[MAXN], inv_fact[MAXN];

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

int comb(int n, int r) {
    if(r > n) return 0;
    return fact[n] * inv_fact[n - r] % MOD * inv_fact[r] % MOD;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N, K;
    cin >> N >> K;

    fact[0] = 1;
    inv_fact[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv_fact[i] = binpow(fact[i], MOD - 2);
    }
    int ans[MAXN][MAXN];
    memset(ans, 0, sizeof(ans));

    ans[0][0] = 1;
    for(int i = 1; i < MAXN; i++) {
        ans[1][i] = ans[1][i - 1] + 1;
        ans[0][i] = 1;
    }
    for(int i = 2; i < MAXN; i++) {
        for(int j = 1; j <= K; j++) {
            ans[i][j] = (ans[i][j] + ans[i][j - 1]) % MOD;
            for(int k = 1; k <= i; k++) {
                int t1 = comb(i, k);
                int t2 = ans[i - k][j - 1];
                int t3 = binpow(K - j + 1, (i - k)*(k) + (k)*(k - 1)/2);
                ans[i][j] = (ans[i][j] + (t1 * t2 % MOD * t3 % MOD)) % MOD;        
            }
        }
    }

    cout << ans[N - 1][K];
    
    return 0;
}