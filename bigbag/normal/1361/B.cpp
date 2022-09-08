#include <bits/stdc++.h>

using namespace std;

const int max_n = 1001111, mod = 1000000007, inf = 1000111222;

int t, n, p, a[max_n];

template<bool use_mod = true>
int mul(int x, int y) {
    if (use_mod) {
        return 1LL * x * y % mod;
    }
    return min(1LL * x * y, 1LL * inf);
}

template<bool use_mod = true>
int power(int x, int y) {
    if (!y) {
        return 1;
    }
    if (y % 2 == 0) {
        return power<use_mod>(mul<use_mod>(x, x), y / 2);
    }
    return mul<use_mod>(x, power<use_mod>(x, y - 1));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &p);
        for (int i = 0; i < n; ++i) {
            int k;
            scanf("%d", &a[i]);
        }
        if (p == 1) {
            printf("%d\n", n % 2);
            continue;
        }
        sort(a, a + n);
        reverse(a, a + n);
        int cd = 0, last_k = inf;
        int ans = 0;
        bool sub = false;
        for (int i = 0; i < n; ) {
            const int st = i;
            while (i < n && a[st] == a[i]) {
                ++i;
            }
            const int k = a[st];
            int cnt = i - st;
            const int ncd = mul<false>(cd, power<false>(p, last_k - k));
            if (!sub && ncd == inf) {
                sub = true;
                ans = mul(cd, power(p, last_k));
            }
            if (sub) {
                ans += mod - mul(cnt, power(p, k));
                ans %= mod;
                continue;
            }
            cd = ncd;
            int mn = min(cd, cnt);
            cd -= mn;
            cnt -= mn;
            last_k = k;
            if (!cd) {
                cd = cnt % 2;
            }
        }
        if (sub) {
            printf("%d\n", ans);
        } else {
            printf("%d\n", mul(cd, power(p, last_k)));
        }
    }
    return 0;
}