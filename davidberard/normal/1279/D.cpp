#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const ll MOD = 998244353;

ll modpow(ll b, ll p) {
    ll ans = 1;
    for(; p; p/=2, b=b*b%MOD) {
        if (p&1) ans = ans*b%MOD;
    }
    return ans;
}

const int N = 1001000;
ll wanting[N];
vector<ll> a[N];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i=1; i<=n; ++i) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (auto& x : a[i]) {
            cin >> x;
            ++wanting[x];
        }
    }
    ll in = modpow(n, MOD-2);
    ll ans = 0;
    for (int i=1; i<=n; ++i) {
        ll ik = modpow(a[i].size(), MOD-2);
        ll ininik = (in*in%MOD)*ik%MOD;
        for (auto& x : a[i]) {
            ans += ininik*wanting[x]%MOD;
        }
    }
    cout << ans%MOD << "\n";
    return 0;
}