# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_set>
# include <unordered_map>
using namespace std;

const long double eps = 0.00000001;

pair<long double, long double> a, b;
long double xx1, yy1, xx2, yy2;
long double vmax, t;

inline long double f(long double mid) {
    long double px, py;
    px = xx1;
    py = yy1;
    if (mid >= t) {
        px += a.first * t;
        py += a.second * t;
        px += b.first * (mid - t);
        py += b.second * (mid - t);
    } else {
        px += a.first * mid;
        py += a.second * mid;
    }
    long double len = ((px - xx2) * (px - xx2) + (py - yy2) * (py - yy2));
    len /= vmax * vmax;
    if (len / mid > mid) return false;
    return true;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> xx1 >> yy1 >> xx2 >> yy2;
    cin >> vmax >> t;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    long double l = 0;
    long double r = 1e9;
    for (int it = 0; it <= 700; ++it) {
        long double mid = (l + r) / 2.;
        if (f(mid)) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(6) << l << '\n';
}