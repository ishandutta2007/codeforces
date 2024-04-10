#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, a[max_n], t[max_n];
long long sum[max_n], ans[max_n], cnt[max_n];

long long get_sum(int l, int r) {
    if (l == 0) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

void inc(int l, int r) {
    ++cnt[l];
    --cnt[r + 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
    }
    sum[0] = t[0];
    for (int i = 1; i < n; ++i) {
        sum[i] = t[i] + sum[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        int l = i - 1, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (a[i] >= get_sum(i, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (i <= l) {
            inc(i, l);
            a[i] -= get_sum(i, l);
        }
        ans[r] += a[i];
    }
    for (int i = 0; i < n; ++i) {
        if (i) {
            cnt[i] += cnt[i - 1];
        }
        printf("%I64d ", cnt[i] * t[i] + ans[i]);
    }
    printf("\n");
    return 0;
}