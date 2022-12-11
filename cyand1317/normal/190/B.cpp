#include <cstdio>
#include <cmath>
#include <algorithm>
using std::swap;

int main()
{
    int x1, y1, r1, x2, y2, r2;

    scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
    int dist_sq = ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    double dist = sqrt(dist_sq);
    if (r1 > r2) swap(x1, x2), swap(y1, y2), swap(r1, r2);

    // r1 < r2
    double ans;
    if (r1 + dist < r2) ans = r2 - (r1 + dist);
    else if (r1 + r2 < dist) ans = dist - (r1 + r2);
    else ans = 0;

    printf("%.8lf\n", ans / 2);
    return 0;
}