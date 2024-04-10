#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;


const ll mod = 1e9 + 7;
const ll M = 5e5;

ll F[505050], IF[505050];

ll inv(ll x) { return x > 1 ? inv(mod % x) * (mod - mod / x) % mod : 1; }

void tc() {
    ll n, i, a, s;
    cin >> n;
    s = 0;
    for (i = 0; i <= n; i++) {
        cin >> a;
        if (a) s = (s +  F[a + i] * IF[i + 1] % mod * IF[a - 1]) % mod;
    }
    cout << s << "\n";
    return;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll i;
    
    F[0] = 1;
    for (i = 1; i <= M; i++) {
        F[i] = F[i - 1] * i % mod;
    }
    IF[M] = inv(F[M]);
    for (i = M; i >= 1; i--) {
        IF[i - 1] = IF[i] * i % mod;
    }
    
    int t = 1;
    
    for (; t--; ) {
        tc();
    }
    
    return 0;
}