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
    int sz, mx, value, poz, prior;
    treap *left, *right;
    treap(int v, int p) {
        value = v;
        poz = p;
        sz = 1;
        mx = p;
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

int get_max(treap *t) {
    if (t == NULL) {
        return -1;
    }
    return t->mx;
}

void update(treap *&t) {
    if (t == NULL) {
        return;
    }
    t->sz = 1 + get_size(t->left) + get_size(t->right);
    t->mx = max(t->poz, max(get_max(t->left), get_max(t->right)));
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

void add(treap *&t, int x, int poz) {
    treap *nt = new treap(x, poz);
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

int n, a[max_n], ans[max_n];
treap *t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    ans[n - 1] = -1;
    t = new treap(a[n - 1], n - 1);
    for (int i = n - 2; i >= 0; --i) {
        treap *buf1, *buf2, *buf3, *buf4;
        split(t, a[i], buf1, buf2);
        ans[i] = get_max(buf1);
        t = merge(buf1, buf2);
        add(t, a[i], i);
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i] != -1) {
            printf("%d ", ans[i] - i - 1);
        } else {
            printf("-1 ");
        }
    }
    printf("\n");
    return 0;
}