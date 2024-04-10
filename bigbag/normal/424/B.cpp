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

int n, s, x[max_n], y[max_n], k[max_n];
double dist[max_n];

bool good(double d) {
    int cnt = s;
    for (int i = 0; i < n; ++i) {
        if (d >= dist[i]) {
            cnt += k[i];
        }
    }
    return cnt >= 1000000;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &x[i], &y[i], &k[i]);
        dist[i] = sqrt(x[i] * x[i] + y[i] * y[i]);
    }
    double l = 0, r = inf;
    if (!good(r)) {
        cout << -1 << endl;
        return 0;
    }
    for (int q = 0; q < 100; ++q) {
        double mid = (l + r) / 2;
        if (good(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%.15lf", r);
    return 0;
}