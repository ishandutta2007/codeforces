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

const int max_n = 11111, inf = 1111111111;

int n, ymx, v1, v2, x[max_n], y[max_n];
int poz;

bool check1() {
    for (int i = poz; ; ) {
        if (1LL * x[i] * v2 >= 1LL * y[i] * v1) {
        } else {
            return false;
        }
        int p = i - 1;
        if (i == 0) {
            p += n;
        }
        if (y[p] <= y[i]) {
            break;
        }
        i = p;
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &ymx, &v1, &v2);
    int MX = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        MX = max(MX, x[i]);
        if (make_pair(x[i], y[i]) < make_pair(x[poz], y[poz])) {
            poz = i;
        }
    }
    if (MX <= 0 || (x[poz] >= 0 && check1())) {
        long double ans = ymx;
        ans /= v2;
        printf("%.10f\n", (double) ans);
        return 0;
    }
    poz = 0;
    for (int i = 0; i < n; ++i) {
        if (make_pair(y[i], x[i]) < make_pair(y[poz], x[poz])) {
            poz = i;
        }
    }
    long double ans = 0, yy = 0, xx = 0;
    while (x[poz] < 0) {
        ++poz;
        poz %= n;
    }
    for (int i = poz; ; ) {
        long double t = ((long double) (x[i] - xx)) / v1;
        yy += v2 * t;
        ans += t;
        yy = min(yy, (long double) y[i]);
        int nxt = (i + 1) % n;
        if (x[nxt] <= x[i]) {
            break;
        }
        xx = x[i];
        i = nxt;
    }
    printf("%.10f\n", (double) (ans + (ymx - yy) / v2));
    return 0;
}