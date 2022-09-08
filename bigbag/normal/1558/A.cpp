/**
 *  created: 24/08/2021, 17:35:57
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &a, &b);
        int n = a + b;
        vector<int> ok(n + 1);
        for (int it = 0; it < 2; ++it) {
            int cnt = (n + 1) / 2;
            for (int c = 0; c <= cnt && c <= a; ++c) {
                if (a - c <= n - cnt) {
                    ok[cnt - c + a - c] = 1;
                }
            }
            swap(a, b);
        }
        vector<int> ans;
        for (int i = 0; i <= n; ++i) {
            if (ok[i]) {
                ans.push_back(i);
            }
        }
        printf("%d\n", ans.size());
        for (int x : ans) {
            printf("%d ", x);
        }
        puts("");
    }
    return 0;
}