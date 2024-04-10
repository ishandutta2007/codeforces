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
const double pi = 3.14159265358979323846;

struct point {
    double x, y, a;
    void read() {
        cin >> x >> y >> a;
        a = a * pi / 180;
    }
    bool operator < (const point &p) const {
        return x < p.x || x == p.x && y < p.y || x == p.x && y == p.y && a < p.a;
    }
    point operator / (double a) {
        point ret;
        ret.x = x / a;
        ret.y = y / a;
        return ret;
    }
    point operator - (point a) {
        point ret;
        ret.x = x - a.x;
        ret.y = y - a.y;
        return ret;
    }
};

point make_point(double x, double y) {
    point ret;
    ret.x = x;
    ret.y = y;
    return ret;
}

int n, l, r;
double ans[1 << max_n];
point p[max_n];

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> l >> r;
    for (int i = 0; i < n; ++i) {
        p[i].read();
        p[i].y = fabs(p[i].y);
    }
    ans[0] = l;
    for (int i = 1; i < (1 << n); ++i) {
        ans[i] = -inf;
    }
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (get_bit(i, j) == 0) {
                double max_r = ans[i];
                point v = make_point(max_r, 0) - p[j];
                point v1;
                v1.x = v.x * cos(p[j].a) - v.y * sin(p[j].a);
                v1.y = v.x * sin(p[j].a) + v.y * cos(p[j].a);
                if (v1.y >= 0) {
                    cout << r - l << endl;
                    return 0;
                }
                v1 = v1 / v1.y;
                ans[i | (1 << j)] = max(ans[i | (1 << j)], p[j].x - p[j].y * v1.x);
                //cout << i << " -> " << (i | (1 << j)) << "   " << ans[i] << ' ' << max_r << endl;
            }
        }
    }
    printf("%.7f\n", min((double)r - l, ans[(1 << n) - 1] - l));
    //printf("%.7f\n", ans[(1 << n) - 1] - l);
    return 0;
}