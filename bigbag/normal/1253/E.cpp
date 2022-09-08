#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, m, dp[2][max_n];
vector<pair<int, int>> v;

void clr(int q) {
    for (int i = 0; i < max_n; ++i) {
        dp[q][i] = inf;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    while (n--) {
        int x, s;
        scanf("%d%d", &x, &s);
        v.push_back({x - s, x + s});
    }
    sort(v.begin(), v.end());
    int q1 = 0, q2 = 1;
    clr(q1);
    dp[q1][0] = 0;
    for (int i = 0; i < v.size(); ++i) {
        copy(dp[q1], dp[q1] + m + 1, dp[q2]);
        for (int j = 0; j < m; ++j) {
            int l = v[i].first - j, r = min(m, v[i].second + j);
            dp[q2][r] = min(dp[q2][r], dp[q1][max(l - 1, 0)] + j);
        }
        for (int j = m - 1; j >= 0; --j) {
            dp[q2][j] = min(dp[q2][j], dp[q2][j + 1]);
        }
        swap(q1, q2);
    }
    printf("%d\n", dp[q1][m]);
    return 0;
}