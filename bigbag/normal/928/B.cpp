#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, k, a[max_n], dp[max_n];

int get_l(int i) {
    return max(1, i - k);
}

int get_r(int i) {
    return min(n, i + k);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        int l = get_l(i);
        int r = get_r(i);
        dp[i] = dp[a[i]] + r - l + 1;
        if (a[i]) {
            dp[i] -= max(0, get_r(a[i]) - l + 1);
        }
        printf("%d ", dp[i]);
    }
    printf("\n");
    return 0;
}