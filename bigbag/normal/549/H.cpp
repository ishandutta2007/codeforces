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

const int max_n = 11, inf = 2111111111;

int a[4];
double b[4];

int num(int x) {
    if (x == 0 || x == 3) {
        return 1;
    }
    return 2;
}

bool ok(double l, double r, double x) {
    return l <= x && x <= r;
}

bool check(double x) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (num(i) != num(j)) {
                for (int q = 0; q < 4; ++q) {
                    for (int w = 0; w < 4; ++w) {
                        if (i != q && j != w && num(i) == num(q) && num(j) == num(w)) {
                            for (int z1 = -1; z1 <= 1; ++z1) {
                                if (z1 == 0) continue;
                                for (int z2 = -1; z2 <= 1; ++z2) {
                                    if (z2 == 0) continue;
                                    b[i] = a[i] + x * z1;
                                    b[j] = a[j] + x * z2;
                                    double mn = min(b[i] * (a[q] - x), b[i] * (a[q] + x));
                                    double mx = max(b[i] * (a[q] - x), b[i] * (a[q] + x));
                                    if (ok(a[w] - x, a[w] + x, mx / b[j])) {
                                        return true;
                                    }
                                    if (ok(a[w] - x, a[w] + x, mn / b[j])) {
                                        return true;
                                    }
                                    if (mx / b[j] > a[w] + x && mn / b[j] < a[w] - x) {
                                        return true;
                                    }
                                    if (mn / b[j] > a[w] + x && mx / b[j] < a[w] - x) {
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    double l = 0, r = inf;
    for (int i = 0; i < 100; ++i) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%.10f\n", r);
    return 0;
}