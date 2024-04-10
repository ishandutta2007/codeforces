#include <cstdio>
#include <algorithm>

const int N = 1e3 + 5;
const int MOD = 998244353;

int n, k, a[N], p[N], f[N][N], sum[N][N];

void add(int &x, int y) {
    (x += y) >= MOD && (x -= MOD);
}
int solve(int x) {
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            f[i][j] = sum[i][j] = 0;
        }
    }
    for (int i = 1, j = 0; i <= n; i++) {
        for (; a[i] - a[j + 1] >= x; j++);
        p[i] = j;
    }
    f[0][0] = 1;
    std::fill(sum[0], sum[0] + n + 1, 1);
    for (int i = 1; i <= k; i++) {
        for (int j = i; j <= n; j++) {
            f[i][j] = sum[i - 1][p[j]];
            sum[i][j] = f[i][j];
        }
        for (int j = i; j <= n; j++) {
            add(sum[i][j], sum[i][j - 1]);
        }
    }
    return sum[k][n];
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    std::sort(a + 1, a + n + 1);
    int ans = 0;
    for (int t = a[n], i = 1; i * (k - 1) <= t; i++) add(ans, solve(i));
    printf("%d\n", ans);
    return 0;
}