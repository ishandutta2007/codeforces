#include <bits/stdc++.h>

using namespace std;

const int max_n = 500555, inf = 1000111222;

struct tree {
    pair<long long, int> a[8 * max_n];
    long long f[8 * max_n];

    void build(int v, int l, int r) {
        if (l == r) {
            a[v] = {0, l};
            f[v] = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        a[v] = max(a[2 * v], a[2 * v + 1]);
    }

    void push(int v, int l, int r) {
        if (f[v] != 0) {
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            a[2 * v].first += f[v];
            a[2 * v + 1].first += f[v];
            f[v] = 0;
        }
    }
    void update(int v, int tl, int tr, int l, int r, int value) {
        if (tl == l && tr == r) {
            f[v] += value;
            a[v].first += value;
            return;
        }
        push(v, tl, tr);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        a[v] = max(a[2 * v], a[2 * v + 1]);
    }

    pair<long long, int> get_max(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return a[v];
        }
        push(v, tl, tr);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_max(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_max(2 * v + 1, mid + 1, tr, l, r);
        }
        return max(get_max(2 * v, tl, mid, l, mid), get_max(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

struct point {
    int x, y, c, l, r;

    void read() {
        scanf("%d%d%d", &x, &y, &c);
        l = min(x, y);
        r = max(x, y);
    }

    bool operator < (const point &p) const {
        return l > p.l;
    }
};

int n;
point p[max_n];
vector<int> v;
tree t;

int compress(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        p[i].read();
        v.push_back(p[i].l);
        v.push_back(p[i].r);
    }
    sort(p, p + n);
    sort(v.begin(), v.end());
    v.push_back(inf);
    v.erase(unique(v.begin(), v.end()), v.end());
    const int sz = v.size() - 1;
    t.build(1, 0, sz);
    for (int i = 0; i < v.size(); ++i) {
        t.update(1, 0, sz, i, i, -v[i]);
    }
    long long ans = 0;
    int l = inf, r = inf;
    for (int i = 0; i < n; ) {
        int pos = i;
        while (i < n && p[i].l == p[pos].l) {
            t.update(1, 0, sz, compress(p[i].r), sz, p[i].c);
            //cout << p[i].l << " " << p[i].r << " " << p[i].c << endl;
            ++i;
        }
        auto mx = t.get_max(1, 0, sz, compress(p[pos].l), sz);
        long long res = mx.first + p[pos].l;
        //cout << p[pos].l << ", res = " << res << ",   " << mx.second << endl;
        if (ans < res) {
            ans = res;
            l = p[pos].l;
            r = v[mx.second];
        }
    }
    printf("%I64d\n%d %d %d %d\n", ans, l, l, r, r);
    return 0;
}