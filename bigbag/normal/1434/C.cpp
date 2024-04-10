#include <bits/stdc++.h>

using namespace std;

int t, a, b, c, d;

__int128 func(int k) {
    __int128 res = -1LL * (k + 1) * a;
    __int128 add = 1LL * k * (k + 1) / 2;
    add *= d;
    add *= b;
    res += add;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (a > 1LL * b * c) {
            puts("-1");
            continue;
        }
        int l = -1, r = c / d;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (func(mid) > func(mid + 1)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        long long ans = -func(r);
        printf("%lld\n", ans);
    }
    return 0;
}