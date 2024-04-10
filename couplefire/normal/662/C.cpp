#include<bits/stdc++.h>

using namespace std;

char s[100000];
int col[100000], dp[21][1 << 20];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf(" %s", s);

        for (int j = 0; j < m; j++) col[j] |= (s[j] - '0') << i;
    }

    for (int i = 0; i < m; i++) dp[0][col[i]]++;

    for (int k = 1; k <= n; k++)
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = k > 1 ? (k - 2 - n) * dp[k - 2][mask] : 0;
            for (int p = 0; p < n; p++) sum += dp[k - 1][mask ^ (1 << p)];

            dp[k][mask] = sum / k;
        }

    int ans = n * m;
    for (int mask = 0; mask < (1 << n); mask++) {
        int cnt = 0;
        for (int k = 0; k <= n; k++) cnt += min(k, n - k) * dp[k][mask];

        ans = min(ans, cnt);
    }

    printf("%d\n", ans);

    return 0;
}