#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n, a[max_n], b[max_n], c[max_n], ans[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }
        ans[0] = a[0];
        for (int i = 1; i < n; ++i) {
            if (a[i] != ans[i - 1] && (i + 1 < n || a[i] != ans[0])) {
                ans[i] = a[i];
            }
            if (b[i] != ans[i - 1] && (i + 1 < n || b[i] != ans[0])) {
                ans[i] = b[i];
            }
            if (c[i] != ans[i - 1] && (i + 1 < n || c[i] != ans[0])) {
                ans[i] = c[i];
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}