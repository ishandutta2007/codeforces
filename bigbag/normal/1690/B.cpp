/**
 *  created: 07/06/2022, 17:40:56
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        int id = max_element(b, b + n) - b;
        if (!b[id]) {
            cout << "YES\n";
        } else {
            int x = a[id] - b[id];
            for (int i = 0; i < n; ++i) {
                a[i] = max(a[i] - x, 0);
            }
            bool ok = (x >= 0);
            for (int i = 0; i < n; ++i) {
                ok &= a[i] == b[i];
            }
            if (ok) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}