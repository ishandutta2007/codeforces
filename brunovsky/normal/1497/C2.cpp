#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int n, k;
    cin >> n >> k;
    while (k > 3) {
        cout << 1 << ' ';
        k--, n--;
    }
    if (n & 1) {
        int a = n / 2, b = n / 2, c = 1;
        assert(a + b + c == n);
        cout << a << ' ' << b << ' ' << c << endl;
    } else if (n % 4 == 0) {
        int a = n / 2, b = n / 4, c = n / 4;
        assert(a + b + c == n);
        cout << a << ' ' << b << ' ' << c << endl;
    } else {
        int a = n / 2 - 1, b = n / 2 - 1, c = 2;
        assert(a + b + c == n);
        cout << a << ' ' << b << ' ' << c << endl;
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        solve();
    }
    return 0;
}