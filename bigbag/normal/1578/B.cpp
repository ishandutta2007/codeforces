/**
 *  created: 13/10/2021, 17:35:21
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, a[3];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> a[0] >> a[1] >> a[2];
        for (int i = 0; i < 3; ++i) {
            int mx = 0;
            for (int j = 0; j < 3; ++j) {
                if (i != j) {
                    mx = max(mx, a[j]);
                }
            }
            cout << max(0, mx + 1 - a[i]) << " ";
        }
        cout << "\n";
    }
    return 0;
}