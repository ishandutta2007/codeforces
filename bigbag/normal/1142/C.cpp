#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111;

struct point {
    long long x, y;

    point() {
    }

    point(long long x, long long y): x(x), y(y) {
    }

    bool operator < (const point &p) const {
        return x < p.x || x == p.x && y < p.y;
    }

    point operator - (const point &p) const {
        return point(x - p.x, y - p.y);
    }
};

long long vect_pr(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
}

bool cw(const point &a, const point &b, const point &c) {
    return vect_pr(b - a, c - b) >= 0;
}

bool ccw(const point &a, const point &b, const point &c) {
    return vect_pr(b - a, c - b) <= 0;
}

int n;
point p[max_n];

vector<point> convex_hull() {
    vector<point> up;
    if (n == 1) {
        up.push_back(p[0]);
        return up;
    }
    sort(p, p + n);
    up.push_back(p[0]);
    for (int i = 1; i < n; ++i) {
        if (ccw(p[0], p[i], p[n - 1])) {
            while (up.size() > 1 && cw(up[up.size() - 2], up[up.size() - 1], p[i])) {
                up.pop_back();
            }
            up.push_back(p[i]);
        }
    }
    return up;
}

void normalize(long long &q, long long &w) {
    long long g = w;
    if (q != 0) {
        g = __gcd(q, w);
    }
    q /= g;
    w /= g;

    if (q < 0) {
        q *= -1;
        w *= -1;
    }
    if (q == 0 && w < 0) {
        w *= -1;
    }
}

vector<pair<pair<long long, long long>, pair<long long, long long>>> ans;

pair<pair<long long, long long>, pair<long long, long long>> pline(const point &a, const point &b) {
    long long q = a.y - b.y;
    long long w = a.x - b.x;
    normalize(q, w);
    long long q2 = a.y * w - q * a.x;
    long long w2 = w;
    normalize(q2, w2);
    return make_pair(make_pair(q, w), make_pair(q2, w2));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    if (n == 1) {
        puts("0");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%I64d%I64d", &p[i].x, &p[i].y);
        p[i].y -= p[i].x * p[i].x;
    }
    sort(p, p + n);
    vector<point> v;
    for (int i = 0; i < n; ++i) {
        if (i + 1 == n || p[i].x < p[i + 1].x) {
            v.push_back(p[i]);
        }
    }
    if (v.size() == 1) {
        puts("0");
        return 0;
    }
    n = v.size();
    for (int i = 0; i < n; ++i) {
        p[i] = v[i];
    }
    v = convex_hull();
    for (int i = 0; i + 1 < v.size(); ++i) {
        ans.push_back(pline(v[i], v[i + 1]));
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    printf("%d\n", ans.size());
    return 0;
}