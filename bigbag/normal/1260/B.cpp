#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        int x = b - a;
        a -= x;
        b -= 2 * x;
        if (a >= 0 && a % 3 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}