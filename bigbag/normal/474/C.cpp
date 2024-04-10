#include <iostream>
#include <vector>

using namespace std;

struct point {
    long long x, y;
    point() {
    }
    point(int x, int y) : x(x), y(y) {
    }
    void read() {
        cin >> x >> y;
    }
    void write() {
        cout << x << " " << y << endl;
    }
    point operator - (point p) {
        return point(x - p.x, y - p.y);
    }
    point operator + (point p) {
        return point(x + p.x, y + p.y);
    }
};

point nxt(point a) {
    return point(-a.y, a.x);
}

long long n;
point a[4], p[4][4], q[4];

long long dist(point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

long long cross_pr(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

bool is_square(point a, point b, point c, point d) {
    long long md = 111111111111111111LL;
    q[0] = a;
    q[1] = b;
    q[2] = c;
    q[3] = d;
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            md = min(md, dist(q[i], q[j]));
        }
    }
    for (int i = 0; i < 4; ++i) {
        vector<int> v;
        int cnt = 0;
        for (int j = 0; j < 4; ++j) {
            if (j != i && dist(q[i], q[j]) == md) {
                v.push_back(j);
                ++cnt;
            }
        }
        if (cnt != 2) {
            return false;
        }
        if (cross_pr(q[v[0]] - q[i], q[v[1]] - q[i]) != 0) {
            return false;
        }
    }
    return true;
}

int fun() {
    int res = 1111;
    for (int q = 0; q < 4; ++q) {
        for (int w = 0; w < 4; ++w) {
            for (int e = 0; e < 4; ++e) {
                for (int r = 0; r < 4; ++r) {
                    if (is_square(p[0][q], p[1][w], p[2][e], p[3][r])) {
                        res = min(res, q + w + e + r);
                    }
                }
            }
        }
    }
    if (res == 1111) {
        res = -1;
    }
    return res;
}

int main() {
    cin >> n;
    while (n--) {
        for (int i = 0; i < 4; ++i) {
            p[i][0].read();
            a[i].read();
            p[i][0] = p[i][0] - a[i];
            for (int j = 1; j < 4; ++j) {
                p[i][j] = nxt(p[i][j - 1]);
            }
            for (int j = 0; j < 4; ++j) {
                p[i][j] = p[i][j] + a[i];
            }
        }
        cout << fun() << endl;
    }
}