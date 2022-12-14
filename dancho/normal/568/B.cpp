#include <cstdio>
#include <cstring>

const int mod = 1000000007;

long long com[4020][4020];

int n;

long long b[4020];

int main() {
    memset(com, 0, sizeof(com));
    for (int i = 0; i <= 4010; ++i) {
        com[i][0] = 1;
    }
    for (int i = 1; i <= 4010; ++i) {
        for (int j = 1; j <= i; ++j) {
            com[i][j] = com[i - 1][j] + com[i - 1][j - 1];
            if (com[i][j] >= mod) {
                com[i][j] %= mod;
            }
        }
    }

    scanf("%d", &n);

    b[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i] = b[i] + com[i - 1][j] * b[j];
            if (b[i] >= mod) {
                b[i] %= mod;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += com[n][i] * b[i];
        if (ans >= mod) {
            ans %= mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}