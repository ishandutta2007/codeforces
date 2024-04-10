#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, ta, tb, k; cin >> n >> m >> ta >> tb >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int j = 0;
    if (k >= n || k >= m) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        while (j < m && a[i] + ta > b[j]) ++j;
        int x = j + (k - i);
        if (x >= m) {
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, b[x] + tb);
    }
    cout << ans << endl;

    return 0;
}