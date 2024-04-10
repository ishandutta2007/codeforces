#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011111, mod = 1000000007;

int n, a[max_n], sum[max_n], sum_sq[max_n], cnt[max_n], pw[max_n];
int z[max_n], g[max_n], res[max_n];

bool get_bit(int mask, int pos) {
    return (bool) (mask & (1 << pos));
}

void prec() {
    pw[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw[i] = (1LL * pw[i - 1] * 2) % mod;
    }
    for (int i = 0; i < (1 << 6); ++i) {
        int cnt = 0;
        for (int j = 0; j < 6; ++j) {
            if (get_bit(i, j)) {
                ++cnt;
            }
        }
        if (cnt % 2 == 1) {
            z[i] = 1;
        } else {
            z[i] = -1;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum[a[i]] += a[i];
        sum[a[i]] %= mod;
        sum_sq[a[i]] += (1LL * a[i] * a[i]) % mod;
        sum_sq[a[i]] %= mod;
        ++cnt[a[i]];
    }
    prec();
    for (int i = 999999; i >= 0; --i) {
        int x = i;
        int a[6];
        for (int j = 5; j >= 0; --j) {
            a[j] = x % 10;
            x /= 10;
        }
        for (int mask = 1; mask < (1 << 6); ++mask) {
            int x = 0;
            for (int j = 0; j < 6; ++j) {
                x = x * 10 + a[j];
                if (get_bit(mask, j)) {
                    if (a[j] == 9) {
                        x = -1;
                        break;
                    }
                    ++x;
                }
            }
            if (x == -1) {
                continue;
            }
            if (z[mask] == 1) {
                sum[i] += sum[x];
                sum[i] %= mod;
                sum_sq[i] += sum_sq[x];
                sum_sq[i] %= mod;
                cnt[i] += cnt[x];
            } else {
                sum[i] += mod - sum[x];
                sum[i] %= mod;
                sum_sq[i] += mod - sum_sq[x];
                sum_sq[i] %= mod;
                cnt[i] -= cnt[x];
            }
        }
        if (cnt[i] == 0) {
        } else if (cnt[i] == 1) {
            res[i] = sum_sq[i];
        } else {
            res[i] = (1LL * pw[cnt[i] - 2] * ((1LL * sum[i] * sum[i] + sum_sq[i]) % mod)) % mod;
        }
        g[i] = res[i];
        for (int mask = 1; mask < (1 << 6); ++mask) {
            int x = 0;
            for (int j = 0; j < 6; ++j) {
                x = x * 10 + a[j];
                if (get_bit(mask, j)) {
                    if (a[j] == 9) {
                        x = -1;
                        break;
                    }
                    ++x;
                }
            }
            if (x == -1) {
                continue;
            }
            if (z[mask] == 1) {
                g[i] += mod - res[x];
                g[i] %= mod;
            } else {
                g[i] += res[x];
                g[i] %= mod;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < 1000000; ++i) {
        ans ^= (1LL * i * g[i]);
    }
    printf("%I64d\n", ans);
    return 0;
}