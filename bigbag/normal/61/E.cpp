#include <set>
#include <map>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1000001, inf = 111111111;

struct tree {
    long long sum;
    int a, dp, sz;
    tree *left, *right;
    tree() {
        a = sum = dp = sz = 0;
        left = NULL;
        right = NULL;
    }
    tree(int x, int v) {
        a = x;
        sum = dp = v;
        sz = 1;
        left = NULL;
        right = NULL;
    }
};

long long get_sum(tree *t) {
    if (t == NULL) {
        return 0;
    }
    return t->sum;
}

int get_size(tree *t) {
    if (t == NULL) {
        return 0;
    }
    return t->sz;
}

void update(tree *&t) {
    if (t == NULL) {
        return;
    }
    t->sz = 1 + get_size(t->left) + get_size(t->right);
    t->sum = t->dp + get_sum(t->left) + get_sum(t->right);
}

void add(tree *&t, int aa, int dpp) {
    if (t == NULL) {
        t = new tree(aa, dpp);
        return;
    }
    if (t->a < aa) {
        add(t->right, aa, dpp);
    } else {
        add(t->left, aa, dpp);
    }
    update(t);
}

tree *Max(tree *&t) {
    if (t->right == NULL) {
        return t;
    }
    if (t->right->right == NULL) {
        tree *ret = t->right;
        t->right = t->right->left;
        update(t);
        update(ret);
        return ret;
    }
    tree *ret = Max(t->right);
    update(t);
    return ret;
}

void Delete(tree *&t, int a, int dp) {
    if (t->a == a && t->dp == dp) {
        if (t->left == NULL && t->right == NULL) {
            t = NULL;
            return;
        }
        if (t->left == NULL) {
            t = t->right;
            return;
        }
        if (t->right == NULL) {
            t = t->left;
            return;
        }
        if (t->left->right == NULL) {
            t->dp = t->left->dp;
            t->a = t->left->a;
            t->left = t->left->left;
            update(t);
            return;
        }
        //cout << "!!!" << endl;
        tree *q = Max(t->left);
        t->dp = q->dp;
        t->a = q->a;
        update(t);
        //tree *q1 = q->left;
        //q = NULL;
        //tree *t1 = Max(t->left);
        //t1 = q1;
        //Delete(q, q->poz, q->len);
        return;
    }
    if (t->a < a) {
        Delete(t->right, a, dp);
    } else {
        Delete(t->left, a, dp);
    }
    update(t);
}

long long get(tree *t, int x) {
    if (t == NULL) {
        return 0;
    }
    if (t->a <= x) {
        return get(t->right, x);
    }
    return t->dp + get_sum(t->right) + get(t->left, x);
    return get_sum(t);
}

int get_cnt(tree *t, int x) {
    if (t == NULL) {
        return 0;
    }
    if (t->a <= x) {
        return get_cnt(t->right, x);
    }
    return 1 + get_size(t->right) + get_cnt(t->left, x);
    return get_size(t);
}

void write(tree *t) {
    if (t == NULL) {
        return;
    }
    write(t->left);
    cout << t->a << ' ';
    write(t->right);
}

int n, a[max_n], dp[max_n], ppp[max_n];
tree *t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    if (n < 3) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ppp[i] = i;
    }
    long long ans = 0;
    dp[0] = 0;
    random_shuffle(ppp, ppp + n - 1);
    random_shuffle(ppp, ppp + n - 1);
    random_shuffle(ppp, ppp + n - 1);
    random_shuffle(ppp, ppp + n - 1);
    random_shuffle(ppp, ppp + n - 1);
    random_shuffle(ppp, ppp + n - 1);
    random_shuffle(ppp, ppp + n - 1);
    t = new tree(a[ppp[0]], 0);
    for (int i = 1; i < n; ++i) {
        add(t, a[ppp[i]], 0);
    }
    for (int i = n - 1; i >= 0; --i) {
        Delete(t, a[i], 0);
        //cout << get_size(t) << endl;
        //write(t);
        //cout << endl;
        dp[i] = get_cnt(t, a[i]);
    }
    t = new tree(a[ppp[0]], dp[ppp[0]]);
    for (int i = 1; i < n; ++i) {
        add(t, a[ppp[i]], dp[ppp[i]]);
    }
    for (int i = n - 1; i >= 0; --i) {
        Delete(t, a[i], dp[i]);
        ans += get(t, a[i]);
    }
    cout << ans << endl;
    return 0;
}