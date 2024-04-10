#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct node {
    node* l = nullptr;
    node* r = nullptr;
    ll key = 0;
    ll prior = 0;
    ll cnt = 0;
    ll sz = 0;
};

node* tree;

ll get_prior(node* t) {
    if (!t) return 1e18;
    else return t->prior;
}

ll get_size(node* t) {
    if (!t) return 0;
    else return t->sz;
}

void recalc(node* t) {
    if (t)
        t->sz = t->cnt + get_size(t->l) + get_size(t->r);
}

pair<node*, node*> split(node* v, ll x0) {
    if (v == nullptr)
        return {nullptr, nullptr};
    if ((v->key) <= x0) {
        auto p = split(v->r, x0);
        v->r = p.first;
        recalc(v);
        return {v, p.second};
    }
    else {
        auto p = split(v->l, x0);
        v->l = p.second;
        recalc(v);
        return {p.first, v};
    }
}

node* merge(node* v1, node* v2) {
    if (!v1) return v2;
    if (!v2) return v1;
    ll p1 = v1->prior, p2 = v2->prior;
    if (p1 < p2) {
        v1->r = merge(v1->r, v2);
        recalc(v1);
        return v1;
    }
    else {
        v2->l = merge(v1, v2->l);
        recalc(v2);
        return v2;
    }
}

bool find_down(ll x) {
    node* t = tree;
    bool found = 0;
    while (t != nullptr) {
        if (t->key == x) {
            found = 1;
            break;
        }
        if (x < t->key)
            t = t->l;
        else
            t = t->r;
    }
    if (found == 1) {
        t = tree;
        while (t != nullptr) {
            t->sz++;
            if (t->key == x) {
                t->cnt++;
                break;
            }
            if (x < t->key)
                t = t->l;
            else
                t = t->r;
        }
        return 1;
    }
    return 0;
}

void add(ll x) {
    if (find_down(x) == 0) {
        ll pr = rand() * rand();
        node* v = new node;
        v->key = x;
        v->prior = pr;
        v->cnt = 1;
        v->sz = 1;
        node* t = nullptr;
        node* t1 = tree;
        while (get_prior(t1) <= pr) {
            t = t1;
            if (x <= t1->key) {
                t1 = t1->l;
            }
            else {
                t1 = t1->r;
            }
        }
        auto p = split(t1, x);
        v->l = p.first;
        v->r = p.second;
        recalc(v);
        if (!t) {
            tree = v;
            return;
        }
        if (x <= t->key)
            t->l = v;
        else
            t->r = v;
        t = tree;
        while (t != nullptr) {
            if ((t->key) == x)
                break;
            t->sz++;
            if (x <= (t->key))
                t = t->l;
            else
                t = t->r;
        }
    }
}

ll smaller(ll x, node* t = tree) {
    if (t == nullptr)
        return 0;
    if (t->key <= x)
        return get_size(t->l) + smaller(x, t->r) + t->cnt;
    else
        return smaller(x, t->l);
}

const ll mx = 200000;
ll n, k, a[mx], b[mx];

bool check(ll X) {
    ll ct = 0;
    for (int i = 1; i <= n; ++i) {
        add(b[i-1]);
        ct += (smaller(b[i] - X));
    }
    tree = nullptr;
    if (ct >= k) return 1;
    else return 0;
}

ll binsearch(ll L, ll R) {
    if ((R - L) == 1) {
        if (check(R)) return R;
        else return L;
    }
    if (L == R) return L;
    ll M = (L + R) / 2;
    if (check(M+1)) return binsearch(M+1, R);
    else return binsearch(L, M);
}

int main()
{
    cin >> n >> k;
    b[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = (b[i-1] + a[i]);
    }
    cout << binsearch(-1e14, 1e14);
    return 0;
}