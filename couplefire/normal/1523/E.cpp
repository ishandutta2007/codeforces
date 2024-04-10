#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;
ll fac[100005];
ll ifac[100005];

ll power(ll x, ll y){
    ll res = 1;
    while(y){
        if(y&1)
            res = (res * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

ll comb(int n, int k){
    if(k==n || k==0) return 1;
    ll res = fac[n] * ifac[n-k] % mod;
    res = res * ifac[k] % mod;
    return res;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    ll res=1;
    for(ll i=1; i<=n; i++){
        ll a = n - (k-1)*(i-1);
        if(a < i-1) break;
        ll x = comb(a, i) * power(comb(n, i), mod-2) % mod;
        res = (res + x) % mod;
    }
    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
    for(ll x=2; x<=100000; x++){
        fac[x] = (fac[x-1] * x) % mod;
        ifac[x] = power(fac[x], mod-2);
    }
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}