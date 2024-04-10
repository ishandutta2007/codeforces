#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const ll MOD = 1e9+7;
ll dp[100];
ll r[100];

ll n, k;

ll modpow(ll b, ll p, ll m=MOD) {
    ll ans = 1;
    for (; p; p/=2, b=b*b%m) {
        if (p&1) ans = ans*b%m;
    }
    return ans;
}

void setup() {
    r[1] = 1;
    for (int i=2; i<100; ++i) {
        r[i] = modpow(i, MOD-2);
    }
}

ll eprime(ll b, ll a) {
    memset(dp, 0, sizeof dp);
    dp[a] = 1;
    for (int i=1; i<=k; ++i) {
        for (int j=a; j>=0; --j) {
            //cerr << "  : " << dp[j] << " -> ";
            dp[j] = (dp[j+1] + dp[j]*r[j+1])%MOD;
            //cerr << dp[j]  << endl;
        }
    }
    ll ans = 0;
    ll p = 1;
    for (int i=0; i<=a; ++i) {
        //cerr << " : " << p << "*" << dp[i] << endl;
        ans = (ans + p*dp[i])%MOD;
        p = p*b%MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    cin >> n >> k;
    ll ans = 1;
    for (ll i=2; i*i<=n; ++i) {
        if (n%i == 0) {
            int a = 0;
            while (n%i == 0) {
                ++a;
                n/=i;
            }
            ans = ans*eprime(i, a)%MOD;
        }
    }
    ans = ans*eprime(n, 1)%MOD;
    cout << ans << "\n";
    return 0;
}