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

typedef pair<uint64, uint64> point;
typedef pair<uint64, uint64> dist;

inline uint64 sqr(uint64 num) {return num * num;}

inline uint64 sqrDistBetween(point& p1, point& p2) {
    return sqr(p1.fi - p2.fi) + sqr(p1.se - p2.se);
}

int main (void) {
    ios_base::sync_with_stdio(0);
    int32 i, f, g;  // count variable

    int32 n;
    point fountain1, fountain2;
    cin >> n >> fountain1.fi >> fountain1.se >> fountain2.fi >> fountain2.se;

    point flowsers[n];
    dist sqrDistList[n + 1];

    for to(i, 0, n, 1) {
        cin >> flowsers[i].fi >> flowsers[i].se;
        sqrDistList[i].fi = sqrDistBetween(flowsers[i], fountain1);
        sqrDistList[i].se = sqrDistBetween(flowsers[i], fountain2);
    }
    sqrDistList[n] = MP(0, 0);

    sort(sqrDistList, &sqrDistList[n + 1], [] (point& a, point& b) {return a.fi < b.fi;});

    uint64 tempArr[n + 1];
    tempArr[n] = 0;
    tempArr[n - 1] = sqrDistList[n].se;
    for downto(i, n - 1, 0, 1) {
        tempArr[i] = max(tempArr[i + 1], sqrDistList[i + 1].se);
    }

    // for to(i, 0, n, 1) {
    //     debug(i << ' ' << sqrDistList[i].fi << ' ' << sqrDistList[i].se << ' ' << tempArr[i]);
    // }

    uint64 result = ULLONG_MAX;
    for to(i, 0, n + 1, 1) {
        uint64 a = sqrDistList[i].fi + tempArr[i];
        debug(sqrDistList[i].fi << ' ' << tempArr[i] << ' ' << a);
        if (result > a) result = a;
    }

    cout << (int64) result << endl;

    return 0;
}