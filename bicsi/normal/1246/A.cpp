#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, p; cin >> n >> p;
    int best = 2e9;
    for (int it = 1; it < 1000; ++it) {
        int newn = n - it * p;
        if (newn < it) continue;
        int ans = __builtin_popcount(newn);
        if (ans > it) continue;
        best = min(best, it);
    }

    if (best == 2e9) {
        cout << -1 << endl;
    } else {
        cout << best << endl;
    }

    return 0;
}