#include <bits/stdc++.h>

using namespace std;

const int max_n = 100011, inf = 1000111222;

struct treap {
    int value, pl;
    int sz, prior;
    treap *left, *right;
    treap(int v) {
        value = v;
        sz = 1;
        pl = 0;
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

void push(treap *&t) {
    if (t == NULL) {
        return;
    }
    if (t->left) {
        t->left->pl += t->pl;
        t->left->value += t->pl;
    }
    if (t->right) {
        t->right->pl += t->pl;
        t->right->value += t->pl;
    }
    t->pl = 0;
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
    push(t);
    write(t->left);
    cout << t->value << ' ';
    write(t->right);
}

int n, a[max_n], b[max_n];
treap *t;
set<pair<long long, int>> q;

void wa() {
    puts("No");
    exit(0);
}

long long get_elem(treap *t, int num) {
    treap *buf1, *buf2, *buf3, *buf4;
    split(t, num, buf1, buf2);
    split(t, 1, buf3, buf4);
    long long res = buf3->value + buf3->pl;
    t = merge(buf1, merge(buf3, buf4));
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    t = NULL;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        add(t, a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
        wa();
    }
    for (int i = 1; i < n; ++i) {
        q.insert({a[i] - a[i - 1], i});
    }
    for (int i = 1; i + 1 < n; ++i) {
        //write(t);
        //cout << endl;
        int need = b[i] - get_elem(t, 0);
        auto it = q.lower_bound({need, -1});
        if (it == q.end() || it->first != need) {
            //cout << "#" << i << endl;
            //cout << "$$$$" << it->first << " " << need << endl;
            wa();
        }
        int pos = it->second + i + 1;
        treap *buf1, *buf2, *buf3, *buf4;
        split(t, pos - 2, buf1, buf2);
        split(buf1, pos - 1, buf3, buf4);
        //write(buf3);
        //cout << endl;
        buf3->pl += need;
        buf3->value += need;
        //cout << "$" << need << endl;
        //write(buf3);
        //cout << endl;
        t = merge(buf3, buf2);
        q.erase(it);
    }
    puts("Yes");
    return 0;
}