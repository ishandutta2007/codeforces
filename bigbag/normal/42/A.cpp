#include <map>
#include <set>
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

const int max_n = 22, inf = 111111111;
const double eps = 1e-6;

int n;
double v, a[max_n], b[max_n];

bool good(double x) {
    double cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += a[i] * x;
        if (a[i] * x > b[i]) {
            return false;
        }
    }
    if (cnt > v) {
        return false;
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> v;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    double l = 0, r = v + eps;
    while (r - l > eps) {
        double x = (l + r) / 2;
        if (good(x)) {
            l = x;
        } else {
            r = x;
        }
    }
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i] * l;
    }
    printf("%.5f", ans);
    return 0;
}