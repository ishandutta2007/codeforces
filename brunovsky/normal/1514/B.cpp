#include <bits/stdc++.h>

using namespace std;

// *****

constexpr unsigned long long MOD = 1e9 + 7;

auto solve() {
    int N, K;
    cin >> N >> K;
    unsigned long long ans = 1;
    for (int i = 1; i <= K; i++)
        ans = ans * N % MOD;
    return ans;
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