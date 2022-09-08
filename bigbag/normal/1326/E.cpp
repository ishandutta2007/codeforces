#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

struct tree {
    int a[4 * max_n], f[4 * max_n];

    tree() {
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
    }

    void push(int v, int l, int r) {
        if (f[v] != 0) {
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            a[2 * v] += f[v];
            a[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, int value) {
        if (tl == l && tr == r) {
            f[v] += value;
            a[v] += value;
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
        a[v] = min(a[2 * v], a[2 * v + 1]);
    }

    int get_min(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return a[v];
        }
        push(v, tl, tr);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_min(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_min(2 * v + 1, mid + 1, tr, l, r);
        }
        return min(get_min(2 * v, tl, mid, l, mid), get_min(2 * v + 1, mid + 1, tr, mid + 1, r));
    }

    void write(int v, int l, int r) {
        if (l == r) {
            cout << l << ' ' << r << " - " << a[v] << " (" << f[v] << ")\n";
            return;
        }
        cout << l << ' ' << r << " - " << a[v] << " (" << f[v] << ")\n";
        int mid = (l + r) / 2;
        write(2 * v, l, mid);
        write(2 * v + 1, mid + 1, r);
    }
};

int n, a[max_n], b[max_n], pos[max_n], ans[max_n];
tree t, t2;

int func(int p) {
    if (!p) {
        return 0;
    }
    return min(0, t2.get_min(1, 0, n - 1, 0, p - 1) - t2.get_min(1, 0, n - 1, p, p));
}

int func2(int p) {
    int subs = 0;
    if (p) {
        subs = t.get_min(1, 0, n - 1, p - 1, p - 1);
    }
    return t.get_min(1, 0, n - 1, p, n - 1) - subs;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
        pos[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        --b[i];
    }
    int cur = 0;
    for (int x = n - 1; x >= 0; --x) {
        int last = cur;
        //cout << "x = " << x + 1 << endl;
        while (cur < n && func2(pos[x]) >= func(pos[x])) {
            t.update(1, 0, n - 1, b[cur], n - 1, -1);
            t2.update(1, 0, n - 1, 0, b[cur], 1);
            //cout << cur << " " << func2(pos[x]) << " " << func(pos[x]) << endl;
            ++cur;
        }
        t.update(1, 0, n - 1, pos[x], n - 1, 1);
        t2.update(1, 0, n - 1, 0, pos[x], -1);
        for (int i = last; i < cur; ++i) {
            ans[i] = x;
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i] + 1);
    }
    return 0;
}