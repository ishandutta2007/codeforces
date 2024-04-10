#include <iostream>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll pw(ll a, ll b) {
    if(b == 0) return 1;
    ll t = pw(a, b/2);
     t *= t;
     t %= MOD;
     if(b&1) t*= a;
     return t % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll p2 = pw(2, n % (MOD-1));
    cout << (((p2*(p2+1)) % MOD) * pw(2, MOD-2)) % MOD << "\n";
    return 0;
}