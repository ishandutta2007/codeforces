#include <bits/stdc++.h>
using namespace std;

const int N = 22000000;

unsigned int b[N];
long long a[N];

int main() {
    ios::sync_with_stdio(0);
    int ncase;
    for (cin >> ncase; ncase--; ) {
        int n; long long l, r; cin >> n >> l >> r;
        unsigned int x, y, z; cin >> x >> y >> z >> b[1] >> b[2];
        for (int i = 1; i <= n; i++) {
            if (i > 2) b[i] = b[i - 1] * y + b[i - 2] * x + z;
            a[i] = b[i] % (r - l + 1) + l;
        }
        const long long inf = 1LL<<62;
        long long ans = inf;
        {
            long long last = a[1];
            for (int i = 2; i <= n; i++) {
                if (a[i] >= 0) {
                    if (last < a[i]) {
                        ans = min(ans, last * a[i]);
                    }
                }
                last = min(last, a[i]);
            }
        }
        {
            long long last = a[n];
            for (int i = n - 1; i > 0; i--) {
                if (a[i] <= 0) {
                    if (last > a[i]) {
                        ans = min(ans, last * a[i]);
                    }
                }
                last = max(last, a[i]);
            }
        }
        if (ans == inf) {
            puts("IMPOSSIBLE");
        } else {
            printf("%lld\n", ans);
        }
    }
    return 0;
}