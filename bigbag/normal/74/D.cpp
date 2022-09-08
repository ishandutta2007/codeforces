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

const int max_n = 1111111111, inf = 111111111;

struct state {
    int len, poz;
    state() {
        len = poz = 0;
    }
    state(int len, int poz) : len(len), poz(poz) {
    }
    bool operator < (const state &a) const {
        return len > a.len || len == a.len && poz > a.poz;
    }
};

struct treap {
    int sz, value, prior;
    treap *left, *right;
    treap(int v) {
        value = v;
        sz = 1;
        prior = rand() * rand();
        left = NULL;
        right = NULL;
    }
};

int get_size(treap *t) {
    if (t == NULL) {
        return 0;
    }
    return t->sz;
}

void update(treap *&t) {
    if (t == NULL) {
        return;
    }
    t->sz = 1 + get_size(t->left) + get_size(t->right);
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

int get_val(treap *t) {
    if (t == NULL) {
        return inf;
    }
    return t->value;
}

void split(treap *our, int key, treap *&l, treap *&r) {
    if (our == NULL) {
        l = NULL;
        r = NULL;
        return;
    }
    if (our->value >= key) {
        r = our;
        split(r->left, key, l, r->left);
    } else {
        l = our;
        split(l->right, key, l->right, r);
    }
    update(l);
    update(r);
}

void add(treap *&t, int x) {
    treap *nt = new treap(x);
    treap *buf1, *buf2;
    split(t, x, buf1, buf2);
    t = merge(buf1, merge(nt, buf2));
}

void erase(treap *&t, int x) {
    treap *buf1, *buf2, *buf3, *buf4;
    split(t, x, buf1, buf2);
    split(buf2, x + 1, buf3, buf4);
    t = merge(buf1, buf4);
}

int n, k;
map<int, int> nums;
map<int, int> f;
set<int> pozs;
set<state> s;
treap *t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    s.insert(state(n, 1));
    pozs.insert(0);
    pozs.insert(n + 1);
    while (k--) {
        int num;
        scanf("%d", &num);
        if (num != 0) {
            int x = f[num];
            x ^= 1;
            f[num] = x;
            if (x == 1) {
                state q = *s.begin();
                int l = q.poz, r = q.poz + q.len - 1;
                int poz = (l + r) / 2;
                if (q.len % 2 == 0) {
                    ++poz;
                }
                pozs.insert(poz);
                s.erase(q);
                if (poz != l) s.insert(state(poz - l, l));
                if (poz != r) s.insert(state(r - poz, poz + 1));
                nums[num] = poz;
                add(t, poz);
                //cout << "! " << l << " " << r << "   " << poz << endl;
            } else {
                int poz = nums[num];
                set<int>::iterator it = pozs.upper_bound(poz);
                int r = *it;
                --it;
                --it;
                int l = *it;
                /*if (l == 0) {
                    ++l;
                }
                if (r == n + 1) {
                    --n;
                }*/
                //cout << "#!" << poz << "  " << l << " " << r << endl;
                //cout << "erase : " << l + 1 << " " << poz - l - 1 << endl;
                //cout << "erase : " << poz + 1 << " " << r - poz - 1 << endl;
                //cout << "insert : " << l + 1 << " " << r - l - 1<< endl;
                s.erase(state(poz - l - 1, l + 1));
                s.erase(state(r - 1 - poz, poz + 1));
                s.insert(state(r - l - 1, l + 1));
                pozs.erase(poz);
                erase(t, poz);
            }
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            treap *buf1, *buf2, *buf3, *buf4;
            split(t, l, buf1, buf2);
            split(buf2, r + 1, buf3, buf4);
            cout << get_size(buf3) << endl;
            //cout << "               " << get_size(buf3) << endl;
            t = merge(buf1, merge(buf3, buf4));
        }
    }
    return 0;
}