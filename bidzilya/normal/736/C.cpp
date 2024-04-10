#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

inline void ModSum(int& x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
    if (x < 0) {
        x += MOD;
    }
}

inline int GetModSum(int x, int y) {
    ModSum(x, y);
    return x;
}

inline void ModMul(int& x, int y) {
    x = (1LL * x * y) % MOD;
}

inline int GetModMul(int x, int y) {
    ModMul(x, y);
    return x;
}

const int MAX_N = 100;
const int MAX_K = 20;

int n, k;
vector<vector<int>> g;

vector<int> height;

void BuildHeight(int v, int pr) {
    height[v] = 1;
    for (int u : g[v]) {
        if (u != pr) {
            BuildHeight(u, v);
            height[v] = max(height[v], height[u] + 1);
        }
    }
}

int dp[MAX_N][MAX_K + 2][MAX_N + 1];

int dp2[MAX_N + 1][MAX_N + 1];

void BuildDp(int v, int pr) {
    vector<int> childs;
    for (int u : g[v]) {
        if (u == pr) {
            continue;
        }
        childs.push_back(u);
        BuildDp(u, v);
    }
    const int m = childs.size();
    vector<int> childHeight(m + 1);
    childHeight[0] = 1;
    for (int i = 1; i <= m; ++i) {
        childHeight[i] = max(childHeight[i - 1], height[childs[i - 1]] + 1);
    }
    for (int distUp = 0; distUp <= k + 1; ++distUp) {
        for (int distDown = 0; distDown <= height[v]; ++distDown) {
            for (int black = 0; black < 2; ++black) {
                if (black && distDown != 0) {
                    continue;
                }

                int newDistUp = k + 1;
                if (distUp != k + 1) {
                    newDistUp = min(newDistUp, distUp + 1);
                }
                if (distDown != height[v]) {
                    newDistUp = min(newDistUp, distDown + 1);
                }
                newDistUp = min(newDistUp, k + 1);

                for (int i = 0; i <= m; ++i) {
                    for (int j = 0; j <= childHeight[i]; ++j) {
                        dp2[i][j] = 0;
                    }
                }
                dp2[0][childHeight[0]] = 1;
                for (int i = 0; i < m; ++i) {
                    for (int prevDistDown = 0; prevDistDown <= childHeight[i]; ++prevDistDown) {
                        for (int curDistDown = 0; curDistDown <= height[childs[i]]; ++curDistDown) {
                            int newDistDown;
                            if (prevDistDown == childHeight[i]) {
                                if (curDistDown == height[childs[i]]) {
                                    newDistDown = childHeight[i + 1];
                                } else {
                                    newDistDown = curDistDown + 1;
                                }
                            } else {
                                if (curDistDown == height[childs[i]]) {
                                    newDistDown = prevDistDown;
                                } else {
                                    newDistDown = min(prevDistDown, curDistDown + 1);
                                }
                            }

                            ModSum(dp2[i + 1][newDistDown], GetModMul(dp2[i][prevDistDown], dp[childs[i]][newDistUp][curDistDown]));
                        }
                    }
                }

                if (black) {
                    for (int dist = 0; dist <= height[v]; ++dist) {
                        ModSum(dp[v][distUp][distDown], dp2[m][dist]);
                    }
                } else {
                    if (distUp <= k || (distDown != height[v] && distDown <= k)) {
                        ModSum(dp[v][distUp][distDown], dp2[m][distDown]);
                    }
                }
            }
        }
    }
}

void Solve() {
    height.resize(n);
    BuildHeight(0, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k + 1; ++j) {
            for (int t = 0; t <= height[i]; ++t) {
                dp[i][j][t] = 0;
            }
        }
    }
    BuildDp(0, -1);
    int result = 0;
    for (int d = 0; d <= height[0]; ++d) {
        ModSum(result, dp[0][k + 1][d]);
    }
    cout << result << endl;
}

bool Read() {
    if (!(cin >> n >> k)) {
        return false;
    }
    g.clear();
    g.resize(n);
    for (int i = 0; i + 1 < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
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