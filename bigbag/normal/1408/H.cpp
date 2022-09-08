#include <bits/stdc++.h>

using namespace std;

const int max_n = 500555, inf = 1000111222;

template<typename T>
struct segment_tree {
    T f[4 * max_n];
    T mn[4 * max_n];

    void build(int v, int l, int r) {
        f[v] = 0;
        if (l == r) {
            mn[v] = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }

    void push(int v, int l, int r, int mid) {
        if (f[v]) {
            mn[2 * v] += f[v];
            mn[2 * v + 1] += f[v];
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, T value) {
        if (tl == l && tr == r) {
            f[v] += value;
            mn[v] += value;
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

    T get_min(int v, int tl, int tr, int l, int r) {
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

int t, n, a[max_n], last[max_n];
bool f[max_n];
vector<int> v;
segment_tree<int> st;

void clr() {
    v.clear();
}

int check(int cnt) {
    memset(f, 0, n);
    for (int i = 0; i < cnt; ++i) {
        f[v[v.size() - 1 - i]] = 1;
    }
    memset(last, -1, (n + 1) * 4);
    st.build(1, 0, n - 1);
    int pos = 0;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i]) {
            st.update(1, 0, n - 1, last[a[i]] + 1, i, 1);
            last[a[i]] = i;
        } else if (f[i]) {
            st.update(1, 0, n - 1, 0, v[pos++], -1);
            res = min(res, st.get_min(1, 0, n - 1, 0, n - 1));
        }
    }
    return cnt + res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if (!a[i]) {
                v.push_back(i);
            }
        }
        printf("%d\n", check(v.size() / 2));
        clr();
    }
    return 0;
}