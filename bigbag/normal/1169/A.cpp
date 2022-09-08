#include <bits/stdc++.h>

using namespace std;

int n, a, x, b, y;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> a >> x >> b >> y;
    --a;
    --x;
    --b;
    --y;
    while (true) {
        if (a == b) {
            cout << "YES" << endl;
            return 0;
        }
        if (a == x || b == y) {
            cout << "NO" << endl;
            return 0;
        }
        a += 1;
        a %= n;
        b += n - 1;
        b %= n;
    }
    return 0;
}