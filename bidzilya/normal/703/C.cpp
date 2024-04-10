#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

#include <cmath>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

int n, w, v, u;
vector<pair<int, int>> points;

int main() {
    scanf("%d%d%d%d", &n, &w, &v, &u);
    points.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &points[i].first, &points[i].second);
    }

    double minValue = 1e18;
    double maxValue = -1e18;
    bool minus = false;
    bool plus = false;
    for (int i = 0; i < n; ++i) {
        long long zn = 1LL * points[i].first * u - 1LL * points[i].second * v;
        long long ch = u;

        if (zn < 0) {
            minus = true;
        }

        if (zn > 0) {
            plus = true;
        }

        double value = 1.0 * zn / ch;

        minValue = min(minValue, value);
        maxValue = max(maxValue, value);
    }

    if (!minus || !plus) {
        printf("%.15lf\n", 1.0 * w / u);
    } else {
        printf("%.15lf\n", 1.0 * w / u + maxValue / v);
    }

    return 0;
}