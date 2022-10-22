#include <bits/stdc++.h>

const int MAXN = 300010;

int n;
int c[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", c + i);
    }
    if (c[1] != c[n]) {
        printf("%d\n", n - 1);
        return 0;
    }
    int ans = 0;
    for (int i = 2; i < n; ++i) {
        if (c[i] != c[n]) {
            ans = std::max(ans, std::max(n - i, i - 1));
        }
    }
    printf("%d\n", ans);
    return 0;
}