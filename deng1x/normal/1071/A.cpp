#include <bits/stdc++.h>

#define ll long long

ll a, b;

int main() {
    scanf("%lld%lld", &a, &b);
    ll l = 0, r = 2 * (a + b), x;
    while (l <= r) {
        ll m = (l + r) >> 1;
        if (m * (m + 1) <= 2 * (a + b)) {
            x = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    std::vector<int> ans1, ans2;
    for (int i = x; i; --i) {
        if (a >= i) {
            a -= i;
            ans1.push_back(i);
        } else {
            if (a) ans1.push_back(a);
            for (; i; --i) {
                if (i == a) continue;
                ans2.push_back(i);
            }
            break;
        }
    }

    int n = (int)ans1.size(), m = (int)ans2.size();
    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%d%c", ans1[i], " \n"[i == n - 1]);
    }
    printf("%d\n", m);
    for (int i = 0; i < m; ++i) {
        printf("%d%c", ans2[i], " \n"[i == m - 1]);
    }
    return 0;
}