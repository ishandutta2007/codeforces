#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, u; cin >> n >> u;
    vector<int> E(n);
    for (int i = 0; i < n; ++i) {
        cin >> E[i];
    }

    int j = 1;

    double ans = -1;
    for (int i = 1; i + 1 < n; ++i) {
        while (j + 1 < n && E[j + 1] - E[i - 1] <= u)
            ++j;
        if (j > i)
            ans = max(ans, 1.0 * (E[j] - E[i]) / (E[j] - E[i - 1]));
    }
    if (ans < 0) cout << -1 << endl;
    else cout << fixed << setprecision(20) << ans << endl;

    return 0;
}