#include <bits/stdc++.h>
using namespace std;
#define maxn 1000
int t, n, m, a[maxn], b[maxn];

int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> t;
    while (t -- ) {
        cin >> n >> n >> m;
        for (int i = 1; i <= n; ++ i) cin >> a[i];
        for (int i = 1; i <= m; ++ i) cin >> b[i];
        int v1 = 0, v2 = 0;
        for (int i = 1; i <= n; ++ i) v1 = max(v1, a[i]);
        for (int i = 1; i <= m; ++ i) v2 = max(v2, b[i]);
        if (v1 > v2) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}