/**
 *  created: 13/10/2021, 17:46:35
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 44, inf = 1000111;

int t, n, a[max_n];

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
            a[i] += inf;
        }
        sort(a, a + n);
        n = unique(a, a + n) - a;
        if (n == 1) {
            cout << "-1\n";
            continue;
        }
        random_shuffle(a, a + n);
        for (int k = 2 * inf; k >= 1; --k) {
            bool ok = 1;
            const int C = a[0] % k;
            for (int i = 0; i < n && ok; ++i) {
                ok &= a[i] % k == C;
            }
            if (ok) {
                cout << k << "\n";
                break;
            }
        }
    }
    return 0;
}