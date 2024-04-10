#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int c[512];

int dp[512][512];

int go(int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == r) {
        return 1;
    }
    if (dp[l][r] != -1) {
        return dp[l][r];
    }

    int sl = r - l + 1;
    for (int i = l; i <= r; ++i) {
        if (c[i] == c[l]) {
            if (i == l) {
                sl = min(sl, 1 + go(l + 1, r));
            } else if (i == l + 1) {
                sl = min(sl, 1 + go(l + 2, r));
            } else {
                sl = min(sl, go(l + 1, i - 1) + go(i + 1, r));
            }
        }
    }
    dp[l][r] = sl;
    return dp[l][r];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
    }

    memset(dp, -1, sizeof(dp));
    printf("%d\n", go(0, n - 1));
    return 0;
}