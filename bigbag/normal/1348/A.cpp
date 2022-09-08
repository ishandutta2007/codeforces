#include <bits/stdc++.h>

using namespace std;

int t, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int x = 0, y = 0;
        for (int i = 1; i < n / 2; ++i) {
            x += 1 << i;
        }
        x += 1 << n;
        y = (1LL << (n + 1)) - 2 - x;
        cout << x - y << endl;
    }
    return 0;
}