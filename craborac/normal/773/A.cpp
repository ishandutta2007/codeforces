#include <bits/stdc++.h>

using namespace std;

long long tc, x, y, p, q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> tc;
    for (int t = 0; t < tc; t++) {
        cin >> x >> y >> p >> q;
        long long k = 0;
        k = max(k, (y + q - 1) / q);
        if (q == p) {
            if (x == y) {
                cout << "0\n";
                continue;
            } else {
                cout << "-1\n";
                continue;
            }
        }
        if (p == 0) {
            if (x == 0) {
                cout << "0\n";
                continue;
            } else {
                cout << "-1\n";
                continue;
            }
        }
        k = max(k, (x + p - 1) / p);
        k = max(k, (y - x + q - p - 1) / (q - p));
        cout << k * q - y << "\n";
    }
}