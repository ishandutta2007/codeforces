#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

template<typename T1, typename T2>
ostream &operator << (ostream &os, const pair<T1, T2> &p) {
    os << "(" << p.first << " " << p.second << ")";
    return os;
}

template<typename T>
ostream &operator << (ostream &os, const vector<T> &v) {
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        if (i) {
            os << " ";
        }
        os << v[i];
    }
    os << "]";
    return os;
}

int mn;

struct node {
    int l, r;
    vector<pair<int, int>> v1, v2;
    long long cnt;
};

node merge(const node &a, const node &b) {
    node res;

    res.v1 = b.v1;
    int cur = b.v1.back().second;
    for (const pair<int, int> &p : a.v1) {
        if (cur < (cur | p.second)) {
            cur |= p.second;
            res.v1.push_back({p.first, cur});
        }
    }

    res.v2 = a.v2;
    cur = a.v2.back().second;
    for (const pair<int, int> &p : b.v2) {
        if (cur < (cur | p.second)) {
            cur |= p.second;
            res.v2.push_back({p.first, cur});
        }
    }

    res.l = a.l;
    res.r = b.r;
    res.cnt = a.cnt + b.cnt;

    int pos = b.v2.size();
    for (int i = 0; i < a.v1.size(); ++i) {
        while (pos > 0 && (a.v1[i].second | b.v2[pos - 1].second) >= mn) {
            --pos;
        }
        int from = a.l - 1;
        if (i + 1 < a.v1.size()) {
            from = a.v1[i + 1].first;
        }
        if (pos < b.v2.size()) {
            res.cnt += 1LL * (a.v1[i].first - from) * (b.r - b.v2[pos].first + 1);
        }
    }

    return res;
}

bool get_bit(int mask, int pos) {
    return (bool) (mask & (1 << pos));
}

node get_node(int pos, int x) {
    node res;
    res.v1.push_back({pos, x});
    res.v2.push_back({pos, x});
    res.cnt = (x >= mn);
    res.l = res.r = pos;
    return res;
}

struct tree {
    node a[4 * max_n];

    void build(int v, int l, int r, int arr[]) {
        if (l == r) {
            a[v] = get_node(l, arr[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, arr);
        build(2 * v + 1, mid + 1, r, arr);
        a[v] = merge(a[2 * v], a[2 * v + 1]);
    }

    void update(int v, int l, int r, int pos, int x) {
        if (l == r) {
            a[v] = get_node(l, x);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(2 * v, l, mid, pos, x);
        } else {
            update(2 * v + 1, mid + 1, r, pos, x);
        }
        a[v] = merge(a[2 * v], a[2 * v + 1]);
    }

    node get(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return a[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get(2 * v + 1, mid + 1, tr, l, r);
        }
        return merge(get(2 * v, tl, mid, l, mid), get(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

int n, m, a[max_n];
tree t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &mn);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    t.build(1, 0, n - 1, a);
    while (m--) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int pos, value;
            scanf("%d%d", &pos, &value);
            --pos;
            t.update(1, 0, n - 1, pos, value);
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            --l;
            --r;
            printf("%I64d\n", t.get(1, 0, n - 1, l, r).cnt);
        }
    }
    return 0;
}