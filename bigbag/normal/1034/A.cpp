#include <bits/stdc++.h>

using namespace std;

const int max_n = 15000111, inf = 1000111222;

int n, x, cnt[max_n];
char f[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    int g;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        ++cnt[x];
        if (i == 0) {
            g = x;
        } else {
            g = __gcd(g, x);
        }
    }
    int ans = n;
    for (int y = g + 1; y < max_n; ++y) {
        if (f[y] == 0) {
            int c = n;
            for (int j = y; j < max_n; j += y) {
                c -= cnt[j];
                f[j] = 1;
            }
            ans = min(ans, c);
        }
    }
    if (ans == n) {
        ans = -1;
    }
    printf("%d\n", ans);
    return 0;
}