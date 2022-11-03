#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    vector<int> minValue(n);
    for (int i = 0; i < n; ++i) {
        minValue[i] = a[i][0];
        for (int j = 1; j < m; ++j) {
            minValue[i] = min(minValue[i], a[i][j]);
        }
    }

    int maxValue = minValue[0];
    for (int i = 1; i < n; ++i) {
        maxValue = max(maxValue, minValue[i]);
    }

    cout << maxValue << endl;

    return 0;
}