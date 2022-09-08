#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n];
long long sum[max_n];

void calc() {
    for (int i = 1; i < n; ++i) {
        sum[i] += sum[i - 1];
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        long long ans = 0, add = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if (i % 2 == 0) {
                ans += a[i];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                sum[i] = -a[i];
            } else {
                sum[i] = a[i];
            }
        }
        calc();
        long long mn = 0;
        for (int i = 1; i < n; i += 2) {
            add = max(add, sum[i] - mn);
            mn = min(mn, sum[i]);
        }
        mn = sum[0];
        for (int i = 2; i < n; i += 2) {
            add = max(add, sum[i] - mn);
            mn = min(mn, sum[i]);
        }
        printf("%I64d\n", ans + add);
    }
    return 0;
}