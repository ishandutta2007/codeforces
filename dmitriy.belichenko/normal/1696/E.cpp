#include<bits/stdc++.h>
using namespace std;
const int MOD = 1'000'000'007;
const int N = 2e5 + 1;
long long poww(long long x, int n) {
    if (n == 0) {
        return 1;
    }
    long long hf = poww(x, n >> 1);
    if (n & 1) {
        return x * hf % MOD * hf % MOD;
    } else return hf * hf % MOD;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> fact(2 * N + 10), a(n + 1);
    for (auto &x : a) cin >> x;
    fact[0] = 1;
    for (int i = 1; i < 2 * N + 10; i++) fact[i] = fact[i - 1] * i % MOD;
    long long ans = 0;
    for (int i = 0; i < n + 1; i++) {
        if (a[i] < 1) continue;
        ans += fact[i + a[i]] * poww(fact[i + 1], MOD - 2) % MOD * poww(fact[a[i] - 1], MOD - 2) % MOD;
        ans %= MOD;
    }
    cout << ans << "\n";
    return 0;
}