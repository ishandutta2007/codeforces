#include <bits/stdc++.h>

using namespace std;

int q, x, y, z;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> q;
    while (q--) {
        cin >> x >> y >> z;
        cout << min({x, y, (x + y + z) / 3}) << "\n";
    }
    return 0;
}