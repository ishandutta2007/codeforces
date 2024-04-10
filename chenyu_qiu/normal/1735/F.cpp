#include <bits/stdc++.h>
using namespace std;

#define double long double
const double eps = 1e-10;

const int N = 300005;
double sum[N << 2], sum1[N << 2];
pair<int, int> coef[N];

void push_up(int p) {
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
    sum1[p] = sum1[p << 1] + sum1[p << 1 | 1];
}

void modify(int p, int l, int r, int pos, const pair<int, int> &val) {
    if (l == r) {
        sum[p] += val.first;
        sum1[p] += val.second;
        return;
    }
    int mid = (l + r) >> 1;
    if (mid >= pos) {
        modify(p << 1, l, mid, pos, val);
    } else {
        modify(p << 1 | 1, mid + 1, r, pos, val);
    }
    push_up(p);
}

inline bool smaller(double x, double y) {
    return y - x >= eps;
}
inline bool zero(double x) {
    return abs(x) <= eps;
}

void del_pre(int p, int l, int r, double x) {
    if (zero(x)) {
        return;
    }
    if (l == r) {
        sum1[p] -= x;
        sum[p] -= x * coef[l].first / coef[l].second;
        return;
    }
    int mid = (l + r) >> 1;
    if (smaller(x, sum1[p << 1])) {
        del_pre(p << 1, l, mid, x);
    } else {
        del_pre(p << 1 | 1, mid + 1, r, x - sum1[p << 1]);
        del_pre(p << 1, l, mid, sum1[p << 1]);
    }
    push_up(p);
}

void del_suf(int p, int l, int r, double x) {
    if (zero(x)) {
        return;
    }
    if (l == r) {
        sum[p] -= x;
        sum1[p] -= x * coef[l].second / coef[l].first;
        return;
    }
    int mid = (l + r) >> 1;
    if (smaller(x, sum[p << 1 | 1])) {
        del_suf(p << 1 | 1, mid + 1, r, x);
    } else {
        del_suf(p << 1, l, mid, x - sum[p << 1 | 1]);
        del_suf(p << 1 | 1, mid + 1, r, sum[p << 1 | 1]);
    }
    push_up(p);
}

void solve() {
    int n;
    double a, b;
    cin >> n >> a >> b;
    swap(a, b);

    vector<int> p(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<int> c(n);
    iota(c.begin(), c.end(), 0);
    sort(c.begin(), c.end(), [&](int x, int y) {
        return 1ll * p[x] * q[y] < 1ll * p[y] * q[x];
    });

    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        coef[i] = {p[c[i]], q[c[i]]};
        pos[c[i]] = i;
    }

    fill(sum, sum + n * 4 + 1, 0);
    fill(sum1, sum1 + n * 4 + 1, 0);

    for (int i = 0; i < n; ++i) {
        modify(1, 0, n - 1, pos[i], make_pair(2 * p[i], 2 * q[i]));
        a += p[i];
        b -= q[i];
        double prv = sum[1];
        if (smaller(b, 0)) {
            del_pre(1, 0, n - 1, -b);
            b = 0;
            a -= prv - sum[1];
        }
        if (smaller(a, sum[1])) {
            del_suf(1, 0, n - 1, sum[1] - a);
        }
        cout << b + sum1[1] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;

    while (t--) { 
        solve();
    }

    return 0;
}