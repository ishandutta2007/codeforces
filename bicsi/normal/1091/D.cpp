#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMod = 998244353;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> fact(n + 1, 1), ifact(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        fact[i] = 1LL * fact[i - 1] * i % kMod;
        int b = fact[i];
        int e = kMod - 2;
        int r = 1;
        while (e) {
            if (e % 2) r = r * b % kMod;
            b = b * b % kMod;
            e /= 2;
        }
        ifact[i] = r;
        assert(ifact[i] * fact[i] % kMod == 1);
    }

    auto COMB = [&](int n, int k) {
        return fact[n] * ifact[k] % kMod * ifact[n - k] % kMod;
    };

    int ans = 0;
    for (int pref = 1; pref < n - 1; ++pref) {
        int now = pref * fact[pref] % kMod * (n - pref - 1) % kMod;
        now = now * COMB(n, pref) % kMod;
        ans = (ans + now) % kMod;
    }
    cout << (ans + fact[n] + kMod) % kMod << endl;

    return 0;
}