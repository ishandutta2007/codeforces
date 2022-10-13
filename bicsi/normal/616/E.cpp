#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;


typedef long long ll;

const ll MOD = 1e9 + 7;
const ll INV2 = 500000004;

ll sum(ll a, ll b) {
    ll rez = b % MOD * ((b + 1) % MOD) % MOD * INV2 % MOD;
    ll sub = a % MOD * ((a - 1) % MOD) % MOD * INV2 % MOD;

    rez -= sub;
    rez %= MOD;

    if(rez < 0) rez += MOD;
    return rez;
}

ll calcdiv2(ll n, ll m) {
    ll r = 0;
    for(ll i=1; i<=m; i++) {
        r += (n/i*i) % MOD;
        r %= MOD;
    }
    return r;
}


ll sol = 0;

void calcdiv(ll n, ll m) {

    while(m > 5000000) {

        if(m > n) m = n;

        ll r = n / m;

        ll k = n / (r+1);

        while((k + 1) / m == (r + 1)) k += 1;
        while(k / m == r) k -= 1;

        ll ss = sum(k + 1, m);
        r = r % MOD * ss % MOD;


        sol += r;
        if(sol >= MOD) sol -= MOD;
        m = k;
    }

    sol += calcdiv2(n, m);
    if(sol >= MOD) sol -= MOD;
}

int main() {
    ll n, m;
    cin >> n >> m;

    ll r = n % MOD * (m % MOD) % MOD;
    calcdiv(n, m);
    r -= sol;
    r %= MOD;

    if(r < 0) r += MOD;

    cout << r;

//    cerr << '\n' << calcdiv(n, m) << " " << calcdiv2(n, m) << '\n';
 }