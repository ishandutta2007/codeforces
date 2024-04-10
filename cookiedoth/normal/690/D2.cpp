#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

const int mod = 1000003;
const int maxn = 1000000;

long long fact[maxn];

long long pw(long long a, long long b) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        long long c = pw(a, b / 2);
        return c * c % mod;
    }
    return pw(a, b - 1) * a % mod;
}

long long rev(long long x) {
    return pw(x, mod - 2);
}

long long C(int n, int k) {
    return fact[n] * rev(fact[k] * fact[n - k] % mod) % mod;
}

int main() {
    int n, c;
    cin >> n >> c;
    fact[0] = 1;
    for (int i = 1; i < maxn; i++) fact[i] = fact[i - 1] * i % mod;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += C(i + c - 1, c - 1);
    }
    cout << ans % mod << endl;
}