#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const ll MOD = 1e9+7;

ll modpow(ll b, ll p) {
    ll ans = 1;
    for(; p; p/=2, b=b*b%MOD) {
        if (p&1) ans = ans*b%MOD;
    }
    return ans;
}

ll ways[1010];
ll fac[2010];
ll ifac[2010];

void setup() {
    fac[0] = ifac[0] = 1;
    for (int i=1; i<2010; ++i) {
        fac[i] = fac[i-1]*i%MOD;
        ifac[i] = ifac[i-1]*modpow(i, MOD-2)%MOD;
    }
}

ll choose(int n, int k) {
    assert(k<=n);
    return (fac[n]*ifac[k]%MOD)*ifac[n-k]%MOD;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    ll n, m;
    cin >> n >> m;
    for (int i=1; i<=n; ++i) {
        ways[i] = choose(m-1+i-1, m-1);
        //cerr << "  " << m+1-1 << " CHOOSE " << m-1 << endl;
        //cerr << " WAYS " << i << " = " << ways[i] << endl;
    }

    ll ans = 0;
    for (int i=1; i<=n; ++i) {
        for (int j=1; i+j<=n+1; ++j) {
            ans += ways[i]*ways[j]%MOD;
        }
    }
    ans = ans%MOD;
    cout << ans << endl;
    return 0;
}