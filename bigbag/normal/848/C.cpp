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

const int max_n = 100111, inf = 1011111111;

struct treap {
    int x, prior;
    long long key;
    unsigned int sum;
    treap *left, *right;
    treap(long long k, int v) {
        key = k;
        x = v;
        sum = v;
        prior = (rand() << 15) + rand();
        left = NULL;
        right = NULL;
    }
};

unsigned int get_sum(treap *t) {
    if (t == NULL) {
        return 0;
    }
    return t->sum;
}

void update(treap *&t) {
    if (t == NULL) {
        return;
    }
    t->sum = t->x + get_sum(t->left) + get_sum(t->right);
}

treap *merge(treap *t1, treap *t2) {
    if (t1 == NULL) {
        return t2;
    }
    if (t2 == NULL) {
        return t1;
    }
    if (t1->prior <= t2->prior) {
        t2->left = merge(t1, t2->left);
        update(t2);
        return t2;
    } else {
        t1->right = merge(t1->right, t2);
        update(t1);
        return t1;
    }
}

void split(treap *our, long long key, treap *&l, treap *&r) {
    if (our == NULL) {
        l = NULL;
        r = NULL;
        return;
    }
    if (our->key >= key) {
        r = our;
        split(r->left, key, l, r->left);
    } else {
        l = our;
        split(l->right, key, l->right, r);
    }
    update(l);
    update(r);
}

void add(treap *&t, long long key, int x) {
    treap *nt = new treap(key, x);
    treap *buf1, *buf2;
    split(t, key, buf1, buf2);
    t = merge(buf1, merge(nt, buf2));
}

void erase(treap *&t, long long x) {
    treap *buf1, *buf2, *buf3, *buf4;
    split(t, x, buf1, buf2);
    split(buf2, x + 1, buf3, buf4);
    delete buf3;
    t = merge(buf1, buf4);
}

void write(treap *t) {
    if (t == NULL) {
        return;
    }
    write(t->left);
    cout << "(" << t->key << " " << t->x << " " << t->sum << ") ";
    write(t->right);
}

int b[max_n];

struct tree {
    treap *t[4 * max_n];
    void build(int v, int l, int r, int a[]) {
        t[v] = NULL;
        for (int i = l; i <= r; ++i) {
            add(t[v], 1LL * (i - a[i]) * max_n + a[i], a[i]);
            /*if (l == 4 && r == 6) {
                cout << "!" << 1LL * (i - a[i]) * max_n + a[i] << " " << i << " " << a[i] << endl;
            }*/
        }
        if (l == r) {
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
    }
    void update(int v, int l, int r, int pos, int x) {
        erase(t[v], 1LL * (pos - b[pos]) * max_n + b[pos]);
        add(t[v], 1LL * (pos - x) * max_n + x, x);
        if (l == r) {
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(2 * v, l, mid, pos, x);
        } else {
            update(2 * v + 1, mid + 1, r, pos, x);
        }
    }
    unsigned int get(int v, int tl, int tr, int l, int r, long long mn) {
        if (tl == l && tr == r) {
            treap *buf1, *buf2;
            split(t[v], mn, buf1, buf2);
            unsigned int res = get_sum(buf2);
            //cout << tl << " " << tr << ": " << res << "   " << get_size(buf1) << " " << get_size(buf2) << " " << mn << endl;
            t[v] = merge(buf1, buf2);
            return res;
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get(2 * v, tl, mid, l, r, mn);
        } else if (l > mid) {
            return get(2 * v + 1, mid + 1, tr, l, r, mn);
        }
        return get(2 * v, tl, mid, l, mid, mn) + get(2 * v + 1, mid + 1, tr, mid + 1, r, mn);
    }
};

int n, m, a[max_n], used[max_n];
set<int> all[max_n];
tree t;

void update(int pos, int x) {
    //cout << pos << ": " << b[pos] << " -> " << x << endl;
    t.update(1, 0, n - 1, pos, x);
    b[pos] = x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    memset(used, -1, sizeof(used));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (used[a[i]] != -1) {
            b[i] = i - used[a[i]];
        }
        used[a[i]] = i;
        all[a[i]].insert(i);
    }
    t.build(1, 0, n - 1, b);
    //cout << t.get(1, 0, n - 1, 2, 6, 0) << endl;
    //return 0;
    while (m--) {
        int tp, l, r;
        scanf("%d%d%d", &tp, &l, &r);
        if (tp == 1) {
            --l;
            set<int>::iterator it = all[a[l]].upper_bound(l);
            int nxt = -1, pr = -1;
            if (it != all[a[l]].end()) {
                nxt = *it;
            }
            --it;
            if (it != all[a[l]].begin()) {
                --it;
                pr = *it;
            }
            all[a[l]].erase(l);
            //cout << pr << " " << l << " " << nxt << endl;
            if (nxt != -1) {
                if (pr == -1) {
                    update(nxt, 0);
                } else {
                    update(nxt, nxt - pr);
                }
            }
            a[l] = r;
            all[a[l]].insert(l);

            it = all[a[l]].upper_bound(l);
            nxt = -1, pr = -1;
            if (it != all[a[l]].end()) {
                nxt = *it;
            }
            --it;
            if (it != all[a[l]].begin()) {
                --it;
                pr = *it;
            }

            if (nxt != -1) {
                update(nxt, nxt - l);
            }
            if (pr != -1) {
                update(l, l - pr);
            } else {
                update(l, 0);
            }
        } else {
            --l;
            --r;
            long long ans = t.get(1, 0, n - 1, l, r, 1LL * l * max_n);
            printf("%I64d\n", ans);
        }
    }
    return 0;
}