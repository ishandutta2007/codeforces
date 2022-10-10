#include <bits/stdc++.h>

using namespace std;

#define debug(msg)
//#define debug(msg) cerr << __FILE__ << ':' << __LINE__ << " => " << msg << endl

#define to(i, a, b, s) (i = a; i < b; i += s)
#define downto(i, a, b, s) (i = a - 1; i >= b; i -= s)
#define all(v) v.begin(), v.end()

#define MP make_pair
#define PB push_back

#define fi first
#define se second

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

const double PI = 3.141592653589793238463;

typedef pair<int64, int64> point;

inline bool isBetween(int64 a, int64 b, int64 c) {
    return min(a, b) <= c and c <= max(a, b);
}

inline bool check(point& a, point& b, point& c) {
    return ((c.fi == a.fi or c.fi == b.fi) and isBetween(a.se, b.se, c.se)) ||
           ((c.se == a.se or c.se == b.se) and isBetween(a.fi, b.fi, c.fi));
}

int main (void) {
    ios_base::sync_with_stdio(0);
    int i, f, g;  // count variable

    point points[3];
    cin >> points[0].fi >> points[0].se;
    cin >> points[1].fi >> points[1].se;
    cin >> points[2].fi >> points[2].se;

    if (points[0].fi == points[1].fi and points[1].fi == points[2].fi) {
        cout << 1;
        return 0;
    }

    if (points[0].se == points[1].se and points[1].se == points[2].se) {
        cout << 1;
        return 0;
    }

    if (
        check(points[0], points[1], points[2]) or
        check(points[0], points[2], points[1]) or
        check(points[1], points[2], points[0])
    ) {
        cout << 2;
        return 0;
    }

    cout << 3;
    return 0;
}