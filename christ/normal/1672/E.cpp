#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5, MOD = 1e9 + 7;
int query (int w) {
    printf ("? %d\n",w);
    fflush(stdout);
    int ret; scanf ("%d",&ret);
    return ret;
}
int main () {
    int n; scanf ("%d",&n);
    int sum = 0;
    {
        int low = 1, high = 2000 * n, mid, ans = -1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (query(mid + n - 1) == 1) {
                high = (ans = mid) - 1;
            } else {
                low = mid + 1;
            }
        }
        sum = ans;
    }
    long long ans = sum + n - 1;
    for (int w = 1; w <= sum + n - 1; w++) {
        int needH = (sum + w - 1) / w;
        while ((sum + n - needH + w - 1) / w > needH) ++needH;
        if (needH > n) continue;
        if ((long long)needH * w >= ans) continue;
        int got = query(w);
        if (got > 0) ans = min(ans,(long long)w * got);
    }
    printf ("! %lld\n",ans);
    return 0;
}