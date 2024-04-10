#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> par(n, -1);
    vector<int> depth(n, 0);
    vector<int> cnt(n + 1, 0);
    cnt[0] = 1;
    for (int i = 1; i < n; ++i) {
        cin >> par[i]; --par[i];
        depth[i] = 1 + depth[par[i]];
        cnt[depth[i]] += 1;
    }

    int ans = 0;
    for (auto x : cnt) {
        ans += x % 2;
    }
    cout << ans << endl;

    return 0;
}