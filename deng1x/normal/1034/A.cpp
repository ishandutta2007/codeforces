#include <bits/stdc++.h>

#define N (15000010)
#define MAXN (300010)

int n;
int a[MAXN];
int min[N];
std::vector<int> prime;
int cnt[N];

int main() {
    for (int i = 2; i < N; ++i) {
        if (!min[i]) {
            min[i] = i;
            prime.push_back(i);
        }
        for (int j = 0, sz = (int)prime.size(); j < sz && i * prime[j] < N; ++j) {
            min[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) {
                break;
            }
        }
    }

    scanf("%d", &n);
    int gcd = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        gcd = std::__gcd(gcd, a[i]);
    }
    for (int i = 1, j; i <= n; ++i) {
        int d = a[i] / gcd;
        while (d != 1) {
            ++cnt[j = min[d]];
            while (d % j == 0) d /= j;
        }
    }
    int ans = n;
    for (auto &p : prime) {
        ans = std::min(ans, n - cnt[p]);
    }
    printf("%d\n", ans == n ? -1 : ans);
    return 0;
}