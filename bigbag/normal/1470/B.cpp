/**
 *  created: 05/01/2021, 16:55:12
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;
const int max_x = 1001111;

int t, n, q, a[max_n], d[max_x], ans[2];

void init() {
    for (int i = 2; i < max_x; ++i) {
        if (!d[i]) {
            d[i] = i;
            if (1LL * i * i < max_x) {
                for (int j = i * i; j < max_x; j += i) {
                    if (!d[j]) {
                        d[j] = i;
                    }
                }
            }
        }
    }
}

int upd(int x) {
    int y = 1;
    while (x > 1) {
        int cnt = 0, cur_d = d[x];
        while (cur_d == d[x]) {
            ++cnt;
            x /= d[x];
        }
        if (cnt % 2) {
            y *= cur_d;
        }
    }
    return y;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    init();
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            a[i] = upd(a[i]);
        }
        sort(a, a + n);
        int mx = 0;
        ans[0] = ans[1] = 0;
        for (int i = 0; i < n; ) {
            int pos = i;
            while (i < n && a[pos] == a[i]) {
                ++i;
            }
            int cnt = i - pos;
            ans[0] = max(ans[0], cnt);
            if (cnt % 2 == 0 || a[pos] == 1) {
                ans[1] += cnt;
            } else {
                mx = max(mx, cnt);
            }
        }
        ans[1] = max(ans[1], mx);
        int q;
        scanf("%d", &q);
        while (q--) {
            long long w;
            scanf("%I64d", &w);
            w = min(w, 1LL);
            printf("%d\n", ans[w]);
        }
    }
    return 0;
}