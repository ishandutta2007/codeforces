/**
 *  created: 02/05/2021, 17:55:07
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, L, R, a[max_n];
int cnt[2][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &L, &R);
        fill(cnt[0], cnt[0] + n, 0);
        fill(cnt[1], cnt[1] + n, 0);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            --a[i];
            ++cnt[(i < L)][a[i]];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int x = min(cnt[0][i], cnt[1][i]);
            cnt[0][i] -= x;
            cnt[1][i] -= x;
        }
        int tp1 = 0, tp2 = 1;
        int tot1 = accumulate(cnt[0], cnt[0] + n, 0);
        int tot2 = accumulate(cnt[1], cnt[1] + n, 0);
        if (tot1 < tot2) {
            swap(tot1, tot2);
            swap(tp1, tp2);
        }
        int eq1 = 0, eq2 = 0;
        for (int i = 0; i < n; ++i) {
            eq1 += cnt[tp1][i] / 2;
            eq2 += cnt[tp2][i] / 2;
        }
        while (tot1 > tot2 && eq1) {
            tot1 -= 2;
            --eq1;
            ++ans;
        }
        ans += (tot1 - tot2);
        ans += tot2;
        printf("%d\n", ans);
    }
    return 0;
}