#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int n, a[max_n], b[max_n], c[max_n];
long long ans, sum;

bool check(long long x) {
    for (int i = n - 1; i >= 0; --i) {
        long long cur = min((long long) a[i] / 2, x);
        x -= cur;
        b[i] = cur;
        c[i] = a[i] - 2 * cur;
    }
    if (x) {
        return false;
    }
    long long need = 0;
    for (int i = n - 1; i >= 0; --i) {
        need += b[i];
        need -= c[i];
        need = max(need, 0LL);
    }
    return need == 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    long long l = 0, r = 1LL * max_n * inf;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%I64d\n", l);
    return 0;
}