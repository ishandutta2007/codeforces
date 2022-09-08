#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

struct tree {
    enum {
        MIN,
        MAX
    };

    int tp, a[4 * max_n];

    tree(int tp): tp(tp) {
        for (int i = 0; i < 4 * max_n; ++i) {
            if (tp == MIN) {
                a[i] = inf;
            } else {
                a[i] = -inf;
            }
        }
    }

    int func(int x, int y) const {
        if (tp == MIN) {
            return min(x, y);
        }
        return max(x, y);
    }

    void update(int v, int tl, int tr, int pos, int x) {
        a[v] = func(a[v], x);
        if (tl == tr) {
            return;
        }
        int mid = (tl + tr) / 2;
        if (pos <= mid) {
            update(2 * v, tl, mid, pos, x);
        } else {
            update(2 * v + 1, mid + 1, tr, pos, x);
        }
    }

    int get(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return a[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get(2 * v + 1, mid + 1, tr, l, r);
        }
        return func(get(2 * v, tl, mid, l, mid), get(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

struct point {
    int x, y, z;

    point() {
    }

    point(int x, int y, int z): x(x), y(y), z(z) {
    }

    void read() {
        scanf("%d%d%d", &x, &y, &z);
    }

    bool operator <= (const point &p) const {
        return x <= p.x && y <= p.y && z <= p.z;
    }

    friend ostream& operator << (ostream &os, const point &p) {
        os << "(" << p.x << " " << p.y << " " << p.z << ")";
        return os;
    }
};

point minp(const point &a, const point &b) {
    return point(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
}

point maxp(const point &a, const point &b) {
    return point(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
}

struct segment {
    point l, r;
    int id;

    segment(const point &l, const point &r, int id): l(l), r(r), id(id) {
    }

    friend ostream& operator << (ostream &os, const segment &s) {
        os << "(" << s.l << " " << s.r << " " << s.id << ")";
        return os;
    }
};

int n, m, k, ans[max_n];
point MX, opened[max_n], closed[max_n], query[max_n];
point mn(inf, inf, inf), mx(-inf, -inf, -inf);
vector<segment> a, b;
tree tmn(tree::MIN);
tree tmx(tree::MAX);

bool cmpx(const point &a, const point &b) {
    return a.x < b.x;
}

void add(const point &p) {
    //cout << "+ " << p << endl;
    if (p.z >= mn.z) {
        tmn.update(1, 1, MX.y, p.y, p.z);
    }
    if (p.z <= mx.z) {
        tmx.update(1, 1, MX.y, p.y, p.z);
    }
}

void process_a() {
    tmn = tree(tree::MIN);
    tmx = tree(tree::MAX);
    sort(closed, closed + m, cmpx);
    reverse(closed, closed + m);
    int pos = m;
    for (int i = 0; i < m; ++i) {
        if (closed[i].x <= mx.x) {
            pos = i;
            break;
        }
    }
    for (const segment &s : a) {
        while (pos < m && closed[pos].x >= s.l.x) {
            add(closed[pos]);
            ++pos;
        }
        int z = tmn.get(1, 1, MX.y, s.l.y, s.r.y);
        if (s.l.z <= z && z <= s.r.z) {
            ans[s.id] = -1;
        }
        z = tmx.get(1, 1, MX.y, s.l.y, s.r.y);
        if (s.l.z <= z && z <= s.r.z) {
            ans[s.id] = -1;
        }
    }
}

void process_b() {
    tmn = tree(tree::MIN);
    tmx = tree(tree::MAX);
    sort(closed, closed + m, cmpx);
    int pos = m;
    for (int i = 0; i < m; ++i) {
        if (closed[i].x >= mn.x) {
            pos = i;
            break;
        }
    }
    for (const segment &s : b) {
        while (pos < m && closed[pos].x <= s.r.x) {
            add(closed[pos]);
            ++pos;
        }
        int z = tmn.get(1, 1, MX.y, s.l.y, s.r.y);
        if (s.l.z <= z && z <= s.r.z) {
            ans[s.id] = -1;
        }
        z = tmx.get(1, 1, MX.y, s.l.y, s.r.y);
        if (s.l.z <= z && z <= s.r.z) {
            ans[s.id] = -1;
        }
    }
}

bool cmpa(const segment &a, const segment &b) {
    return a.l.x > b.l.x;
}

bool cmpb(const segment &a, const segment &b) {
    return a.r.x < b.r.x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    MX.read();
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        opened[i].read();
        mn = minp(mn, opened[i]);
        mx = maxp(mx, opened[i]);
    }
    for (int i = 0; i < m; ++i) {
        closed[i].read();
        if (mn <= closed[i] && closed[i] <= mx) {
            puts("INCORRECT");
            return 0;
        }
    }
    puts("CORRECT");
    for (int i = 0; i < k; ++i) {
        query[i].read();
        if (mn <= query[i] && query[i] <= mx) {
            ans[i] = 1;
        } else {
            point rmn = minp(mn, query[i]);
            point rmx = maxp(mx, query[i]);
            segment s(rmn, rmx, i);
            if (s.r.x == mx.x) {
                a.push_back(s);
            } else {
                b.push_back(s);
            }
        }
    }
    sort(a.begin(), a.end(), cmpa);
    sort(b.begin(), b.end(), cmpb);
    process_a();
    process_b();
    for (int i = 0; i < k; ++i) {
        if (ans[i] == 1) {
            puts("OPEN");
        } else if (ans[i] == -1) {
            puts("CLOSED");
        } else {
            puts("UNKNOWN");
        }
    }
    return 0;
}