#include <bits/stdc++.h>

using namespace std;

const int max_n = 200022, inf = 1000111222;

int t, n, a[max_n];
vector<int> all[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            --a[i];
            all[a[i]].push_back(i);
        }
        int ans = inf;
        for (int x = 0; x < n; ++x) {
            if (all[x].empty()) {
                continue;
            }
            int res = 0;
            for (int i = 0; i + 1 < all[x].size(); ++i) {
                res += (all[x][i] + 1) != all[x][i + 1];
            }
            res += all[x][0] != 0;
            res += (all[x].back() + 1) != n;
            ans = min(ans, res);
        }
        printf("%d\n", ans);
        for (int i = 0; i < n; ++i) {
            all[i].clear();
        }
    }
    return 0;
}