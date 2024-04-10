#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222;
const long long inf = 2000111222000111222LL;

struct line {
    int k;
    long long b;

    line() {
    }

    line(int k, long long b): k(k), b(b) {
    }

    long long get(int x) const {
        return 1LL * k * x + b;
    }

    bool operator < (const line &l) const {
        return k < l.k || k == l.k && b < l.b;
    }
};

pair<long long, int> get_intersection(const line &l1, const line &l2) {
    return {l1.b - l2.b, l2.k - l1.k};
}

bool cmp(const pair<long long, int> &a, const pair<long long, int> &b) {
    //return 1.0 * a.first / a.second < 1.0 * b.first / b.second;
    if (a.first < 0 && b.first < 0) {
        return cmp({-b.first, b.second}, {-a.first, a.second});
    }
    if (a.first < 0) {
        return true;
    }
    if (b.first < 0) {
        return false;
    }
    long long q = a.first / a.second;
    long long w = b.first / b.second;
    if (q != w) {
        return q < w;
    }
    return 1LL * (a.first % a.second) * b.second < 1LL * (b.first % b.second) * a.second;
}

void add_line(vector<line> &v, const line &l) {
    while (!v.empty()) {
        if (v.back().k == l.k) {
            if (l.b <= v.back().b) {
                return;
            }
            v.pop_back();
            //cout << "-" << endl;
            continue;
        }
        if (v.size() == 1) {
            break;
        }
        if (cmp(get_intersection(v[v.size() - 2], l), get_intersection(v[v.size() - 2], v.back()))) {
            v.pop_back();
            //cout << "-" << endl;
        } else {
            break;
        }
    }
    v.push_back(l);
    //cout << "+ " << l.k << " " << l.b << endl;
}

int n, q, a[max_n], b[max_n], na[max_n], nb[max_n];
int l[max_n], r[max_n];
vector<int> g[max_n], order;
line l1[max_n], l2[max_n];

void dfs(int v) {
    l[v] = order.size();
    order.push_back(v);
    for (int to : g[v]) {
        a[to] += a[v];
        b[to] += b[v];
        dfs(to);
    }
    r[v] = order.size() - 1;
}

const int bsize = 233;
const int max_blocks = max_n / bsize + 2;

int num[max_n];
int lb[max_blocks], rb[max_blocks];

void init() {
    for (int i = 0; i < max_blocks; ++i) {
        lb[i] = min(n, i * bsize);
        rb[i] = min(n, (i + 1) * bsize);
        for (int j = lb[i]; j < rb[i]; ++j) {
            num[j] = i;
        }
    }
}

long long get_max_line(const vector<line> &v, int x, int &pos) {
    pos = min(pos, (int) v.size() - 1);
    while (pos + 1 < v.size() && v[pos].get(x) < v[pos + 1].get(x)) {
        ++pos;
    }
    return v[pos].get(x);
}

line *pt;

bool cmp2(int a, int b) {
    return pt[a] < pt[b];
}

struct sqrt_decomp {
    line ln[max_n];
    int add[max_blocks], opt[max_blocks];
    vector<line> v[max_blocks];
    vector<int> order[max_blocks];

    void init(line l[max_n]) {
        for (int i = 0; i < n; ++i) {
            ln[i] = l[i];
        }
        pt = ln;
        for (int i = 0; i < max_blocks; ++i) {
            for (int j = lb[i]; j < rb[i]; ++j) {
                order[i].push_back(j);
            }
            sort(order[i].begin(), order[i].end(), cmp2);
            opt[i] = 0;
            rebuild(i);
        }
    }

    void rebuild(int b) {
        v[b].clear();
        for (int i : order[b]) {
            add_line(v[b], ln[i]);
        }
        opt[b] = 0;
    }

    void update(int l, int r, int x) {
        //cout << "+ " << l << " " << r << " " << x << endl;
        const int n1 = num[l];
        const int n2 = num[r];
        if (n1 == n2) {
            for (int i = l; i <= r; ++i) {
                ln[i].b += 1LL * ln[i].k * x;
                //cout << "@" << ln[i].get(0) << endl;
            }
            rebuild(n1);
            return;
        }
        for (int i = l; i < rb[n1]; ++i) {
            ln[i].b += 1LL * ln[i].k * x;
        }
        for (int i = lb[n2]; i <= r; ++i) {
            ln[i].b += 1LL * ln[i].k * x;
        }
        rebuild(n1);
        rebuild(n2);
        for (int i = n1 + 1; i < n2; ++i) {
            add[i] += x;
        }
    }

    long long get_max(int l, int r) {
        const int n1 = num[l];
        const int n2 = num[r];
        if (n1 == n2) {
            long long res = -inf;
            for (int i = l; i <= r; ++i) {
                res = max(res, ln[i].get(add[n1]));
            }
            return res;
        }
        long long res = -inf;
        for (int i = l; i < rb[n1]; ++i) {
            res = max(res, ln[i].get(add[n1]));
        }
        for (int i = lb[n2]; i <= r; ++i) {
            res = max(res, ln[i].get(add[n2]));
        }
        for (int i = n1 + 1; i < n2; ++i) {
            res = max(res, get_max_line(v[i], add[i], opt[i]));
        }
        return res;
    }
};

sqrt_decomp s1, s2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; ++i) {
        int p;
        scanf("%d", &p);
        --p;
        g[p].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    dfs(0);
    for (int i = 0; i < n; ++i) {
        na[i] = a[order[i]];
        nb[i] = abs(b[order[i]]);
        l1[i] = {-nb[i], -1LL * nb[i] * na[i]};
        l2[i] = {nb[i], 1LL * nb[i] * na[i]};
    }
    init();
    s1.init(l1);
    s2.init(l2);
    while (q--) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int v, x;
            scanf("%d%d", &v, &x);
            --v;
            s1.update(l[v], r[v], x);
            s2.update(l[v], r[v], x);
        } else {
            int v;
            scanf("%d", &v);
            --v;
            long long mx = max(s1.get_max(l[v], r[v]),
                               s2.get_max(l[v], r[v]));
            printf("%I64d\n", mx);
        }
    }
    return 0;
}