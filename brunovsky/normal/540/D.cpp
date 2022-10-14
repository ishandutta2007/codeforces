#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

constexpr int ROCK = 0, SCISS = 1, PAPER = 2;
double dp[101][101][101][3];

auto solve() {
    int R, S, P;
    cin >> R >> S >> P;
    dp[1][0][0][ROCK] = dp[0][1][0][SCISS] = dp[0][0][1][PAPER] = 1.0;

    for (int sum = 2; sum <= R + P + S; sum++) {
        for (int r = 0; r <= R; r++) {
            for (int s = 0; s <= S; s++) {
                int p = sum - r - s;
                if (0 <= p && p <= P) {
                    if (s == 0 && p == 0) {
                        dp[r][0][0][ROCK] = 1.0;
                    } else if (r == 0 && p == 0) {
                        dp[0][s][0][SCISS] = 1.0;
                    } else if (r == 0 && s == 0) {
                        dp[0][0][p][PAPER] = 1.0;
                    } else {
                        int dies[3] = {p * r, r * s, s * p};
                        int total = p * r + r * s + s * p;
                        for (int d : {ROCK, SCISS, PAPER}) { // which one dies
                            if (dies[d]) {
                                int mr = r - (r && d == ROCK);
                                int ms = s - (s && d == SCISS);
                                int mp = p - (p && d == PAPER);
                                double q = 1.0 * dies[d] / total;
                                for (int i : {ROCK, SCISS, PAPER}) {
                                    dp[r][s][p][i] += q * dp[mr][ms][mp][i];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    auto [r, s, p] = dp[R][S][P];
    cout << r << ' ' << s << ' ' << p << endl;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    solve();
    return 0;
}