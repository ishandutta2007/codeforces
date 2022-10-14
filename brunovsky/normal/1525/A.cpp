#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto solve() {
    int k;
    cin >> k;
    return 100 / gcd(k, 100);
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}