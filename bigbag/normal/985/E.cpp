#include <bits/stdc++.h>

using namespace std;

const int max_n = 505555, inf = 1000111222;

int n, k, d, a[max_n], dp[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &k, &d);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int last = 0;
    dp[0] = 1;
    for (int i = k; i <= n; ++i) {
        if (a[i] - a[last + 1] <= d) {
            dp[i] = 1;
        }
        if (dp[i - k + 1]) {
            last = i - k + 1;
        }
    }
    if (dp[n]) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}