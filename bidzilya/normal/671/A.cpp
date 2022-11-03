#include <iostream>
#include <vector>
#include <set>
#include <iomanip>

#include <cmath>
using namespace std;

struct TPoint {
    long long X;
    long long Y;
};

inline long long GetLen2(const TPoint& lhs, const TPoint& rhs) {
    return (lhs.X - rhs.X) * (lhs.X - rhs.X) + (lhs.Y - rhs.Y) * (lhs.Y - rhs.Y);
}

inline double GetLen(const TPoint& lhs, const TPoint& rhs) {
    return sqrt(0.0 + GetLen2(lhs, rhs));
}

istream& operator >> (istream& inputStream, TPoint& point) {
    inputStream >> point.X >> point.Y;
    return inputStream;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    TPoint a, b, t;
    cin >> a >> b >> t;

    int n;
    cin >> n;

    vector<TPoint> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i];
    }

    double allSum = 0;
    for (int i = 0; i < n; ++i) {
        allSum += GetLen(points[i], t);
    }

    allSum *= 2.0;

    set<pair<double, int>> sa, sb;

    for (int i = 0; i < n; ++i) {
        sa.insert(make_pair(GetLen(a, points[i]) - GetLen(points[i], t), i));
        sb.insert(make_pair(GetLen(b, points[i]) - GetLen(points[i], t), i));
    }

    double result = allSum + sa.begin()->first;
    result = min(result, allSum + sb.begin()->first);

    if (n > 1) {
        if (sa.begin()->second == sb.begin()->second) {
            auto itr = sb.begin();
            ++itr;
            result = min(result, allSum + sa.begin()->first + itr->first);
        } else {
            result = min(result, allSum + sa.begin()->first + sb.begin()->first);
        }

        if (sb.begin()->second == sa.begin()->second) {
            auto itr = sa.begin();
            ++itr;
            result = min(result, allSum + sb.begin()->first + itr->first);
        } else {
            result = min(result, allSum + sb.begin()->first + sa.begin()->first);
        }
    }

    cout << fixed << setprecision(15) << result << endl;

    return 0;
}