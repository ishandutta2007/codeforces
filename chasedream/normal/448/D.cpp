#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL a[10000005], b[10000005], l, r, n, m, k;

inline bool check(LL kk) {
    int r = m;
    LL cnt = 0;
    for (int i = 1; i <= n; i++) {
        while (r >= 1 && a[i] * b[r] > kk) r--;
        cnt += r;
    }
    return cnt >= k;
}
int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    for (int i = 1; i <= n; i++) a[i] = i;
    for (int i = 1; i <= m; i++) b[i] = i;
    l = 1, r = n * m;
    while (l < r) {
        LL mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%lld\n", l);
    return 0;
}