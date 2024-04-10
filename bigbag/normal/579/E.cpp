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

const int max_n = 222222, inf = 1111111111;
const double eps = 1e-11;

int n;
long long a[max_n];
double b[max_n];

double f(double x) {
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] - x;
    }
    double sum = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        sum += b[i];
        res = max(res, sum);
        sum = max(sum, 0.0);
    }
    for (int i = 0; i < n; ++i) {
        b[i] *= -1;
    }
    sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += b[i];
        res = max(res, sum);
        sum = max(sum, 0.0);
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
    }
    double l = 0, r = 11111;
    for (int i = 0; i < 111; ++i) {
        double mid1 = (2 * l + r) / 3;
        double mid2 = (l + 2 * r) / 3;
        if (f(mid1) > f(mid2)) {
            l = mid1;
        } else {
            r = mid2;
        }
    }
    double ans = f(l);
    l = 0, r = 11111;
    for (int i = 0; i < 111; ++i) {
        double mid1 = (2 * l + r) / 3;
        double mid2 = (l + 2 * r) / 3;
        if (f(-mid1) > f(-mid2)) {
            l = mid1;
        } else {
            r = mid2;
        }
    }
    ans = min(ans, f(-l));
    printf("%.10f\n", ans);
    return 0;
}