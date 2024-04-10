#include<bits/stdc++.h> 

using namespace std;

typedef long long ll;

const ll mod = 1e6 + 3;

ll ex[int(mod + 10)];

ll expo(ll x, ll e) {
    if (e == 0) return 1;
    if (e%2) return (x*expo((x*x)%mod, e/2))%mod;
    return (expo((x*x)%mod, e/2))%mod;
}

ll inv(ll x) {
    return expo(x, mod - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ex[0] = 1;
    for (int i = 1; i < mod; ++i) ex[i] = (ex[i-1]*2ll)%mod; 
    
    ll n, k;
    cin >> n >> k;
    
    if (n < 64 and 1ll<<n < k) {
        cout << "1 1" << endl;
        return 0;
    }
    
    ll dos = ex[(n%(mod-1))];
    ll B = ex[((n%(mod-1))*(k%(mod-1)))%(mod-1)];
    ll A = 1;
//     cerr << dos << endl;
//     cerr << B << endl;
    if (k > dos) A = 0;
    else {
        for (int i = 0; i < k; ++i) {
            A = (A*(dos - i))%mod;
        }
    }
    ll q = n;
    --k;
    while (k > 0) {
        k /= 2;
        q += k;
    }
    
    A = (A*inv(expo(2, q)))%mod;
    B = (B*inv(expo(2, q)))%mod;
    
    A = (B - A + mod)%mod;
    
    cout << A << ' ' << B << endl;
}