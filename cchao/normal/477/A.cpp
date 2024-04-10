#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

long long f(long long x) {
    return x * (x + 1) / 2 % mod;
}

int main() {
    long long a, b; cin >> a >> b;

    long long l = f(b - 1);
    long long r = b * f(a) % mod + a;

    l %= mod;
    r %= mod;

    cout << l * r % mod << endl;

    return 0;
}