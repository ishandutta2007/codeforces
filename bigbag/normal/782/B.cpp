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

const int max_n = 66666, inf = 1011111111;

int n, x[max_n], v[max_n];

bool check(long double t) {
    long double mn = -1e20;
    for (int i = 0; i < n; ++i) {
        mn = max(mn, x[i] - t * v[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (mn > x[i] + t * v[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    long double l = 0, r = inf;
    for (int i = 0; i < 100; ++i) {
        long double mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%.10f\n", (double) r);
    return 0;
}