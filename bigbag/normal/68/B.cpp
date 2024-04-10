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

const int max_n = 11111, inf = 111111111;
const double eps = 1e-9;

int n, k, a[max_n];

bool good(double x) {
    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < x) {
            sum1 += x - a[i];
        } else {
            sum2 += a[i] - x;
        }
    }
    return sum2 - (sum2 * k) / 100 >= sum1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    double l = 0, r = inf;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (good(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%.10f\n", l);
    return 0;
}