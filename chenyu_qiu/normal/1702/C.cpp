#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        while (k--) {
            int b, c;
            cin >> b >> c;
            auto it1 = lower_bound(a.begin(), a.end(), pair<int, int>(b, 0));
            if (it1 == a.end() || it1->first != b) {
                cout << "NO\n";
                continue;
            }
            auto it2 = upper_bound(a.begin(), a.end(), pair<int, int>(c, n));
            if (it2 == a.begin()) {
                cout << "NO\n";
                continue;
            }
            it2--;
            if (it2->first != c) {
                cout << "NO\n";
                continue;
            }
            if (it1->second <= it2->second) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}