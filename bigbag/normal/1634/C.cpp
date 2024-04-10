/**
 *  created: 06/02/2022, 16:48:46
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
        if (k == 1) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                cout << i + 1 << "\n";
            }
        } else if (n % 2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int odd = 1, even = 2;
            for (int i = 0; i < n; ++i) {
                if (odd <= n * k) {
                    for (int j = 0; j < k; ++j) {
                        cout << odd << " ";
                        odd += 2;
                    }
                } else {
                    for (int j = 0; j < k; ++j) {
                        cout << even << " ";
                        even += 2;
                    }
                }
                cout << "\n";
            }
        }
    }
    return 0;
}