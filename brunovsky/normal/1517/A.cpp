#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto solve() {
    long n;
    cin >> n;
    if (n % 2050 != 0) {
        return -1;
    }
    string s = to_string(n / 2050);
    int k = 0;
    for (int i = 0, S = s.size(); i < S; i++) {
        k += s[i] - '0';
    }
    return k;
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