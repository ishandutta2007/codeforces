#include <bits/stdc++.h>

using namespace std;

int t;
long long a, b, c;

int main() {
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        if (a < c) {
            cout << 1 << " ";
        } else {
            cout << -1 << " ";
        }
        if (c < a * b) {
            cout << b << "\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}