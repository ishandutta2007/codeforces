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

const int inf = 111111111;

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
    void write(string s = "") {
        printf("%d %d%s", x, y, s.c_str());
    }
    void write_point(string s = "") {
        printf("(%d %d)%s", x, y, s.c_str());
    }
    bool operator == (const point &a) const {
        return x == a.x && y == a.y;
    }
    bool operator < (const point &a) const {
        return x < a.x || x == a.x && y < a.y;
    }
    point operator - (const point &a) const {
        return point(x - a.x, y - a.y);
    }
    point operator + (const point &a) const {
        return point(x + a.x, y + a.y);
    }
    point operator * (const int &a) const {
        return point(x * a, y * a);
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
    void write(string s = "") {
        cout << A << " " << B << " " << C << s;
    }
};

struct segment {
    point l, r;
    void read() {
        l.read();
        r.read();
    }
    segment() {
        l = r = point();
    }
    segment(point l, point r) : l(l), r(r) {
    }
};

long long cross_pr(point a, point b) {
    return 1LL * a.x * b.x + 1LL * a.y * b.y;
}

long long vect_pr(point a, point b) {
    return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

int cv(point a, point b, point c) {
    long long q = vect_pr(b - a, c - b);
    if (q == 0) {
        return 0;
    }
    if (q > 0) {
        return 1;
    }
    return -1;
}

bool intersect(int lx, int rx, int ly, int ry) {
    if (lx > rx) {
        swap(lx, rx);
    }
    if (ly > ry) {
        swap(ly, ry);
    }
    if (lx > ly) {
        swap(lx, ly);
        swap(rx, ry);
    }
    return ly <= rx;
}

bool intersect(segment a, segment b) {
    return intersect(a.l.x, a.r.x, b.l.x, b.r.x) && intersect(a.l.y, a.r.y, b.l.y, b.r.y) && cv(a.l, b.l, a.r) * cv(a.l, b.r, a.r) <= 0 && cv(b.l, a.l, b.r) * cv(b.l, a.r, b.r) <= 0;
}

bool is_in(point a, point b, point c) {
    return intersect(segment(a, b), segment(c, c));
}

long long area2(int n, point p[]) {
    long long res = 0;
    p[n] = p[0];
    for (int i = 0; i < n; ++i) {
        res += 1LL * (p[i].y + p[i + 1].y) * (p[i + 1].x - p[i].x);
    }
    if (res < 0) {
        res *= -1;
    }
    return res;
}

long long s_triangle(point a, point b, point c) {
    long long res = 1LL * (a.y + b.y) * (b.x - a.x) + 1LL * (b.y + c.y) * (c.x - b.x) + 1LL * (c.y + a.y) * (a.x - c.x);
    if (res < 0) {
        res *= -1;
    }
    return res;
}

vector<point> convex_hull(int n, point p[]) {
    sort(p, p + n);
    p[n] = p[0];
    vector<point> res, up, down;
    if (n == 1) {
        res.push_back(p[0]);
        return res;
    }
    up.push_back(p[0]);
    for (int i = 1; i < n; ++i) {
        while (up.size() > 1 && cv(up[up.size() - 2], up[up.size() - 1], p[i]) <= 0) {
            up.pop_back();
        }
        up.push_back(p[i]);
    }
    down.push_back(p[0]);
    for (int i = 1; i < n; ++i) {
        while (down.size() > 1 && cv(down[down.size() - 2], down[down.size() - 1], p[i]) >= 0) {
            down.pop_back();
        }
        down.push_back(p[i]);
    }
    down.pop_back();
    reverse(down.begin(), down.end());
    down.pop_back();
    res = up;
    for (int i = 0; i < down.size(); ++i) {
        res.push_back(down[i]);
    }
}

const int max_n = 5555;

int n, a, b, c;
long long s;
point p[max_n];
vector<point> v;

void write(point a, point b, point c) {
    point A, B, C;
    A = c + a - b;
    C = c + b - a;
    B = b + a - c;
    A.write("\n");
    B.write("\n");
    C.write("\n");
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%I64d", &n, &s);
    for (int i = 0; i < n; ++i) {
        p[i].read();
    }
    v = convex_hull(n, p);
    for (int i = 0; i < v.size(); ++i) {
        //v[i].write("\n");
    }
    int q = 0, w = 1, e = 2;
    long long mx = 0;
    n = v.size();
    while (q < n) {
        while (true) {
            while (s_triangle(v[q], v[w], v[e]) <= s_triangle(v[q], v[w], v[(e + 1) % n])) {
                ++e;
                e %= n;
            }
            //cout << "#" << q << " " << w << " " << e << endl;
            if (mx < s_triangle(v[q], v[w], v[e])) {
                mx = s_triangle(v[q], v[w], v[e]);
                a = q;
                b = w;
                c = e;
            }
            if (s_triangle(v[q], v[w], v[e]) <= s_triangle(v[q], v[(w + 1) % n], v[e])) {
                ++w;
                w %= n;
            } else {
                break;
            }
        }
        ++q;
        if (q == w) w = (w + 1) % n;
        if (w == e) e = (e + 1) % n;
    }
    //cout << a << " " << b << " " << c << endl;
    write(v[a], v[b], v[c]);
    return 0;
}