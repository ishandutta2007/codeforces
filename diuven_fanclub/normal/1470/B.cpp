#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int D[1000005];

int main() {
    for (int i = 1; i <= 1000000; i++) {
        D[i] = i;
    }
    for (int i = 2; i <= 1000; i++) {
        if (D[i] != i) continue;
        int x = i * i;
        for (int j = x; j <= 1000000; j += x) {
            while (D[j] % x == 0) D[j] /= x;
        }
    }
    int t;
    scanf("%d", &t);
    for (int _t = 0; _t < t; _t++) {
        int n, q;
        scanf("%d", &n);
        map<int, int> cnt;
        for (int i = 1; i <= n; i++) {
            int a;
            scanf("%d", &a);
            cnt[D[a]]++;
        }
        int ans[2] = {};
        for (auto [i, j] : cnt) {
            ans[0] = max(ans[0], j);
            if (i == 1 || j % 2 == 0) ans[1] += j;
        }
        ans[1] = max(ans[0], ans[1]);
        scanf("%d", &q);
        for (int i = 1; i <= q; i++) {
            ll w;
            scanf("%lld", &w);
            printf("%d\n", ans[min(w, 1ll)]);
        }
    }
}