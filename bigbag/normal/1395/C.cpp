#include <bits/stdc++.h>

using namespace std;

const int max_n = 222, inf = 1000111222;

int n, m, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    for (int ans = 0; ; ++ans) {
        bool ok = 1;
        for (int i = 0; i < n; ++i) {
            bool f = 0;
            for (int j = 0; j < m; ++j) {
                const int x = a[i] & b[j];
                if ((ans & x) == x) {
                    f = 1;
                }
            }
            ok &= f;
        }
        if (ok) {
            cout << ans << "\n";
            return 0;
        }
    }
    return 0;
}