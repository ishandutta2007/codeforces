#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const long double pi = 2 * acos(0.0), eps = 1e-7, inf = 1111111111;

int n, r, v, s, t;

long double get_t(long double x, long double y) {
    y -= x;
    long double ll = (y - r) / v, rr = (y + r) / v;
    for (int i = 0; i < 50; ++i) {
        long double mid = (ll + rr) / 2;
        long double d = v * mid + r * cos(v * mid / r);
        if (d < y) {
            ll = mid;
        } else {
            rr = mid;
        }
    }
    return ll;
}

long double f(long double x) {
    return get_t(x, t) - get_t(x, s);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &r, &v);
    while (n--) {
        scanf("%d%d", &s, &t);
        long double q = (s + t) / 2.0;
        long double dd = 2 * pi * r;
        int k = (t - s) / dd;
        q -= (k + 2) * dd;
        double ans = min(f(q - pi * r / 2), f(q - 3 * pi * r / 2));
        printf("%.10f\n", ans);
    }
    return 0;
}