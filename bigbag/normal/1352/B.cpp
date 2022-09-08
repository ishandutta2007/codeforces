#include <bits/stdc++.h>

using namespace std;

int t, n, k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (n >= k && (n - (k - 1)) % 2) {
            cout << "YES\n";
            for (int i = 0; i + 1 < k; ++i) {
                cout << 1 << " ";
            }
            cout << n - (k - 1) << "\n";
        } else if (n >= 2 * k && (n - 2 * k) % 2 == 0) {
            cout << "YES\n";
            for (int i = 0; i + 1 < k; ++i) {
                cout << 2 << " ";
            }
            cout << n - 2 * (k - 1) << "\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}