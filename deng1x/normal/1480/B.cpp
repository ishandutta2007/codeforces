//
// Created by Junjie Wu on 2021/2/20.
//

#include <bits/stdc++.h>

const int N = 1e5 + 10;
using ll = long long;

ll A, B;
int n;
std::pair<int, int> p[N];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld%d", &A, &B, &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &p[i].first);
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &p[i].second);
        }
        std::sort(p + 1, n + p + 1);
        for (int i = 1; i < n; ++i) {
            ll times = (p[i].second + A - 1) / A;
            B -= times * p[i].first;
            if (B <= 0) break;
        }
        if (B <= 0) {
            puts("NO");
            continue;
        }
        ll times = (p[n].second + A - 1) / A - 1;
        B -= times * p[n].first;
        puts(B > 0 ? "YES": "NO");
    }
    return 0;
}