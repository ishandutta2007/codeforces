#include <ctime>
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

const int max_n = 100111;
const long long inf = 1000111222000111222;

bool sort_by_k = true;

struct line {
    long long k;
    long long b;
    mutable long long x;
    line(long long k, long long b, long long x = 0): k(k), b(b), x(x) {
    }
    long long value(long long x) const {
        return k * x + b;
    }
    bool operator < (const line &l) const {
        return sort_by_k ? (k > l.k || k == l.k && b > l.b) : (x < l.x);
    }
};

ostream& operator << (ostream &os, const line &l) {
    os << "(k = " << l.k << ", b = " << l.b << ", x = " << l.x << ")";
    return os;
}

long long intersection(const line &l1, const line &l2) {
    long long a = l2.b - l1.b;
    long long b = l1.k - l2.k;
    return a / b - ((a ^ b) < 0 && a % b);
}

struct line_container;
ostream& operator << (ostream &os, const line_container &l);

struct line_container : set<line> {
    line_container() {
    }
    bool bad(iterator it, iterator nxt) {
        if (nxt == end()) {
            it->x = inf;
            return false;
        }
        it->x = intersection(*it, *nxt);
        return it->x >= nxt->x;
    }
    void add(const line &l) {
        auto ins = insert(l);
        if (!ins.second) {
            return;
        }
        iterator it = ins.first;
        iterator nxt = it;
        nxt++;
        if (nxt != end()) {
            if (it->k == nxt->k) {
                erase(it);
                return;
            }
            if (it != begin()) {
                iterator prev = it;
                --prev;
                if (prev->k != it->k && intersection(*prev, *it) >= intersection(*prev, *nxt)) {
                    erase(it);
                    return;
                }
            }
            while (bad(it, nxt)) {
                nxt = erase(nxt);
            }
        } else {
            it->x = inf;
        }
        if (it == begin()) {
            return;
        }
        iterator prev = it;
        --prev;
        while (it != begin()) {
            prev = it;
            --prev;
            if (prev->k == it->k) {
                erase(prev);
                continue;
            }
            bad(prev, it);
            if (prev == begin()) {
                break;
            }
            iterator prev2 = prev;
            --prev2;
            if (bad(prev2, prev)) {
                erase(prev);
            } else {
                break;
            }
        }
    }
    long long get_min(long long x) {
        if (empty()) {
            return inf;
        }
        sort_by_k = false;
        line best = *lower_bound(line(0, 0, x));
        sort_by_k = true;
        return best.value(x);
    }
};

ostream& operator << (ostream &os, const line_container &cont) {
    bool was = false;
    os << "{";
    for (const line &l : cont) {
        if (was) {
            os << " ";
        }
        was = true;
        os << l;
    }
    os << "}";
    return os;
}

struct tree {
    line_container a[4 * max_n];
    tree() {
    }
    void update(int v, int l, int r, int pos, const line &ln) {
        a[v].add(ln);
        if (l == r) {
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(2 * v, l, mid, pos, ln);
        } else {
            update(2 * v + 1, mid + 1, r, pos, ln);
        }
    }
    long long get_min(int v, int tl, int tr, int l, int r, int x) {
        if (l == tl && r == tr) {
            return a[v].get_min(x);
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_min(2 * v, tl, mid, l, r, x);
        }
        if (l > mid) {
            return get_min(2 * v + 1, mid + 1, tr, l, r, x);
        }
        return min(get_min(2 * v, tl, mid, l, mid, x), get_min(2 * v + 1, mid + 1, tr, mid + 1, r, x));
    }
};

tree t;

int n, a[max_n], b[max_n], pos[max_n], sz, l[max_n], r[max_n];
long long dp[max_n];
vector<int> g[max_n];

void dfs(int v, int p) {
    pos[v] = sz;
    l[v] = sz + 1;
    r[v] = sz;
    ++sz;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
            r[v] = max(r[v], r[to]);
        }
    }
    if (l[v] > r[v]) {
        dp[v] = 0;
    } else {
        dp[v] = t.get_min(1, 0, n - 1, l[v], r[v], a[v]);
    }
    t.update(1, 0, n - 1, pos[v], line(b[v], dp[v]));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; ++i) {
        printf("%I64d ", dp[i]);
    }
    printf("\n");
    return 0;
}