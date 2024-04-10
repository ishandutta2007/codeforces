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

const int max_n = 101111, mod = 1000000007, inf = 2011111111;

struct tree {
    multiset<pair<int, pair<int, int> > > q[4 * max_n];
    void add(int v, int tl, int tr, int pos, pair<int, pair<int, int> > p) {
        /*if (v == 1) {
            cout << v << " " << tl << " " << tr << ": ";
            printf("+ h = %d, pos = %d, cnt = %d\n", p.first, pos, p.second.first);
        }*/
        q[v].insert(p);
        if (tl == tr) {
            return;
        }
        int mid = (tl + tr) / 2;
        if (pos <= mid) {
            add(2 * v, tl, mid, pos, p);
        } else {
            add(2 * v + 1, mid + 1, tr, pos, p);
        }
    }
    void err(int v, int tl, int tr, int pos, pair<int, pair<int, int> > p) {
        /*if (v == 1) {
            printf("- h = %d, pos = %d, cnt = %d\n", p.first, pos, p.second.first);
        }*/
        q[v].erase(q[v].find(p));
        if (tl == tr) {
            return;
        }
        int mid = (tl + tr) / 2;
        if (pos <= mid) {
            err(2 * v, tl, mid, pos, p);
        } else {
            err(2 * v + 1, mid + 1, tr, pos, p);
        }
    }
    pair<int, pair<int, int> > get_min(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            if (q[v].size() == 0) {
                return make_pair(inf, make_pair(inf, inf));
            }
            return *q[v].begin();
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_min(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_min(2 * v + 1, mid + 1, tr, l, r);
        }
        return min(get_min(2 * v, tl, mid, l, mid), get_min(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

struct block {
    int u, l, r, s;
    void read() {
        scanf("%d%d%d%d", &u, &l, &r, &s);
        --l;
        --r;
    }
    void write() {
        printf("%d [%d %d] %d\n", u, l, r, s);
    }
    bool operator < (const block &b) const {
        return u > b.u;
    }
};

int h, w, n;
block a[max_n];
tree t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &h, &w, &n);
    for (int i = 0; i < w; ++i) {
        t.add(1, 0, w - 1, i, make_pair(h + 1, make_pair(1, i)));
    }
    for (int i = 0; i < n; ++i) {
        a[i].read();
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        //a[i].write();
        int cnt = 0;
        while (true) {
            pair<int, pair<int, int> > p = t.get_min(1, 0, w - 1, a[i].l, a[i].r);
            if (p.first > a[i].u + a[i].s) {
                break;
            }
            //cout << "#" << p.first << " " << p.second.first << " " << p.second.second << endl;
            cnt += p.second.first;
            cnt %= mod;
            t.err(1, 0, w - 1, p.second.second, p);
        }
        //cout << "cnt = " << cnt << endl;
        if (a[i].l == 0) {
            cnt *= 2;
            cnt %= mod;
            t.add(1, 0, w - 1, a[i].r + 1, make_pair(a[i].u, make_pair(cnt, a[i].r + 1)));
        } else if (a[i].r + 1 == w) {
            cnt *= 2;
            cnt %= mod;
            t.add(1, 0, w - 1, a[i].l - 1, make_pair(a[i].u, make_pair(cnt, a[i].l - 1)));
        } else {
            t.add(1, 0, w - 1, a[i].r + 1, make_pair(a[i].u, make_pair(cnt, a[i].r + 1)));
            t.add(1, 0, w - 1, a[i].l - 1, make_pair(a[i].u, make_pair(cnt, a[i].l - 1)));
        }
    }
    int ans = 0;
    for (auto p : t.q[1]) {
        //cout << "!" << p.first << " " << p.second.first << " " << p.second.second << endl;
        ans += p.second.first;
        ans %= mod;
    }
    printf("%d\n", ans);
    return 0;
}