/**
 *  created: 27/01/2022, 16:39:47
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n, k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int full = n - 1;
        if (!k) {
            for (int i = 0; i < n; ++i) {
                if (i < (i ^ full)) {
                    cout << i << " " << (i ^ full) << "\n";
                }
            }
        } else if (k < full) {
            const int x = k ^ full;
            for (int i = 1; i + 1 < n; ++i) {
                if (i != k && i != x && i < (i ^ full)) {
                    cout << i << " " << (i ^ full) << "\n";
                }
            }
            cout << k << " " << full << "\n";
            cout << 0 << " " << x << "\n";
        } else {
            if (n == 4) {
                cout << "-1\n";
            } else {
                cout << full << " " << full - 1 << "\n";
                cout << 1 << " " << 3 << "\n";
                cout << 0 << " " << full - 3 << "\n";
                for (int i = 2; i < n; ++i) {
                    if (i < (i ^ full) && i != 3) {
                        cout << i << " " << (i ^ full) << "\n";
                    }
                }
            }
        }
    }
    return 0;
}