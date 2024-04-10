#include <bits/stdc++.h>

using namespace std;

int t, n, x;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> x;
        if (n <= 2) {
            cout << 1 << "\n";
        } else {
            n -= 3;
            cout << 2 + n / x << "\n";
        }
    }
    return 0;
}