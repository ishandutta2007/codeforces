#include <algorithm>
#include <cstdio>
#include <cstring>

int main() {
    int t, T;
    int n, m, x1, y1, x2, y2;
    scanf("%d", &T);
    for (t = 0; t < T; ++t) {
        scanf("%d %d %d %d %d %d", &n, &m, &x1, &y1, &x2, &y2);
        if (x1 > x2) {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        if (y1 > y2) {
            y1 = m + 1 - y1;
            y2 = m + 1 - y2;
        }
        int x = x2 - x1;
        int y = y2 - y1;
        long long tot = (long long) n * m;
        long long bx2 = 1LL + x;
        long long by2 = 1LL + y;
        long long bx1 = (long long) n - x;
        long long by1 = (long long) m - y;
        long long overlap;
        tot -= 2LL * (bx1) * (by1);
        if (bx1 < bx2 || by1 < by2) {
            overlap = 0;
        } else {
            overlap = (1LL + bx1 - bx2) * (1LL + by1 - by2);
        }
        tot += overlap;
        printf("%lld\n", tot);
    }
    return 0;
}