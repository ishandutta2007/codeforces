#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int n, m, a[max_n][max_n];
vector<int> all[2][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
            all[0][i].push_back(a[i][j]);
            all[1][j].push_back(a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        sort(all[0][i].begin(), all[0][i].end());
        all[0][i].erase(unique(all[0][i].begin(), all[0][i].end()), all[0][i].end());
    }
    for (int i = 0; i < m; ++i) {
        sort(all[1][i].begin(), all[1][i].end());
        all[1][i].erase(unique(all[1][i].begin(), all[1][i].end()), all[1][i].end());
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = lower_bound(all[0][i].begin(), all[0][i].end(), a[i][j]) - all[0][i].begin();
            int y = lower_bound(all[1][j].begin(), all[1][j].end(), a[i][j]) - all[1][j].begin();
            int res = max(x, y);
            res += max(all[0][i].size() - x, all[1][j].size() - y);
            printf("%d ", res);
        }
        puts("");
    }
    return 0;
}