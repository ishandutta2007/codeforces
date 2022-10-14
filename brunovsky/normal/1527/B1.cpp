#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

int dp[1001][1001][2][2];
// dp[a][b][c][d]: our expense - their expense, we want to minimize
// a = 0/0
// b = 0/1
// c = central 0
// d = can flip

void setmin(int& a, int b) { a = min(a, b); }

void setup_dp() {
    dp[0][0][1][0] = dp[0][0][1][1] = 1;
    for (int sum = 1; sum <= 1000; sum++) {
        for (int a = 0; a <= sum; a++) {
            int b = sum - a;
            assert(0 <= b && b <= 1000);
            for (int c : {0, 1}) {
                for (int d : {0, 1}) {
                    dp[a][b][c][d] = 10000;
                    if (a > 0) {
                        assert(b < 1000);
                        // we can pay 1 and give dp[a-1][b+1][c][1] to opponent
                        setmin(dp[a][b][c][d], 1 - dp[a - 1][b + 1][c][1]);
                    }
                    if (b > 0) {
                        // we can pay 1 and give dp[a][b-1][c][1] to opponent
                        setmin(dp[a][b][c][d], 1 - dp[a][b - 1][c][1]);
                    }
                    if (c > 0) {
                        // we can pay 1 and give dp[a][b][0][1] to opponent
                        setmin(dp[a][b][c][d], 1 - dp[a][b][0][1]);
                    }
                    if (d == 1 && b > 0) {
                        // we can flip
                        setmin(dp[a][b][c][d], -dp[a][b][c][0]);
                    }
                }
            }
        }
    }
}

auto solve() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    int A = 0, B = 0;
    for (int i = 0; i < N / 2; i++) {
        if (s[i] == '0' && s[N - i - 1] == '0') {
            A++;
        } else if (s[i] != s[N - i - 1]) {
            B++;
        }
    }
    int C = N % 2 == 1 && s[N / 2] == '0';
    int ans = dp[A][B][C][1];
    fprintf(stderr, "A=%d B=%d C=%d [ans=%d] [without=%d]\n", A, B, C, ans,
            dp[A][B][C][0]);
    if (ans > 0) {
        return "BOB";
    } else if (ans == 0) {
        return "DRAW";
    } else {
        return "ALICE";
    }
}

// *****

int main() {
    setup_dp();
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}