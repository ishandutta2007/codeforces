#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n;
vector<int> v[2];

bool get_bit(int mask, int pos) {
    return (bool) (mask & (1 << pos));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int ans = 0;
        for (int i = 0; i < 9; ++i) {
            v[0].clear();
            v[1].clear();
            for (int j = 0; j < n; ++j) {
                v[get_bit(j, i)].push_back(j + 1);
            }
            if (v[0].empty() || v[1].empty()) {
                continue;
            }
            printf("%d %d ", v[0].size(), v[1].size());
            for (int x : v[0]) {
                printf("%d ", x);
            }
            for (int x : v[1]) {
                printf("%d ", x);
            }
            printf("\n");
            fflush(stdout);
            int res;
            scanf("%d", &res);
            ans = max(ans, res);
        }
        printf("-1 %d\n", ans);
        fflush(stdout);
    }
    return 0;
}