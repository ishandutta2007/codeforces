//
// Created by Junjie Wu on 2021/4/18.
//

#include <bits/stdc++.h>

const int N = 1e5 + 10;

using ll = long long;

int n;
ll k;

int a[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%lld", &n, &k);
        if (n < 63 && (1ll << (n - 1)) < k) {
            puts("-1");
            continue;
        }

        for (int i = 1; i <= n; ++i) {
            a[i] = i;
        }

        --k;
        std::vector<int> bits;
        while (k) {
            bits.push_back(k & 1);
            k >>= 1;
        }

        for (int i = 0, j; i < bits.size(); i = j) {
            for (j = i; j < bits.size() && bits[j] == bits[i]; ++j);
            // [i, j)
            // reverse [n - j, n - i]
            if (bits[i]) {
                std::reverse(a + n - j, 1 + a + n - i);
            }
        }

        for (int i = 1; i <= n; ++i) {
            printf("%d%c", a[i], " \n"[i == n]);
        }
    }
    return 0;
}