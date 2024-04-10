#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n, m, a[2][2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        bool ok = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
            ok |= a[0][1] == a[1][0];
        }
        if (ok && m % 2 == 0) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}