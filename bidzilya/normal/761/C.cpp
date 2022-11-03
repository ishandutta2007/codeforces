#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1e9;

int n, m;
vector<string> a;

inline int GetDist(int from, int to) {
    int d = from - to;
    if (d < 0) {
        d += m;
    }
    return min(d, m - d);
}

vector<vector<int>> dp;

inline int GetMask(char c) {
    if (isdigit(c)) {
        return (1 << 0);
    } else if (c == '#' || c == '&' || c == '*') {
        return (1 << 1);
    } else {
        return (1 << 2);
    }
}

void Solve() {
    dp.assign(n + 1, vector<int>(1 << 3, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int mask = 0; mask < (1 << 3); ++mask) {
            if (dp[i][mask] == INF) {
                continue;
            }
            for (int j = 0; j < m; ++j) {
                const int cost = dp[i][mask] + GetDist(0, j);
                const int newMask = (mask | GetMask(a[i][j]));

                dp[i + 1][newMask] = min(dp[i + 1][newMask], cost);
            }
        }
    }

    cout << dp[n][(1 << 3) - 1] << endl;
}

bool Read() {
    if (!(cin >> n >> m)) {
        return false;
    }
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}