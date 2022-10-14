#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N;
    string S;
    cin >> N >> S;

    int T = 0, M = 0;
    for (int i = 0; i < N; i++) {
        T += S[i] == 'T';
        M += S[i] == 'M';
        if (M > T)
            return "NO";
    }
    T = 0, M = 0;
    for (int i = N - 1; i >= 0; i--) {
        T += S[i] == 'T';
        M += S[i] == 'M';
        if (M > T)
            return "NO";
    }
    if (2 * M != T)
        return "NO";

    return "YES";
}

// *****

int main() {
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}