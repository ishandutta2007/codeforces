#include <bits/stdc++.h>

using namespace std;

// *****

constexpr int MAXM = 200'100;
constexpr unsigned MOD = 1e9 + 7;
unsigned dp[MAXM];

void setup() {
    for (int m = 0; m < 10; m++) {
        dp[m] = 1;
    }
    for (int m = 10; m < MAXM; m++) {
        dp[m] = (dp[m - 10] + dp[m - 9]) % MOD;
    }
}

auto solve() {
    int n, m;
    cin >> n >> m;
    string N = to_string(n);
    unsigned ans = 0;
    for (char c : N) {
        ans = (ans + dp[m + c - '0']) % MOD;
    }
    return ans;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    setup();
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << '\n';
    }
    return 0;
}