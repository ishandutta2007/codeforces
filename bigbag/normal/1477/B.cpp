/**
 *  created: 28/01/2021, 16:54:22
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

template<typename T>
struct segment_tree {
    static const T default_value = -1012345678;

    T f[4 * max_n];
    T sum[4 * max_n];

    void build(int v, int l, int r, const string &a) {
        f[v] = default_value;
        if (l == r) {
            sum[v] = a[l] - '0';
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    void push(int v, int l, int r, int mid) {
        if (f[v] != default_value) {
            sum[2 * v] = f[v] * (mid - l + 1);
            sum[2 * v + 1] = f[v] * (r - mid);
            f[2 * v] = f[v];
            f[2 * v + 1] = f[v];
            f[v] = default_value;
        }
    }

    void update(int v, int tl, int tr, int l, int r, T value) {
        if (tl == l && tr == r) {
            f[v] = value;
            sum[v] = value * (r - l + 1);
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
        sum[v] = sum[2 * v] + sum[2 * v + 1];
    }

    T get_sum(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return sum[v];
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return get_sum(2 * v, tl, mid, l, mid) + get_sum(2 * v + 1, mid + 1, tr, mid + 1, r);
    }
};

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int t, n, q, l[max_n], r[max_n];
string a, b;
segment_tree<int> st;

bool check() {
    for (int i = q - 1; i >= 0; --i) {
        int sum = st.get_sum(1, 0, n - 1, l[i], r[i]);
        if (sum * 2 == r[i] - l[i] + 1) {
            return false;
        }
        if (sum * 2 < r[i] - l[i] + 1) {
            st.update(1, 0, n - 1, l[i], r[i], 0);
        } else {
            st.update(1, 0, n - 1, l[i], r[i], 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (st.get_sum(1, 0, n - 1, i, i) != a[i] - '0') {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &q);
        a = read();
        b = read();
        for (int i = 0; i < q; ++i) {
            scanf("%d%d", &l[i], &r[i]);
            --l[i];
            --r[i];
        }
        st.build(1, 0, n - 1, b);
        if (check()) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}