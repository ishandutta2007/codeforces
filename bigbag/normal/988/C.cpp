#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, sd = 22222, inf = 1000111222;

int n, used[max_n], cur;
vector<int> a[max_n];
map<int, pair<int, int>> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int sz;
        scanf("%d", &sz);
        a[i].resize(sz);
        int sum = 0;
        for (int j = 0; j < sz; ++j) {
            scanf("%d", &a[i][j]);
            sum += a[i][j];
        }
        ++cur;
        for (int j = 0; j < sz; ++j) {
            if (used[a[i][j] + sd] == cur) {
                continue;
            }
            used[a[i][j] + sd] = cur;
            if (q.count(sum - a[i][j])) {
                printf("YES\n%d %d\n%d %d\n", q[sum - a[i][j]].first, q[sum - a[i][j]].second, i + 1, j + 1);
                return 0;
            }
            q[sum - a[i][j]] = make_pair(i + 1, j + 1);
        }
    }
    printf("NO\n");
    return 0;
}