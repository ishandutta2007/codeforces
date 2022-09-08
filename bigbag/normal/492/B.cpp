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

const int max_n = 1111, inf = 1111111111;

int n;
double x, a[max_n];

bool ok(double d) {
    if (a[0] > d) {
        return false;
    }
    if (a[n - 1] + d < x) {
        return false;
    }
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i + 1] - a[i] > 2 * d) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    double l = 0, r = inf;
    for (int i = 0; i < 100; ++i) {
        double mid = (l + r) / 2;
        if (ok(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%.10f\n", r);
    return 0;
}