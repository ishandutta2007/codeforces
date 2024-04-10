#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;
const int max_v = 4 * max_n;

template<typename T>
struct segment_tree {
    T f[4 * max_n];
    pair<T, int> mn[4 * max_n];

    void build(int v, int l, int r, T a[]) {
        f[v] = 0;
        if (l == r) {
            mn[v] = {a[l], l};
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }

    void push(int v, int l, int r, int mid) {
        if (f[v]) {
            mn[2 * v].first += f[v];
            mn[2 * v + 1].first += f[v];
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, T value) {
        if (tl == l && tr == r) {
            f[v] += value;
            mn[v].first += value;
            return;
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }

    pair<T, int> get_min(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mn[v];
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            return get_min(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_min(2 * v + 1, mid + 1, tr, l, r);
        }
        return min(get_min(2 * v, tl, mid, l, mid), get_min(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

int n, q, a[max_n];
segment_tree<int> t;
vector<int> all[max_v];

void build(int v, int l, int r) {
    t.build(1, l, r, a);
    int cnt = 0, start = 0;
    all[v].reserve(r - l + 1);
    while (cnt < r - l + 1) {
        pair<int, int> p = t.mn[1];
        int add = max(0, p.first);
        start += add;
        t.update(1, l, r, l, r, -add);
        if (p.second < r) {
            t.update(1, l, r, p.second + 1, r, -1);
        }
        t.update(1, l, r, p.second, p.second, inf);
        ++cnt;
        all[v].push_back(start);
    }
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
}

int get(int v, int tl, int tr, int l, int r, int cnt) {
    if (tl == l && tr == r) {
        cnt += upper_bound(all[v].begin(), all[v].end(), cnt) - all[v].begin();
        return cnt;
    }
    int mid = (tl + tr) / 2;
    if (r <= mid) {
        return get(2 * v, tl, mid, l, r, cnt);
    } else if (l > mid) {
        return get(2 * v + 1, mid + 1, tr, l, r, cnt);
    }
    cnt = get(2 * v, tl, mid, l, mid, cnt);
    return get(2 * v + 1, mid + 1, tr, mid + 1, r, cnt);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
        a[i] = i - a[i];
        if (a[i] < 0) {
            a[i] = max_n;
        }
    }
    build(1, 0, n - 1);
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        r = n - 1 - r;
        int ans = get(1, 0, n - 1, l, r, 0);
        printf("%d\n", ans);
    }
    return 0;
}