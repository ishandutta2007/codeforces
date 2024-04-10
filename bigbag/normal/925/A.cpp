#include <bits/stdc++.h>

using namespace std;

const int max_n = 101111, inf = 1000111222;

int n, m, v[2], q;
int cnt[2], a[2][max_n];

int get(int x1, int y1, int x2, int y2, int y, int v) {
    if (y == -1 || y == inf) {
        return inf;
    }
    int res = abs(y1 - y) + abs(y2 - y) + (abs(x1 - x2) + v - 1) / v;
    //cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << y << " " << v << ": " << res << endl;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d%d", &n, &m, &cnt[0], &cnt[1], &v[1]);
    v[0] = 1;
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j <= cnt[i]; ++j) {
            scanf("%d", &a[i][j]);
        }
        a[i][0] = -1;
        a[i][cnt[i] + 1] = inf;
    }
    scanf("%d", &q);
    while (q--) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        --x1;
        --x2;
        if (x1 == x2) {
            printf("%d\n", abs(y1 - y2));
            continue;
        }
        int ans = inf;
        for (int tp = 0; tp < 2; ++tp) {
            if (cnt[tp]) {
                int pos = lower_bound(a[tp], a[tp] + cnt[tp] + 2, y1) - a[tp];
                ans = min(ans, get(x1, y1, x2, y2, a[tp][pos], v[tp]));
                ans = min(ans, get(x1, y1, x2, y2, a[tp][pos - 1], v[tp]));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}