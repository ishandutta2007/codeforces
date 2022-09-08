/**
 *  created: 05/09/2021, 17:57:31
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

template<typename T>
struct segment_tree {
    T sum[4 * max_n];

    void build(int v, int l, int r, T a[]) {
        if (l == r) {
            sum[v] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    void update(int v, int l, int r, int x, T value) {
        if (l == r) {
            sum[v] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            update(2 * v, l, mid, x, value);
        } else {
            update(2 * v + 1, mid + 1, r, x, value);
        }
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    T get_sum(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return sum[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return get_sum(2 * v, tl, mid, l, mid) + get_sum(2 * v + 1, mid + 1, tr, mid + 1, r);
    }
};

int n, m, a[max_n], f[max_n];
set<int> q;
segment_tree<long long> st;

long long c2(long long x) {
    return x * (x + 1) / 2;
}

void update(int i) {
    int nf = a[i] > a[i + 1];
    if (nf != f[i]) {
        int pr = *prev(q.lower_bound(i));
        int nxt = *q.upper_bound(i);
        if (f[i] == 0) {
            st.update(1, 0, n, nxt, c2(nxt - i));
            st.update(1, 0, n, i, c2(i - pr));
            q.insert(i);
        } else {
            st.update(1, 0, n, nxt, c2(nxt - pr));
            st.update(1, 0, n, i, 0);
            q.erase(i);
        }
        f[i] = nf;
    }
}

long long solve(int l, int r) {
    long long res = st.get_sum(1, 0, n, l, r);
    int first = *q.lower_bound(l);
    if (first > r) {
        return c2(r - l + 1);
    }
    res -= st.get_sum(1, 0, n, first, first);
    res += c2(first - l + 1);
    int last = *prev(q.upper_bound(r));
    res += c2(r - last);
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    ++n;
    for (int i = 1; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    a[0] = inf;
    q.insert(0);
    q.insert(n);
    for (int i = 1; i < n; ++i) {
        update(i);
    }
    while (m--) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int pos, x;
            scanf("%d%d", &pos, &x);
            a[pos] = x;
            update(pos - 1);
            update(pos);
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            long long ans = solve(l, r);
            printf("%lld\n", ans);
        }
    }
    return 0;
}