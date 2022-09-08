/**
 *  created: 25/03/2021, 18:51:19
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n, a[max_n], b[max_n], len[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> len[i];
            len[i] += a[i];
            if (i) {
                len[i] -= b[i - 1];
            }
        }
        int last = 0;
        for (int i = 0; i < n; ++i) {
            last += len[i];
            if (i + 1 < n) {
                last += (b[i] - a[i] + 1) / 2;
                last = max(last, b[i]);
            }
        }
        cout << last << "\n";
    }
    return 0;
}