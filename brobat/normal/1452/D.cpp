#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 998244353;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

int pw[MAXN], inv[MAXN], ans[MAXN];

void pre(int n) {
    pw[0] = inv[0] = 1;
    forn(i, 1, n + 1) {
        pw[i] = (pw[i - 1] * 2) % MOD;
        inv[i] = binpow(pw[i], MOD - 2);
    }
    ans[0] = 1;
    ans[1] = inv[1];
    ans[2] = inv[2];
    forn(i, 3, n + 1) {
        ans[i] = (ans[i-1]*inv[1] + ans[i-2]*inv[2]) % MOD;
    }
}

void solve() {
    int n; cin >> n;
    pre(n);
    cout << ans[n];
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    while(T--) solve();

    return 0;
}