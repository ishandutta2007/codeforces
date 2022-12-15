#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const ll MOD = 1'000'000'007;
ll mypw(ll x, ll k) {
    if (!k) return 1;
    ll a = mypw(x, k>>1);
    a = a * a % MOD;
    if (k&1) return a * x % MOD;
    else return a;
}

const int MAXn = 2e5 + 5;
ll fac[MAXn], ifac[MAXn];

ll p(int a, int b) {
    return fac[a] * ifac[a - b] % MOD;
}
ll c(int a, int b) {
    return fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
}
ll h(ll a, ll b) {
    if (b < 0)
        return 0;
    return c(a + b - 1, b);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    fac[0] = 1;
    for (int i = 1; i < MAXn; i++)
        fac[i] = fac[i - 1] * i % MOD;
    ifac[MAXn - 1] = mypw(fac[MAXn - 1], MOD - 2);
    for (int i = MAXn - 2; i >= 0; i--)
        ifac[i] = ifac[i + 1] * (i + 1) % MOD;
    int T;
    cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        ll x = 1, y = 1;
        for (int i = 1; i <= n; i++) {
            ll xx = h(i + 1, n - i - (k - 1) * (i - 1)) * fac[i] % MOD; 
            ll yy = p(n, i);
            // cerr << i << " " << xx << " " << yy << "\n";
            x = (x * yy + xx * y) % MOD;
            y = y * yy % MOD;
        }
        cout << x * mypw(y, MOD - 2) % MOD << "\n";
    }
    
}