#include <bits/stdc++.h>

using namespace std;

// *****

#define MAXN 502
uint64_t cost[MAXN][MAXN][2]; // 1=vertical,0=horizontal
uint64_t dp[MAXN][MAXN][11];

#define min4(a, b, c, d) min(min(a, b), min(c, d))

auto solve() {
    int N, M, K;
    cin >> N >> M >> K;
    if (K % 2 == 1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << (j ? " " : "") << -1;
            }
            cout << endl;
        }
        return;
    }

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            cost[i][j][0] = cost[i][j][1] = UINT64_MAX / 4;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < M; j++) {
            cin >> cost[i][j][0];
        }
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> cost[i][j][1];
        }
    }

    memset(dp, 0x7f, sizeof(dp));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j][0] = 0;
        }
    }

    int cur = 0, nxt = 1;
    for (int D = 1; D <= K / 2; D++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                dp[i][j][nxt] = min4(dp[i - 1][j][cur] + 2 * cost[i - 1][j][1],
                                     dp[i + 1][j][cur] + 2 * cost[i][j][1],
                                     dp[i][j - 1][cur] + 2 * cost[i][j - 1][0],
                                     dp[i][j + 1][cur] + 2 * cost[i][j][0]);
            }
        }
        swap(cur, nxt);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << (j > 1 ? " " : "") << dp[i][j][cur];
        }
        cout << endl;
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}