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

const int max_n = 11111, inf = 1011111111;

int n, len, v1, v2, k;

bool check(long double t) {
    long double poz1 = 0, poz2 = 0;
    for (int i = n; i > 0; i -= k) {
        long double x = (poz2 * v1 + poz1 * v2) / (v1 + v2);
        t -= (poz2 - poz1) / (v1 + v2);
        poz1 = poz2 = x;
        long double o = len - x;
        if (t < 0) {
            return false;
        }
        if (t * v2 < o) {
            return false;
        }
        if (i <= k) {
            return true;
        }
        long double t1 = (o - t * v1) / (v2 - v1);
        if (t1 < 0) {
            return true;
        }
        t -= t1;
        poz1 += v1 * t1;
        poz2 += v2 * t1;
    }
    return t >= 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> len >> v1 >> v2 >> k;
    long double l = 0, r = inf;
    for (int i = 0; i < 100; ++i) {
        long double mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%.10f\n", (double) (r));
    return 0;
}