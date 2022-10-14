#include <bits/stdc++.h>

using namespace std;

#define long int64_t
#define DV(a) (" [" #a "=" + to_string(a) + "]")

// *****

auto solve() {
    long A, B;
    cin >> A >> B;
    if (B == 1) {
        cout << "NO" << endl;
        return;
    } else if (B == 2) {
        // A, 3A, 4A
        long x = 3 * A, y = A, z = 2 * A * B;
        cout << "YES" << endl;
        cout << x << ' ' << y << ' ' << z << endl;
    } else {
        // A, A(B-1), AB
        long x = A * (B - 1), y = A, z = A * B;
        cout << "YES" << endl;
        cout << x << ' ' << y << ' ' << z << endl;
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