#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

typedef long long LL;

LL extended_euclidean(LL a, LL b, LL &x, LL &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    LL res = extended_euclidean(b, a % b, y, x);
    y -= a / b * x;
    return res;
}

LL modular(LL x, LL m) {
    if (x < 0) x += abs(x / m) * m + m;
    return x % m;
}

LL modular_inverse(LL a, LL m) {
    LL x, y;
    extended_euclidean(a, m, x, y);
    return modular(x, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    long long a, b, p, x;
    cin >> a >> b >> p >> x;
    long long ans = 0;
    if (a == 1) {
        ans = x / p;
        if (x % p >= b) ++ans;
        cout << ans << endl;
        return 0;
    }

/*
    long long ansL = 0;
    long long K = 1;
    for (int i = 1; i <= x; ++i) {
        K = (K * a) % p;
        if (K * i % p == b) ++ansL;//cout << i << " ";
    }
    cout << ansL << endl;
*/
    
    long long invb = modular_inverse(b, p);
    long long temp = invb;
    long long bigp = p * (p - 1);
    for (int i = 1; i < p - 1; ++i) {
        temp = (temp * a) % p;
        long long inv = modular_inverse(temp, p);
        long long a = (p + p - inv + i) % p;
        ans += x / bigp;
        if (x % bigp >= a * (p - 1) + i) ++ans;
    }

    // dan suan p-1
    temp = (temp * a) % p;
    long long inv = modular_inverse(temp, p);
    ans += x / bigp;
    if (x % bigp >= (p - inv) * (p - 1)) ++ans;
    cout << ans << endl;
    return 0;
}