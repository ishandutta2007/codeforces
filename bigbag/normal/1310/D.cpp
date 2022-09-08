#include <bits/stdc++.h>

using namespace std;

const int max_n = 88, inf = 1000111222;
const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 generator(seed);

double get_time() {
    return 1.0 * clock() / CLOCKS_PER_SEC;
}

bool is_tl() {
    static int cnt = 0;
    ++cnt;
    if (cnt == 10) {
        cnt = 0;
        return get_time() > 0.25;
    }
    return false;
}

int n, k, dist[max_n][max_n], f[max_n];
int dp[2][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }
    int ans = inf;
    while (!is_tl()) {
        for (int i = 0; i < n; ++i) {
            f[i] = generator() % 2;
        }
        int q1 = 0, q2 = 1;
        fill(dp[q1], dp[q1] + n, inf);
        dp[q1][0] = 0;
        for (int i = 0; i < k; ++i) {
            fill(dp[q2], dp[q2] + n, inf);
            for (int from = 0; from < n; ++from) {
                for (int to = 0; to < n; ++to) {
                    if (f[from] != f[to]) {
                        dp[q2][to] = min(dp[q2][to], dp[q1][from] + dist[from][to]);
                    }
                }
            }
            swap(q1, q2);
        }
        ans = min(ans, dp[q1][0]);
    }
    printf("%d\n", ans);
    return 0;
}