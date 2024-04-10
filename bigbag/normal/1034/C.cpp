#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, mod = 1000000007;

int n, a[max_n], p[max_n];
int cnt[max_n], tot[max_n], f[max_n], dp[max_n];
long long sum[max_n];

void add(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum[i] = a[i];
    }
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &p[i]);
    }
    for (int i = n; i >= 1; --i) {
        sum[p[i]] += sum[i];
    }
    for (int i = 1; i <= n; ++i) {
        long long g = __gcd(sum[1], sum[i]);
        long long s = sum[1] / g;
        if (s <= n) {
            ++cnt[s];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            tot[j] += cnt[i];
        }
    }
    for (int cnt = 1; cnt <= n; ++cnt) {
        if (sum[1] % cnt == 0 && tot[cnt] == cnt) {
            f[cnt] = 1;
        }
    }
    dp[1] = 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        add(ans, dp[i]);
        for (int j = 2 * i; j <= n; j += i) {
            if (f[j]) {
                add(dp[j], dp[i]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}