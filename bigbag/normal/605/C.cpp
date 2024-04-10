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

const int max_n = 311111, inf = 1111111111;
const double eps = 1e-8;

struct point {
    int x, y;
    point() {
        x = y = 0;
    }
    point(int x, int y) : x(x), y(y) {
    }
    point operator - (const point &p) const {
        return point(x - p.x, y - p.y);
    }
    bool operator < (const point &p) const {
        return x < p.x || x == p.x && y < p.y;
    }
    void write(string s = "") {
        cout << "(" << x << " " << y << ")" << s;
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
        A = b.y - a.y;
        B = a.x - b.x;
        C = -A * a.x - B * a.y;
        long long g = __gcd(A, B);
        g = __gcd(g, C);
        A /= g;
        B /= g;
        C /= g;
    }
    void write(string s = "") {
        cout << A << " " << B << " " << C << s;
    }
};


int n, p, q;
vector<point> v;

long long vect_pr(point a, point b) {
    return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

bool cv(point a, point b, point c) {
    point q = b - a;
    point w = c - b;
    return vect_pr(q, w) > 0;
}

bool ccv(point a, point b, point c) {
    point q = b - a;
    point w = c - b;
    return vect_pr(q, w) < 0;
}

vector<point> get_convex_hull(vector<point> v) {
    if (v.size() == 1) {
        return v;
    }
    vector<point> res, up, down;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        if (i == 0 || i + 1 == v.size() || cv(v[0], v[i], v.back())) {
            while (up.size() >= 2 && !cv(up[up.size() - 2], up[up.size() - 1], v[i])) {
                up.pop_back();
            }
            up.push_back(v[i]);
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        if (i == 0 || i + 1 == v.size() || ccv(v[0], v[i], v.back())) {
            while (down.size() >= 2 && !ccv(down[down.size() - 2], down[down.size() - 1], v[i])) {
                down.pop_back();
            }
            down.push_back(v[i]);
        }
    }
    down.pop_back();
    reverse(down.begin(), down.end());
    down.pop_back();
    res = up;
    for (int i = 0; i < down.size(); ++i) {
        res.push_back(down[i]);
    }
    return res;
}

bool is_in(point a, point b, double x, double y) {
    double xx = a.x - x;
    double yy = a.y - y;
    double res = sqrt(xx * xx + yy * yy);
    xx = b.x - x;
    yy = b.y - y;
    res += sqrt(xx * xx + yy * yy);
    xx = b.x - a.x;
    yy = b.y - a.y;
    res -= sqrt(xx * xx + yy * yy);
    if (fabs(res) > eps) {
    }
    return fabs(res) <= eps;
}

void per_otr(point a, point b, point c, point d, double &x, double &y) {
    line l1 = line(a, b);
    line l2 = line(c, d);
    x = -inf;
    y = -inf;
    long long q = l2.A * l1.C - l2.C * l1.A;
    long long w = l2.C * l1.B - l2.B * l1.C;
    long long e = l1.A * l2.B - l2.A * l1.B;
    if (e == 0) {
        return;
    }
    x = ((long double) w) / e;
    y = ((long double) q) / e;
    if (!is_in(a, b, x, y) || !is_in(c, d, x, y)) {
        //cout << is_in(a, b, x, y) << " " << is_in(c, d, x, y) << "  ";
        x = -inf;
        y = -inf;
    }
    //cout << x << " " << y;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &p, &q);
    int kp = p, kq = q;
    while (p < 10000000 && q < 10000000) {
        p *= 2;
        q *= 2;
    }
    for (int i = 0; i < n; ++i) {
        point a;
        scanf("%d%d", &a.x, &a.y);
        v.push_back(a);
        v.push_back(point(a.x, 0));
        v.push_back(point(0, a.y));
    }
    v = get_convex_hull(v);
    double ansx = 0, ansy = 0;
    for (int i = 0; i < v.size(); ++i) {
        //v[i].write("\n");
        double x, y;
        //cout << i << " : ";
        per_otr(point(0, 0), point(p, q), v[i], v[(i + 1) % v.size()], x, y);
        //cout << endl;
        if (ansx < x) {
            ansx = x;
            ansy = y;
        }
    }
    //printf("%.10f %.10f\n", ansx, ansy);
    printf("%.10f\n", kp / ansx);
    return 0;
}