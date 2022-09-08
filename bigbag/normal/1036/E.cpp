#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

struct point {
    int x, y;

    point() {
    }

    point(int x, int y): x(x), y(y) {
    }

    void read() {
        scanf("%d%d", &x, &y);
    }

    point operator - (const point &p) {
        return point(x - p.x, y - p.y);
    }

    bool operator < (const point &p) const {
        return x < p.x || x == p.x && y < p.y;
    }

    bool operator == (const point &p) const {
        return x == p.x && y == p.y;
    }
};

struct line {
    long long A, B, C;

    line() {
    }

    line(const point &a, const point &b) {
        A = a.y - b.y;
        B = b.x - a.x;
        C = -1LL * A * a.x - 1LL * B * a.y;
    }
};

int n, cnt[max_n * max_n];
point a[max_n], b[max_n];
line l[max_n];
long long ans;
vector<point> v;

bool is_in(long long l, long long r, long long x) {
    if (l > r) {
        swap(l, r);
    }
    return l <= x && x <= r;
}

bool is_in(const point &a, const point &b, long long x, long long y) {
    return is_in(a.x, b.x, x) && is_in(a.y, b.y, y);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        cnt[(i * (i - 1)) / 2] = i;
    }

    for (int i = 0; i < n; ++i) {
        a[i].read();
        b[i].read();
        point v = b[i] - a[i];
        ans += 1 + __gcd(abs(v.x), abs(v.y));
        l[i] = line(a[i], b[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long q = 1LL * l[j].A * l[i].C - 1LL * l[j].C * l[i].A;
            long long w = 1LL * l[j].C * l[i].B - 1LL * l[j].B * l[i].C;
            long long e = 1LL * l[i].A * l[j].B - 1LL * l[j].A * l[i].B;
            if (e != 0 && q % e == 0 && w % e == 0) {
                long long x = w / e, y = q / e;
                if (is_in(a[i], b[i], x, y) && is_in(a[j], b[j], x, y)) {
                    v.push_back({x, y});
                }
            }
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        int c = 1;
        while (i + 1 < v.size() && v[i] == v[i + 1]) {
            ++i;
            ++c;
        }
        ans -= cnt[c] - 1;
    }
    printf("%I64d\n", ans);
    return 0;
}