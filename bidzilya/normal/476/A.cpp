#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> result(n + 1, vector<int>(m, INF));

    result[0][0] = 0;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (result[i][j] == INF) {
                continue;
            }
            int nj = j + 1;
            if (nj == m) {
                nj = 0;
            }
            if (i + 1 <= n) {
                result[i + 1][nj] = min(result[i + 1][nj], result[i][j] + 1);
            }
            if (i + 2 <= n) {
                result[i + 2][nj] = min(result[i + 2][nj], result[i][j] + 1);
            }
        }
    }

    if (result[n][0] == INF) {
        cout << -1 << endl;
    } else {
        cout << result[n][0] << endl;
    }

    return 0;
}