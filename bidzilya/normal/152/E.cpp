#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const char EMPTY = '.';
const char BLOCKED = 'X';

const int INF = 1e9;

const int DX[4] = {-1, 0, 0, 1};
const int DY[4] = {0, -1, 1, 0};

int n, m;

template <typename TGetMinDistPathFunction>
void FillTable(int mask, int vertex, vector<vector<char>>& table,
    const vector<vector<int>>& prMask, const vector<vector<int>>& prVertex, TGetMinDistPathFunction getMinDistPathFunc)
{
    if (prMask[mask][vertex] == -1 && prVertex[mask][vertex] == -1) {
        table[vertex / m][vertex % m] = BLOCKED;
    } else if (prMask[mask][vertex] != -1) {
        FillTable(prMask[mask][vertex], vertex, table, prMask, prVertex, getMinDistPathFunc);
        FillTable(mask - prMask[mask][vertex], vertex, table, prMask, prVertex, getMinDistPathFunc);
    } else {
        vector<int> path = getMinDistPathFunc(vertex, prVertex[mask][vertex]);
        for (int x : path) {
            table[x / m][x % m] = BLOCKED;
        }
        FillTable(mask, prVertex[mask][vertex], table, prMask, prVertex, getMinDistPathFunc);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> n >> m >> k;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> id(n, vector<int>(m, -1));
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        id[x][y] = i;
    }

    vector<vector<int>> minDist(n * m, vector<int>(n * m, INF));
    vector<vector<int>> pr(n * m, vector<int>(n * m));
    for (int i = 0; i < n * m; ++i) {
        minDist[i][i] = 0;
    }
    for (int i = 0; i < n * m; ++i) {
        int x = i / m;
        int y = i % m;

        for (int k = 0; k < 4; ++k) {
            int nx = x + DX[k];
            int ny = y + DY[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                minDist[i][nx * m + ny] = a[x][y];
                pr[i][nx * m + ny] = i;
            }
        }
    }

    for (int k = 0; k < n * m; ++k) {
        for (int i = 0; i < n * m; ++i) {
            for (int j = 0; j < n * m; ++j) {
                if (minDist[i][k] + minDist[k][j] < minDist[i][j]) {
                    minDist[i][j] = minDist[i][k] + minDist[k][j];
                    pr[i][j] = pr[k][j];
                }
            }
        }
    }

    auto getMinDistPath = [&minDist, &pr] (int v, int u) {
        vector<int> result;
        while (u != v) {
            result.push_back(u);
            u = pr[v][u];
        }
        result.push_back(v);
        return result;
    };

    vector<vector<int>> dp(1 << k, vector<int>(n * m, INF));
    vector<vector<int>> prMask(1 << k, vector<int>(n * m));
    vector<vector<int>> prVertex(1 << k, vector<int>(n * m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (id[i][j] == -1) {
                dp[0][i * m + j] = a[i][j];
                prMask[0][i * m + j] = -1;
                prVertex[0][i * m + j] = -1;
            } else {
                dp[1 << id[i][j]][i * m + j] = a[i][j];
                prMask[1 << id[i][j]][i * m + j] = -1;
                prVertex[1 << id[i][j]][i * m + j] = -1;
            }
        }
    }

    for (int mask = 0; mask < (1 << k); ++mask) {
        for (int i = 0; i < n * m; ++i) {
            for (int subMask = mask; subMask > 0; subMask = (subMask - 1) & mask) {
                int newValue = dp[subMask][i] + dp[mask - subMask][i] - a[i / m][i % m];
                if (newValue < dp[mask][i]) {
                    dp[mask][i] = newValue;
                    prMask[mask][i] = subMask;
                    prVertex[mask][i] = -1;
                }
            }
        }

        for (int v = 0; v < n * m; ++v) {
            for (int u = 0; u < n * m; ++u) {
                if (dp[mask][u] + minDist[v][u] < dp[mask][v]) {
                    dp[mask][v] = dp[mask][u] + minDist[v][u];
                    prMask[mask][v] = -1;
                    prVertex[mask][v] = u;
                }
            }
        }
    }

    int result = INF;
    int resultMask = (1 << k) - 1;
    int resultVertex;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dp[resultMask][i * m + j] < result) {
                result = dp[resultMask][i * m + j];
                resultVertex = i * m + j;
            }
        }
    }

    cout << result << endl;

    vector<vector<char>> table(n, vector<char>(m, EMPTY));

    FillTable(resultMask, resultVertex, table, prMask, prVertex, getMinDistPath);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << table[i][j];
        }
        cout << endl;
    }

    return 0;
}