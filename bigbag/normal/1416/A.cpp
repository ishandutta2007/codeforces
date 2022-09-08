#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int t, n, a[max_n], ans[max_n];
vector<int> all[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            all[i + 1].push_back(-1);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            all[a[i]].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            all[i + 1].push_back(n);
        }
        for (int i = 1; i <= n; ++i) {
            ans[i] = inf;
        }
        for (int i = 1; i <= n; ++i) {
            int d = 0;
            for (int j = 0; j + 1 < all[i].size(); ++j) {
                d = max(d, all[i][j + 1] - all[i][j]);
            }
            ans[d] = min(ans[d], i);
        }
        for (int i = 2; i <= n; ++i) {
            ans[i] = min(ans[i], ans[i - 1]);
        }
        for (int i = 1; i <= n; ++i) {
            if (ans[i] == inf) {
                ans[i] = -1;
            }
            printf("%d ", ans[i]);
            all[i].clear();
        }
        puts("");
    }
    return 0;
}