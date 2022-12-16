#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const ll MOD = 1e9+7;
const int N = 1001000;

ll r[N], fac[N], ifac[N];

void setup() {
    r[1] = 1;
    ifac[0] = ifac[1] = fac[1] = fac[0] = 1;
    for (int i=2; i<N; ++i) {
        r[i] = (MOD - (MOD/i) * r[MOD%i] % MOD) % MOD;
        fac[i] = fac[i-1]*i%MOD;
        ifac[i] = ifac[i-1]*r[i]%MOD;
    }
}

ll choose(int n, int k) {
    return (fac[n]*ifac[n-k]%MOD)*ifac[k]%MOD;
}

ll modpow(ll b, ll p) {
    //p = (p+MOD-1)%(MOD-1);
    if (p == -1) {
        return r[b];
    }
    ll ans = 1;
    for (; p; p/=2, b=b*b%MOD) {
        if (p&1) ans = ans*b%MOD;
    }
    return ans;
}

ll n, m, a, b;

ll mpow[N], npow[N];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    cin >> n >> m >> a >> b;
    ll ans = 0;
    mpow[0] = 1;
    npow[0] = modpow(n, -1);
    for (int i=1; i<N; ++i) {
        mpow[i] = mpow[i-1]*m%MOD;
        npow[i] = npow[i-1]*n%MOD;
    }

    for (int i=1; i<=min(m, n-1); ++i) {
        if (i-1 > m-1) continue;
        //ll w = choose(n-2, i-1);
        ll w = fac[n-2]*ifac[(n-2)-(i-1)]%MOD;
        ll x = choose(m-1, i-1);
        //ll x = fac[m-1]*ifac[
        ll y = (i+1)*npow[n-(i+1)]%MOD;
        ll z = mpow[n-(i+1)];
        //cerr << "  ^ " << z << ": " << m << "^" << n-(i+1) << endl;

        //cerr << "  ! " << n << "^" << n-(i+1)-1 << endl;

        ll t = (w*x%MOD)*(y*z%MOD)%MOD;
        ans += t;
        //cerr << " " << i << ": " << t << ": " << w << " " << x << " " << y << " " << z << endl;
    }
    cout << ans%MOD << endl;
    return 0;
}