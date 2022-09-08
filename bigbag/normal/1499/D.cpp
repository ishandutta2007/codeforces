/**
 *  created: 18/03/2021, 17:10:28
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 20001112, inf = 1000111222;

int mn_d[max_n], diff_p[max_n];

void init() {
    mn_d[1] = 1;
    for (int i = 2; i < max_n; ++i) {
        if (!mn_d[i]) {
            mn_d[i] = i;
            if (1LL * i * i < max_n) {
                for (int j = 2 * i; j < max_n; j += i) {
                    if (!mn_d[j]) {
                        mn_d[j] = i;
                    }
                }
            }
        }
    }
    for (int i = 1; i < max_n; ++i) {
        int x = i;
        while (x > 1) {
            ++diff_p[i];
            int d = mn_d[x];
            while (x % d == 0) {
                x /= d;
            }
        }
        diff_p[i] = 1 << diff_p[i];
    }
}

int t, c, d, x;
long long ans;

void try_g(int g) {
    int y = x / g + d;
    if (y % c == 0) {
        int k = y / c;
        ans += diff_p[k];
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    init();
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &c, &d, &x);
        ans = 0;
        for (int i = 1; i * i <= x; ++i) {
            if (x % i == 0) {
                try_g(i);
                if (i * i != x) {
                    try_g(x / i);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}