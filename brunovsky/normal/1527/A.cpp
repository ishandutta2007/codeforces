#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto solve() {
    long N;
    cin >> N;
    long Q = 1;
    while (2 * Q <= N) {
        Q <<= 1;
    }
    return Q - 1;
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