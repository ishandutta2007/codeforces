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
        printf("%.5f %.5f", x, y);
    }
};

struct line {
    long long A, B, C;
    line() {
        A = B = C = 0;
    }
    line(long long A, long long B, long long C) : A(A), B(B), C(C) {
    }
    line(point a, point b) {
		A = a.y - b.y;
		B = b.x - a.x;
		C = -A * a.x - B * a.y;
	}
};

long double dist(point p, line l) {
    return fabs((l.A * p.x + l.B * p.y + l.C) / sqrt(l.A * l.A + l.B * l.B));
}

const int max_n = 1011;

int n;
point p[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        p[i].read();
    }
    p[n] = p[0];
    p[n + 1] = p[1];
    long double ans = 1e18;
    for (int i = 0; i < n; ++i) {
        line l = line(p[i], p[i + 2]);
        ans = min(ans, dist(p[i + 1], l));
    }
    printf("%.10f\n", (double) (ans / 2));
    return 0;
}