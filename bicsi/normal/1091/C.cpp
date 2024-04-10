#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    set<long long> ret;
    
    auto DO = [&](int d) {
        assert(n % d == 0);
        // 0 -> d -> 2d -> ... -> (n - 1) / d * d
        long long now = 1LL * n / d * (n / d - 1) / 2;
        now *= d;
        now += n / d;
        ret.insert(now);
    };

    for (int d = 1; d * d <= n; ++d) {
        if (n % d) continue;
        DO(n / d);
        DO(d);
    }

    for (auto x : ret) cout << x << " ";
    cout << endl;

    return 0;
}