#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const ll MOD = 998244353;

int n, m, k;

const int N = 5050;
ll choose[N];
ll fac[N], ifac[N];

ll modpow(ll b, ll p) {
    ll ans = 1;
    for(; p; b=b*b%MOD, p/=2) {
        if (p&1) ans = ans*b%MOD;
    }
    return ans;
}

ll dp[N][N];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;

    ll im = modpow(m, MOD-2);

    dp[0][0] = 1;
    for (int i=1; i<=k; ++i) {
        for (int j=1; j<=min(k, n); ++j) {
            dp[i][j] = ((dp[i-1][j]*j%MOD) + (dp[i-1][j-1]*(n-j+1)%MOD))%MOD;
        }
    }

    ll ans = 0;
    for (int i=1; i<=min(k, n); ++i) {
        ans += modpow(im, i)*dp[k][i]%MOD;
    }
    cout << ans%MOD << endl;
    
    return 0;
}