#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto solve() {
    int r, b, d;
    cin >> r >> b >> d;
    if (1LL * min(r, b) * (d + 1) < max(r, b))
        return "NO"s;
    else
        return "YES"s;
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