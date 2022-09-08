/**
 *  created: 30/10/2021, 17:39:57
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 101111, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        bool ok = 1;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            bool cur = 0;
            for (int j = 1; j <= i; ++j) {
                if (a[i] % (j + 1)) {
                    cur = 1;
                    break;
                }
            }
            ok &= cur;
        }
        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}