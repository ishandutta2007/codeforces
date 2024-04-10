/**
 *  created: 17/07/2021, 17:49:51
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 101111, inf = 1000111222;

int t, n, a[max_n], b[max_n], sa[max_n], sb[max_n];

bool check(int cnt) {
    int k = n + cnt;
    k -= k / 4;
    int sum1 = 0, sum2 = sb[min(n, k)];
    int c1 = min(k, cnt);
    sum1 = c1 * 100;
    sum1 += sa[k - c1];
    return sum1 >= sum2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &b[i]);
        }
        sort(a, a + n);
        sort(b, b + n);
        reverse(a, a + n);
        reverse(b, b + n);
        for (int i = 0; i < n; ++i) {
            sa[i + 1] = sa[i] + a[i];
            sb[i + 1] = sb[i] + b[i];
        }
        int l = -1, r = 10 * max_n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}