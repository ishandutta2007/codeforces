#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N, K;
    string s;
    cin >> N >> K >> s;
    if (N <= 2 * K) {
        return "NO";
    }
    for (int i = 0; i < K; i++) {
        if (s[i] != s[N - i - 1]) {
            return "NO";
        }
    }
    return "YES";
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