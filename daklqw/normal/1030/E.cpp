/*
$1
WWJ
YTX
AK NOIP
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 300010
typedef long long LL;
LL a[MAXN], pre[MAXN];
int n, b[MAXN], pre0[MAXN], pre1[MAXN];

int main() {
    scanf("%d", &n);
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        b[i] = __builtin_popcountll(a[i]);
        pre[i] = pre[i - 1] + b[i];
        pre0[i] = pre0[i - 1] + (pre[i] & 1 ^ 1);
        pre1[i] = pre1[i - 1] + (pre[i] & 1);
    }
    for (int i = 1; i <= n; ++i) {
        if (pre[i - 1] & 1) ans += pre1[n] - pre1[i];
        else ans += pre0[n] - pre0[i];
        int range = min(i + 64, n), maxn = b[i];
        for (int j = i + 1; j <= range; ++j) {
            maxn = max(maxn, b[j]);
            if ((maxn << 1) <= pre[j] - pre[i - 1]) continue;
            if (pre[j] - pre[i - 1] & 1) continue;
            --ans;
        }
    }
    printf("%lld\n", ans);
    return 0;
}