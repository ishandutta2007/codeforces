#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto solve() {
    int N;
    long K;
    cin >> N >> K;
    vector<long> x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
    bool found = x[0] == K;
    long g = 0;
    for (int i = 1; i < N; i++) {
        g = gcd(g, x[i] - x[0]);
        found |= x[i] == K;
    }
    return (!found && (!g || (K - x[0]) % g)) ? "NO" : "YES";
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