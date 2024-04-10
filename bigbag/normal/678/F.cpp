#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const long long inf = 4000111222000111222LL;

struct Line {
    long long k, b;

    Line(long long k = 0, long long b = 0): k(k), b(b) {
    }

    long long get_value(long long x) const {
        return k * x + b;
    }

    bool operator < (const Line &l) const {
        return k > l.k || (k == l.k && b < l.b);
    }
};

long long intersection(const Line &l1, const Line &l2) {
    long long a = l2.b - l1.b;
    long long b = l1.k - l2.k;
    return a / b - (a < 0 && a % b);
    return a / b - ((a ^ b) < 0 && a % b);
}

template<int x_increase>
struct LineContainer : vector<Line> {
    size_t pos = 0;

    void clear() {
        vector<Line>::clear();
        pos = 0;
    }

    void add(const Line &l) {
        if (!empty()){
            assert(back().k >= l.k);
            if (back().k == l.k) {
                if (l.b >= back().b) {
                    return;
                }
                pop_back();
            }
            while (size() >= 2 && intersection(at(size() - 2), l) <= intersection(at(size() - 2), back())) {
                pop_back();
            }
        }
        push_back(l);
    }

    long long get_min(long long x) {
        if (empty()) {
            return inf;
        }
        if (x_increase == 1) {
            pos = min(pos, size() - 1);
            while (pos + 1 < size() && at(pos).get_value(x) > at(pos + 1).get_value(x)) {
                ++pos;
            }
            return at(pos).get_value(x);
        } else if (x_increase == -1) {
            while (size() >= 2 && back().get_value(x) > at(size() - 2).get_value(x)) {
                pop_back();
            }
            return back().get_value(x);
        } else {
            int l = -1, r = size() - 1;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (x <= intersection(at(mid), at(mid + 1))) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            return at(r).get_value(x);
        }
        return this->front().get_value(x);
    }
};

const int max_n = 300333;

struct segment_tree {
    LineContainer<0> a[4 * max_n];

    void update(int v, int tl, int tr, int l, int r, const Line &line) {
        if (tl == l && tr == r) {
            a[v].add(line);
            return;
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, line);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, line);
        } else {
            update(2 * v, tl, mid, l, mid, line);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, line);
        }
    }

    long long get_min(int v, int tl, int tr, int pos, long long x) {
        long long res = a[v].get_min(x);
        if (tl == tr) {
            return res;
        }
        int mid = (tl + tr) / 2;
        if (pos <= mid) {
            res = min(res, get_min(2 * v, tl, mid, pos, x));
        } else {
            res = min(res, get_min(2 * v + 1, mid + 1, tr, pos, x));
        }
        return res;
    }
};

int n, tp[max_n], a[max_n], b[max_n], r[max_n];
long long ans[max_n];
vector<pair<Line, pair<int, int>>> all;
vector<pair<int, int>> q;
segment_tree t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tp[i]);
        if (tp[i] == 1) {
            scanf("%d%d", &a[i], &b[i]);
            r[i] = n - 1;
        } else if (tp[i] == 2) {
            scanf("%d", &a[i]);
            --a[i];
            r[a[i]] = i;
        } else {
            scanf("%d", &a[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (tp[i] == 1) {
            all.push_back({{-a[i], -b[i]}, {i, r[i]}});
        } else if (tp[i] == 3) {
            q.push_back({a[i], i});
        }
    }
    sort(all.begin(), all.end());
    //sort(q.begin(), q.end());
    for (const auto &p : all) {
        t.update(1, 0, n - 1, p.second.first, p.second.second, p.first);
    }
    for (const auto &p : q) {
        ans[p.second] = t.get_min(1, 0, n - 1, p.second, p.first);
    }
    for (int i = 0; i < n; ++i) {
        if (tp[i] == 3) {
            if (ans[i] == inf) {
                puts("EMPTY SET");
            } else {
                printf("%I64d\n", -ans[i]);
            }
        }
    }
    return 0;
}