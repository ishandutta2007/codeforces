#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 998244353;

int fact[MAXN];

void pre() {
    fact[0] = 1;
    forn(i, 1, MAXN + 1) {
        fact[i] = (fact[i-1]*i) % MOD;
    }
}

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res%MOD;
}

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    forn(i, 0, n) cin >> v[i];
    int x = 0, y = 0;
    int mx = *max_element(v.begin(), v.end());
    forn(i, 0, n) {
        if(v[i]==mx) x++;
        if(v[i]==mx-1) y++;
    }
    if(x > 1) {
        cout << fact[n] << endl;
        return;
    }
    int z = fact[n] * binpow(y+1, MOD - 2) % MOD;
    cout << (fact[n] + MOD - z) % MOD << endl;
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