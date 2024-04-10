#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111;
const long long inf = 1000111222000111222LL;

int n, q;
long long a[max_n], sum[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
    }
    sort(a, a + n);
    for (int i = 0; i + 1 < n; ++i) {
        a[i] = a[i + 1] - a[i];
    }
    a[n - 1] = inf;
    sort(a, a + n);
    sum[0] = a[0];
    for (int i = 1; i < n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        long long ql, qr;
        scanf("%I64d%I64d", &ql, &qr);
        long long x = qr - ql + 1;

        int l = -1, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (a[mid] <= x) {
                l = mid;
            } else {
                r = mid;
            }
        }
        long long ans = 0;
        if (l != -1) {
            ans += sum[l];
        }
        ans += x * (n - l - 1);
        printf("%I64d ", ans);
    }
    return 0;
}