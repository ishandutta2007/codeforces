#include <bits/stdc++.h>

using namespace std;

int t, n, x, y;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n / 2; ++i) {
            cin >> x >> y;
            cout << -y << " " << x << " ";
        }
        cout << "\n";
    }
    return 0;
}