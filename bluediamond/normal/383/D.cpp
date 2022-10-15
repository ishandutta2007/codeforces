#include <cstdio>

using namespace std;

const int MOD = 1000000007;

int n, x, DP[1005][20005], ans=0;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        for (int j = 0; j <= 20000; j++) {
            if (!DP[i - 1][j]) continue;
            DP[i][j+x] += DP[i-1][j], DP[i][j+x] %= MOD;
            DP[i][j-x] += DP[i-1][j], DP[i][j-x] %= MOD;
        }
        DP[i][10000-x]++, DP[i][10000+x]++;
        ans += DP[i][10000];
        ans %= MOD;
    }
    printf("%d\n",ans);
}