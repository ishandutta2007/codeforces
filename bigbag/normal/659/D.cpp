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

const double pi = 3.14159265358979323846, eps = 1e-9, inf = 111111111;

struct point {
    int x, y;
    point() {
        x = y = 0;
    }
    point(int x, int y) : x(x), y(y) {
    }
    void read() {
        scanf("%d%d", &x, &y);
    }
    void write() {
        printf("%d %d\n", x, y);
    }
    bool operator == (point a) {
        return x == a.x && y == a.y;
    }
    point operator - (point a) {
        return point(x - a.x, y - a.y);
    }
    point operator + (point a) {
        return point(x + a.x, y + a.y);
    }
    point operator * (int a) {
        return point(x * a, y * a);
    }
    point operator / (int a) {
        return point(x / a, y / a);
    }
};

int my_abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

const int max_n = 1111, sd = 10111;

int n, s, ans;
point p[max_n];

int vect_pr(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

bool cf(point a, point b) {
    return vect_pr(a, b) > 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i) {
        p[i].read();
    }
    p[n + 1] = p[1];
    for (int i = 0; i < n; ++i) {
        if (cf(p[i + 1] - p[i], p[i + 2] - p[i + 1])) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}