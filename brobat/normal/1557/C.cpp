#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

int fact[MAXN];
int inv_fact[MAXN];

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

void pre() {
    fact[0] = inv_fact[0] = 1;
    forn(i, 1, MAXN) {
        fact[i] = (fact[i-1] * i) % MOD;
        inv_fact[i] = binpow(fact[i], MOD - 2);
    }
}

int nCr(int n, int r) {
    return fact[n] * inv_fact[r] % MOD * inv_fact[n-r] % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;
    if(k==0) {
        cout << 1 << endl;
        return;
    }
    int x = (n%2)?0:1, y = (n%2)?1:0;
    for(int i = 0; i<n; i+=2) y = (y + nCr(n, i)) % MOD; 
    int dp[k+1];
    dp[0] = 1;
    forn(i, 1, k+1) {
        dp[i] = (x*binpow(2, n*(i-1)%(MOD-1))%MOD + y*dp[i-1]%MOD) % MOD;
    }
    cout << dp[k] << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    pre();
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}