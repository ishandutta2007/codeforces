#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto solve() {
    long r, b, k;
    cin >> r >> b >> k;
    long g = gcd(r, b);
    if (r > (k - 1) * b + g || b > (k - 1) * r + g) {
        return false;
    } else {
        return true;
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << (solve() ? "OBEY" : "REBEL") << endl;
    }
    return 0;
}