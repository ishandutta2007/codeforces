#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string GetS(int i, int j, const vector<vector<int>>& dpLen) {
    if (i == j) {
        return "()";
    } else {
        if (dpLen[i][j] == j) {
            return "(" + GetS(i + 1, j, dpLen) + ")";
        } else if (dpLen[i][j] == i) {
            return "()" + GetS(i + 1, j, dpLen);
        } else {
            return "(" + GetS(i + 1, dpLen[i][j], dpLen) + ")" + GetS(dpLen[i][j] + 1, j, dpLen);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    vector<vector<int>> dpLen(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i) {
        if (a[i].first == 1) {
            dpLen[i][i] = i;
        }
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            const int j = i + len - 1;
            for (int t = i; t <= j; ++t) {
                int dist = (t - i) * 2 + 1;

                if (dist >= a[i].first && dist <= a[i].second &&
                    (t == i || dpLen[i + 1][t] != -1) &&
                    (t == j || dpLen[t + 1][j] != -1))
                {
                    dpLen[i][j] = t;
                    break;
                }
            }
        }
    }

    if (dpLen[0][n - 1] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << GetS(0, n - 1, dpLen) << endl;
    }

    return 0;
}