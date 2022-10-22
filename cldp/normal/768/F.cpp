#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;


const long long INF = 1000000007;
const int MAXN = 2010;

long long fac[200100], rev[200100];

long long extended_euclidean(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long res = extended_euclidean(b, a % b, y, x);
    y -= a / b * x;
    return res;
}

long long modular(long long x, long long m) {
    if (x < 0) x += abs(x / m) * m + m;
    return x % m;
}

long long modular_inverse(long long a, long long m) {
    long long x, y;
    extended_euclidean(a, m, x, y);
    return modular(x, m);
}

long long count(long long i, long long W, long long F) {
    long long ans = fac[W + i - 1];
    ans = (ans * rev[i - 1]) % INF;
    ans = (ans * rev[W]) % INF;
    ans = (ans * fac[F + i]) % INF;
    ans = (ans * rev[i]) % INF;
    ans = (ans * rev[F]) % INF;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    fac[0] = 1;
    for (int i = 1; i <= 200000; ++i) {
        fac[i] = (fac[i - 1] * i) % INF;
        rev[i] = modular_inverse(fac[i], INF);
    }
    rev[0] = rev[1];
    
    long long F, W, H;
    cin >> F >> W >> H;
    if (W == 0) {
        cout << 1 << endl;
        return 0;
    }
    if (F == 0) {
        if (W > H) cout << 1 << endl; else cout << 0 << endl;
        return 0;
    }
    ++H;
    long long num = 0, den = 0;
    for (int i = 1; ; ++i) {
        if (1LL * i * H > W || (i - 1) > F) break;
        num = (num + count(i, W - i * H, F - (i - 1))) % INF;
    }
    for (int i = 1; ; ++i) {
        if (i > W || (i - 1) > F) break;
        den = (den + count(i, W - i, F - (i - 1))) % INF;
    }
    num = (num * modular_inverse(den, INF)) % INF;
    cout << num << endl;
    return 0;
}