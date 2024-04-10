#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 9;

int n, a, b, k;

int fpow(long long x, long long y) {
    x = (x % mod + mod) % mod;
    int res = 1;
    while(y) {
        if(y & 1) res = 1LL * res * x % mod;
        y >>= 1;
        x = (1LL * x * x) % mod;
    }
    return res;
}

int main(){

    cin >> n >> a >> b >> k;
    string s; cin >> s;

    long long v = 0;
    for(int i = 0; i < k; ++i) {
        long long sign = (s[i] == '-' ? -1 : 1);
        v += fpow(b, i) * sign * fpow(a, n - i) % mod;
        v %= mod;
    }

    v += mod;
    v %= mod;

    long long r = 1LL * fpow(b, k) * fpow(fpow(a, mod - 2), k) % mod;
    long long rep = (n + 1) / k;

    if(r == 1) {
        cout << v * rep % mod << endl;
        return 0;
    }

    long long risan = 1LL * v * (1 - fpow(r, rep)) % mod;
    risan = risan * fpow(1 - r, mod - 2) % mod;

    risan += mod;
    risan %= mod;

    cout << risan << endl;

    return 0;
}