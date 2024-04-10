#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const ll mod = 998244353;
const int NMAX = 1001000;
ll n;

ll r[NMAX];
ll f[NMAX];
ll fi[NMAX];

void setup() {
    f[0] = fi[0] = r[0] = 1;
    f[1] = fi[1] = r[1] = 1;
    for (int i=2; i<NMAX; ++i) {
        r[i] = (mod - (mod/i) * r[mod%i] % mod) % mod;
        f[i] = f[i-1]*i%mod;
        fi[i] = fi[i-1]*r[i]%mod;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    cin >> n;
    ll ans = 0;
    for(int i=2;i<=n;++i) {
        //cerr << " " << f[n] << " " << fi[i] << " -> " << f[n]*fi[i]%mod << " " << f[i]-1 << endl;
        ans = (ans+f[n]*fi[i]%mod*(f[i]+mod-1)%mod)%mod;
    }
    ans = (ans+1)%mod;
    cout << ans << endl;
    return 0;
}