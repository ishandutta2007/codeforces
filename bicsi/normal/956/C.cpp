#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> v(n), lo(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        lo[i] = v[i] + 1;
    }

    for (int i = 0; i + 1 < n; ++i) {
        lo[i + 1] = max(lo[i + 1], lo[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
        lo[i] = max(lo[i], lo[i + 1] - 1);
    }
/*
    for (int i = 0; i < n; ++i) {
        cerr << lo[i] << " ";
    }
    cerr << endl;
*/
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (lo[i] - v[i] - 1);
    }
    cout << ans << endl;

    return 0;
}