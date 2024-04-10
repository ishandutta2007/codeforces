#include <bits/stdc++.h>

using namespace std;

int t, a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << (abs(a - b) + 9) / 10 << "\n";
    }
    return 0;
}