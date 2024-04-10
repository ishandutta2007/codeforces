#include <bits/stdc++.h>

using namespace std;

const int max_n = 111111;

struct tree {
    int p, mod, a[4 * max_n], f[4 * max_n], pw[max_n], sum[max_n];
    void build(int P, int Mod) {
        p = P;
        mod = Mod;
        pw[0] = 1;
        sum[0] = 1;
        for (int i = 1; i < max_n; ++i) {
            pw[i] = (1LL * pw[i - 1] * p) % mod;
            sum[i] = (sum[i - 1] + pw[i]) % mod;
        }
        memset(f, -1, sizeof(f));
    }
    void push(int v, int l, int r) {
        int mid = (l + r) / 2;
        if (f[v] != -1) {
            f[2 * v] = f[2 * v + 1] = f[v];
            a[2 * v] = (1LL * sum[mid - l] * f[v]) % mod;
            a[2 * v + 1] = (1LL * sum[r - mid - 1] * f[v]) % mod;
            f[v] = -1;
        }
    }
    void update(int v, int tl, int tr, int l, int r, int x) {
        //cout << v << " " << tl << " " << tr << "   " << l << " " << r << " " << x << endl;
        if (tl == l && tr == r) {
            f[v] = x;
            a[v] = (1LL * sum[r - l] * x) % mod;
            return;
        }
        push(v, tl, tr);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, x);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, x);
        } else {
            update(2 * v, tl, mid, l, mid, x);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, x);
        }
        a[v] = (1LL * a[2 * v] * pw[tr - mid] + a[2 * v + 1]) % mod;
    }
    int get(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return a[v];
        }
        push(v, tl, tr);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get(2 * v + 1, mid + 1, tr, l, r);
        } else {
            return (1LL * get(2 * v, tl, mid, l, mid) * pw[r - mid] + get(2 * v + 1, mid + 1, tr, mid + 1, r)) % mod;
        }
    }
};

int n, m, k;
char s[max_n];
tree t[3];
vector<int> v[3][max_n];

bool ok(int f, int l, int r, int d) {
    int H = t[f].get(1, 0, n - 1, l, r);
    int h = t[f].get(1, 0, n - 1, l, l + d - 1);
    int cnt = (r - l + 1) / d;
    int sum = v[f][d][cnt - 1];
    h = (1LL * sum * h) % t[f].mod;
    h = (1LL * h * t[f].pw[(r - l + 1) % d]) % t[f].mod;
    if ((r - l + 1) % d) {
        h = (h + t[f].get(1, 0, n - 1, l, r - cnt * d)) % t[f].mod;
    }
    return h == H;
}

void build(int f) {
    for (int d = 1; d <= n; ++d) {
        int sum = 0;
        for (int i = 0; i < n; i += d) {
            sum = (sum + t[f].pw[i]) % t[f].mod;
            v[f][d].push_back(sum);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d%s", &n, &m, &k, s);
    t[0].build(39, 1000000007);
    t[1].build(41, 1000000009);
    t[2].build(29, 1043540923);
    for (int i = 0; i < n; ++i) {
        t[0].update(1, 0, n - 1, i, i, s[i] - '0' + 1);
        t[1].update(1, 0, n - 1, i, i, s[i] - '0' + 1);
        t[2].update(1, 0, n - 1, i, i, s[i] - '0' + 1);
    }
    build(0);
    build(1);
    build(2);
    m += k;
    while (m--) {
        int tp, l, r, d;
        scanf("%d%d%d%d", &tp, &l, &r, &d);
        --l;
        --r;
        if (tp == 1) {
            t[0].update(1, 0, n - 1, l, r, d + 1);
            t[1].update(1, 0, n - 1, l, r, d + 1);
            t[2].update(1, 0, n - 1, l, r, d + 1);
        } else {
            if (ok(0, l, r, d) && ok(1, l, r, d) && ok(2, l, r, d)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}