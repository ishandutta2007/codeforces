#include<bits/stdc++.h>
#define int long long
const int maxn = 1e3 + 10, P = 1e9 + 7;
int n, f[maxn][maxn];
signed main() {
    scanf("%lld", &n);
    f[1][1] = f[1][0] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; j + k <= n; k++) {
                int t = f[i - 1][j] * f[i - 1][k] % P;
                f[i][j + k] = (f[i][j + k] + t % P) % P;
                f[i][j + k] = (f[i][j + k] + t * ((j + k) * 2) % P) % P;
                f[i][j + k - 1] = (f[i][j + k - 1] + t * (j + k) % P * (j + k - 1) % P) % P;
                f[i][j + k + 1] = (f[i][j + k + 1] + t) % P;
            }
    printf("%lld\n", f[n][1]);
    return 0;
}