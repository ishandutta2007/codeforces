#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 200222, mod = 998244353;

struct matrix {
    int n, m, v[2][2];
    matrix() {
    }
    matrix(int n, int m) : n(n), m(m) {
        memset(v, 0, sizeof(v));
    }
    matrix operator * (const matrix &q) const {
        matrix res(n, q.m);
        for (int i = 0; i < res.n; ++i) {
            for (int j = 0; j < res.m; ++j) {
                long long sum = 0;
                for (int k = 0; k < m; ++k) {
                    sum += 1LL * v[i][k] * q.v[k][j];
                }
                res.v[i][j] = sum % mod;
            }
        }
        return res;
    }
    matrix operator + (const matrix &q) const {
        matrix res(n, m);
        if (n != q.n || m != q.m) {
            cout << "FAIL" << endl;
            exit(0);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res.v[i][j] = (v[i][j] + q.v[i][j]) % mod;
            }
        }
        return res;
    }
    bool operator == (const matrix &q) const {
        if (n == q.n && m == q.m) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (v[i][j] != q.v[i][j]) {
                        return false;
                    }
                }
            }
            return true;
        }
        return false;
    }
    void write() const {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
};

matrix ONE(2, 2);
matrix INC(2, 2);
matrix MULT(2, 2);

void init() {
    ONE.v[0][0] = 1;
    ONE.v[0][1] = 0;
    ONE.v[1][0] = 0;
    ONE.v[1][1] = 1;

    INC.v[0][0] = 1;
    INC.v[0][1] = 0;
    INC.v[1][0] = 1;
    INC.v[1][1] = 1;

    MULT.v[0][0] = 2;
    MULT.v[0][1] = 0;
    MULT.v[1][0] = 0;
    MULT.v[1][1] = 1;
}

struct tree {
    matrix a[4 * max_n], f[4 * max_n];
    void build(int v, int l, int r) {
        f[v] = ONE;
        if (l == r) {
            a[v] = matrix(1, 2);
            a[v].v[0][0] = 0;
            a[v].v[0][1] = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        a[v] = a[2 * v] + a[2 * v + 1];
    }
    void push(int v, int l, int r) {
        if (l != r && !(f[v] == ONE)) {
            f[2 * v] = f[2 * v] * f[v];
            f[2 * v + 1] = f[2 * v + 1] * f[v];
            a[2 * v] = a[2 * v] * f[v];
            a[2 * v + 1] = a[2 * v + 1] * f[v];
            f[v] = ONE;
        }
    }
    void update(int v, int tl, int tr, int l, int r, const matrix &q) {
        if (tl == l && tr == r) {
            a[v] = a[v] * q;
            f[v] = f[v] * q;
            //q.write();
            return;
        }
        push(v, tl, tr);
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, q);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, q);
        } else {
            update(2 * v, tl, mid, l, mid, q);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, q);
        }
        a[v] = a[2 * v] + a[2 * v + 1];
    }
    matrix get_sum(int v, int tl, int tr, int l, int r) {
        //cout << v << " " << tl << " " << tr << " " << l << " " << r << ":   ";
        //a[v].write();
        push(v, tl, tr);
        if (tl == l && tr == r) {
            return a[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_sum(2 * v, tl, mid, l, r);
        }
        if (l > mid) {
            return get_sum(2 * v + 1, mid + 1, tr, l, r);
        }
        return get_sum(2 * v, tl, mid, l, mid) + get_sum(2 * v + 1, mid + 1, tr, mid + 1, r);
    }
};

int n, q, tp[max_n], l[max_n], r[max_n], x[max_n];
set<pair<int, int>> all[max_n];
vector<pair<int, int>> v;
tree t;

void inc(int l, int r) {
    t.update(1, 1, n, l, r, INC);
    //cout << l << " " << r << " + " << endl;
}

void mult(int l, int r) {
    t.update(1, 1, n, l, r, MULT);
    //cout << l << " " << r << " * " << endl;
}

void compress() {
    sort(v.begin(), v.end());
    int num = 0;
    for (int i = 0; i < v.size();) {
        int cur = i;
        while (cur < v.size() && v[cur].first == v[i].first) {
            x[v[cur].second] = num;
            ++cur;
        }
        ++num;
        i = cur;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    init();
    scanf("%d%d", &n, &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d", &tp[i]);
        if (tp[i] == 1) {
            scanf("%d%d%d", &l[i], &r[i], &x[i]);
            v.push_back({x[i], i});
        } else {
            scanf("%d%d", &l[i], &r[i]);
        }
    }
    compress();
    t.build(1, 1, n);
    for (int i = 0; i < q; ++i) {
        if (tp[i] == 1) {
            set<pair<int, int>>::iterator it = all[x[i]].lower_bound(make_pair(l[i], -1));
            if (it != all[x[i]].begin()) {
                --it;
            }
            auto en = all[x[i]].end();
            if (it != en && it->second < l[i]) {
                ++it;
            }
            if (it != en) {
                auto start = it;
                int lastr = l[i] - 1;
                while (it != en && it->first <= r[i]) {
                    if (lastr + 1 < it->first) {
                        inc(lastr + 1, it->first - 1);
                    }
                    lastr = it->second;
                    mult(max(l[i], it->first), min(r[i], lastr));
                    ++it;
                }
                if (lastr < r[i]) {
                    inc(lastr + 1, r[i]);
                }
                all[x[i]].erase(start, it);
                all[x[i]].insert({min(l[i], start->first), max(r[i], lastr)});
            } else {
                inc(l[i], r[i]);
                all[x[i]].insert({l[i], r[i]});
            }
        } else {
            const matrix &ans = t.get_sum(1, 1, n, l[i], r[i]);
            printf("%d\n", ans.v[0][0]);
        }
    }
    return 0;
}