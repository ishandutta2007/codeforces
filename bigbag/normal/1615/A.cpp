/**
 *  created: 24/12/2021, 16:35:32
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

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
        }
        if (accumulate(a, a + n, 0LL) % n == 0) {
            cout << 0 << "\n";
        } else {
            cout << 1 << "\n";
        }
    }
    return 0;
}