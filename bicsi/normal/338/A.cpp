#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef unsigned long long ll;

ll total = 0;

const ll P = 1e9 + 9;

ll lgpow(ll b, ll e) {

    ll rez = 1;
    for(ll i=0; (1LL << i) <= e; i++) {
        if(e & (1LL << i)) {
            rez *= b;
            rez %= P;
        }

        b *= b;
        b %= P;
    }

    return rez;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE


    ll n, m, k;

    cin>>n>>m>>k;

    ll bad = n-m;

    ll one_pointers = k * bad;

    if(one_pointers >= n) {
        cout << m;
        return 0;
    }

    n -= one_pointers;

    total = one_pointers - bad;
    total += n % k;

    n /= k;
    total %= P;

    ll r1 = lgpow(2LL, n+1);
    r1 += (P - 2);
    r1 %= P;

    r1 *= k;
    r1 %= P;

    total += r1;
    total %= P;

    cout << total;
    return 0;
}