#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int n, a[max_n];
long long sum;

long long solve(long long d) {
    long long res = 0, x = 0;
    for (int i = 0; i < n; ++i) {
        x += a[i];
        x %= d;
        res += min(x, d - x);
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if (sum <= 1) {
        puts("-1");
        return 0;
    }
    long long ans = 1e18;
    for (int d = 2; d < max_n; ++d) {
        if (sum % d == 0) {
            ans = min(ans, solve(d));
            while (sum % d == 0) {
                sum /= d;
            }
        }
    }
    if (sum > 1) {
        ans = min(ans, solve(sum));
    }
    printf("%I64d\n", ans);
    return 0;
}