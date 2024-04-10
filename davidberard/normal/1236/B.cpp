#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const ll MOD = 1e9+7;
ll n, m;

ll tpow(ll b, ll p) {
    ll x = b;
    ll ans = 1;
    for (int i=0; i<31; ++i) {
        if ((p>>i)&1) {
            ans = ans*x%MOD;
        }
        x = x*x%MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    cout << tpow((tpow(2, m)+MOD-1), n) << "\n";
    return 0;
}