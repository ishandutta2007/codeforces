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

const int max_n = 111111, inf = 1111111111;

struct treap {
    int sz, value, prior, sum;
    treap *left, *right;
    bool rev;
    treap(int v) {
        sum = v;
        value = v;
        sz = 1;
        prior = rand() * rand();
        left = NULL;
        right = NULL;
        rev = false;
    }
};

int get_size(treap *t) {
    if (t == NULL) {
        return 0;
    }
    return t->sz;
}

int get_sum(treap *t) {
    if (t == NULL) {
        return 0;
    }
    return t->sum;
}

void update(treap *&t) {
    if (t == NULL) {
        return;
    }
    t->sz = 1 + get_size(t->left) + get_size(t->right);
    t->sum = t->value + get_sum(t->left) + get_sum(t->right);
}

void push(treap *&t) {
    if (t == NULL) {
        return;
    }
    if (t->rev) {
        t->rev = false;
        if (t->left != NULL) t->left->rev ^= 1;
        if (t->right != NULL) t->right->rev ^= 1;
        swap(t->left, t->right);
    }
}

treap *merge(treap *t1, treap *t2) {
    if (t1 == NULL) {
        return t2;
    }
    if (t2 == NULL) {
        return t1;
    }
    push(t1);
    push(t2);
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

void split(treap *our, int sz, treap *&l, treap *&r) {
    if (our == NULL) {
        l = NULL;
        r = NULL;
        return;
    }
    push(our);
    if (get_size(our->left) + 1 == sz) {
        l = our;
        r = our->right;
        l->right = NULL;
    } else {
        if (get_size(our->left) >= sz) {
            r = our;
            split(r->left, sz, l, r->left);
        } else {
            l = our;
            split(l->right, sz - get_size(l->left) - 1, l->right, r);
        }
    }
    update(l);
    update(r);
}

void add(treap *&t, int x) {
    treap *q = new treap(x);
    t = merge(t, q);
}

void write(treap *t) {
    if (t == NULL) {
        return;
    }
    write(t->left);
    cout << t->value << ' ';
    write(t->right);
}

void Write(treap *t) {
    cout << get_size(t) << " : ";
    write(t);
    cout << endl;
}

void inc(treap *&t, int poz, int value) {
    treap *buf1, *buf2, *buf3;
    split(t, poz, buf1, buf2);
    split(buf1, poz - 1, buf1, buf3);
    buf3->value += value;
    buf3->sum += value;
    t = merge(merge(buf1, buf3), buf2);
}

int n, q;
treap *t, *buf1, *buf2, *buf3, *buf4;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        add(t, 1);
    }
    //Write(t);
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x;
            cin >> x;
            push(t);
            if (x <= n - x) {
                split(t, x, buf1, buf2);
                for (int i = 1; i <= x; ++i) {
                    split(buf1, get_size(buf1) - 1, buf1, buf3);
                    inc(buf2, i, buf3->value);
                }
                t = buf2;
            } else {
                split(t, x, buf1, buf2);
                //cout << n << endl;
                for (int i = 0; i < n - x; ++i) {
                    //cout << i << endl;
                    split(buf2, 1, buf3, buf2);
                    inc(buf1, x - i, buf3->value);
                }
                t = buf1;
                t->rev ^= 1;
            }
            n = get_size(t);
        } else {
            int l, r;
            cin >> l >> r;
            push(t);
            split(t, l, buf1, buf2);
            split(buf2, r - l, buf3, buf4);
            cout << get_sum(buf3) << endl;
            t = merge(buf1, merge(buf3, buf4));
        }
        //Write(t);
    }
    return 0;
}