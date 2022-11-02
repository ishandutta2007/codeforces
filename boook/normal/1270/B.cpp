#include <bits/stdc++.h>
using namespace std;
#define maxn 200090
#define PII pair<int, int>

int t, n, x[maxn];

int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> t;
    while (t -- ) {
        cin >> n;
        for (int i = 1; i <= n; ++ i) cin >> x[i];
    
        int ok = 0, ans;
        for (int i = 2; i <= n; ++ i) {
            if (abs(x[i] - x[i - 1]) >= 2) {
                ok = 1, ans = i;
            }
        }
//        PII sml = make_pair(x[1], 1);
//        PII big = make_pair(x[1], 1);
//
//        for (int i = 1; i <= n; ++ i) {
//            sml = min(sml, make_pair(x[i], i));
//            big = max(big, make_pair(x[i], i));
//        }
//
        if (ok) {
            cout << "YES\n";
            cout << ans - 1 << " " << ans << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}