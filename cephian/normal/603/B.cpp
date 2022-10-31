#include <iostream>

using namespace std;
typedef long long ll;

ll MOD = 1000000007;

ll powt(ll a, ll b) {
    if(b == 0) return 1;
    ll t = powt(a, b/2);
    t *= t;
    t %= MOD;
    if(b & 1) t *= a;
    return t % MOD;
}

ll p, k;
bool fix[1000005];

int main() {
    cin >> p >> k;
    if(k == 0)
        cout << powt(p,p-1) << "\n";
    else if(k == 1)
        cout << powt(p,p) << "\n";
    if(k < 2)
        return 0;
    fill(fix, fix+p, 0);
    ll ans = 1;
    for(int i = 1; i < p ;++i) {
        if(!fix[i]) {
            ans = (ans * p) % MOD;
            for(int j = i; !fix[j]; j = (j * k) % p)
                fix[j] = 1;
        }
    }
    cout << ans << "\n";
    return 0;
}