#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
// const int MOD = 1000000007;

int binpow(int a, int b, int MOD) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

void solve() {
    int MOD = 1000000007;
    int k; 
    cin >> k;
    int p = binpow(2, k, MOD - 1);
    p = (p + MOD - 1 - 2) % (MOD - 1);
    int q = binpow(4, p, MOD);
    cout << q * 6 % MOD << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}