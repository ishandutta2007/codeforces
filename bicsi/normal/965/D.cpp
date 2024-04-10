#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<long long> s(n + 1, 0);
    long long best = 2e18;

    for (int i = 1; i < n; ++i) {
        int now; cin >> now; s[i] = s[i - 1] + now;
        if (i >= k) best = min(best, s[i] - s[i - k]);
    }
    cout << best << endl;

    return 0;
}