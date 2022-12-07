#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 400100;
const int MOD = (int)1E9 + 7;

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
    
    vector <int> fact(N), inv(N);
    fact[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = binpow(fact[i], MOD - 2);
    }

    auto COMB = [&](int a, int b) -> int {
        if(a < b) return 0;
        return fact[a] * inv[b] % MOD * inv[a - b] % MOD;
    };

    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i <= n; i++) {
        int j;
        cin >> j;
        ans = (ans + COMB(i + j, i + 1)) % MOD;
    }
    cout << ans;
    
    return 0;
}