/**
 *  created: 19/05/2022, 18:15:42
**/

#include <bits/stdc++.h>

using namespace std;

const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 gen(seed);

struct treap {
    int sz, sum, prior;
    pair<int, int> value;

    treap *left, *right;
    treap(const pair<int, int> &v) {
        value = v;
        sz = 1;
        sum = v.first;
        prior = gen();
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
    t->sum = t->value.first + get_sum(t->left) + get_sum(t->right);
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

void split(treap *our, const pair<int, int> &key, treap *&l, treap *&r) {
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

void add(treap *&t, const pair<int, int> &x) {
    treap *nt = new treap(x);
    treap *buf1, *buf2;
    split(t, x, buf1, buf2);
    t = merge(buf1, merge(nt, buf2));
}

void erase(treap *&t, pair<int, int> x) {
    treap *buf1, *buf2, *buf3, *buf4;
    split(t, x, buf1, buf2);
    ++x.second;
    split(buf2, x, buf3, buf4);
    t = merge(buf1, buf4);
}

int get_max(treap *t, int ops) {
    if (t == NULL) {
        return 0;
    }
    if (get_sum(t->left) >= ops) {
        return get_max(t->left, ops);
    }
    int res = get_size(t->left);
    ops -= get_sum(t->left);
    if (ops < t->value.first) {
        return res;
    }
    ++res;
    ops -= t->value.first;
    return res + get_max(t->right, ops);
}

const int max_n = 100111, inf = 1000111222;

int t, n, k, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ++cnt[a[i]];
        }
        treap *t = NULL;
        for (auto [x, c] : cnt) {
            add(t, {c, x});
        }
        int need = 0, ans = inf;
        for (int x = 0; x <= n; ++x) {
            if (cnt[x]) {
                erase(t, {cnt[x], x});
            }
            if (!cnt[x] && need <= k) {
                int ops = k - cnt[x];
                int res = get_size(t) - get_max(t, ops);
                if (!x) {
                    res = max(res, 1);
                }
                ans = min(ans, res);
            }
            need += cnt[x] == 0;
        }
        cout << ans << "\n";
    }
    return 0;
}