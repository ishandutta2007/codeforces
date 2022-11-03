#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

#include <cmath>
using namespace std;

const double PI = acos(-1.0);

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

using TPoint = pair<long long, long long>;

TPoint operator - (const TPoint& lhs, const TPoint& rhs) {
    return TPoint{lhs.first - rhs.first, lhs.second - rhs.second};
}

long long GetSMult(const TPoint& lhs, const TPoint& rhs) {
    return lhs.first * rhs.first + lhs.second * rhs.second;
}

long long GetVMult(const TPoint& lhs, const TPoint& rhs) {
    return lhs.first * rhs.second - lhs.second * rhs.first;
}

long long GetDist2(const pair<long long, long long>& lhs, const pair<long long, long long>& rhs) {
    return (lhs.first - rhs.first) * (lhs.first - rhs.first) + (lhs.second - rhs.second) * (lhs.second - rhs.second);
}

double GetDist(const TPoint& start, const TPoint& finish, const TPoint& point) {
    if (GetSMult(finish - start, point - start) >= 0 && GetSMult(start - finish, point - finish) >= 0) {
        long long vmult = abs(GetVMult(finish - start, point - start));
        return 1.0 * vmult / sqrt((double) GetDist2(finish, start));
    } else {
        return 1e9;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    pair<long long, long long> start;
    scanf(LLD_SPEC LLD_SPEC, &start.first, &start.second);

    vector<pair<long long, long long>> points(n);
    for (int i = 0; i < n; ++i) {
        scanf(LLD_SPEC LLD_SPEC, &points[i].first, &points[i].second);
    }

    long long minDist2 = GetDist2(points[0], start);
    long long maxDist2 = GetDist2(points[0], start);
    for (int i = 1; i < n; ++i) {
        minDist2 = min(minDist2, GetDist2(points[i], start));
        maxDist2 = max(maxDist2, GetDist2(points[i], start));
    }

    double minDist = sqrt((double) minDist2);
    double maxDist = sqrt((double) maxDist2);

    for (int i = 0; i < n; ++i) {
        int j = i + 1;
        if (j == n) {
            j = 0;
        }

        double curDist = GetDist(points[i], points[j], start);

        minDist = min(minDist, curDist);
    }

    double result = PI * (maxDist - minDist) * (maxDist + minDist);

    printf("%.15lf\n", result);

    return 0;
}