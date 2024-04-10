#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

struct Treap {
    int x, y;
    int sz;
    Treap *l, *r;

    Treap(int x) : x(x), y(rand()), sz(1), l(0), r(0) {
    }
};

typedef Treap* ptreap;

int get_sz(ptreap t) {
    if (!t) {
        return 0;
    }
    return t->sz;
}

void recalc(ptreap t) {
    if (t) {
        t->sz = get_sz(t->l) + get_sz(t->r) + 1;
    }
}

ptreap* split(ptreap t, int x) {
    if (!t) {
        return new ptreap[2] {0, 0};
    }
    ptreap* r;
    if (x < t->x) {
        r = split(t->l, x);
        t->l = r[1];
        r[1] = t;
    } else {
        r = split(t->r, x);
        t->r = r[0];
        r[0] = t;
    }

    recalc(r[0]);
    recalc(r[1]);
    return r;
}

ptreap merge(ptreap a, ptreap b) {
    if (!a) {
        return b;
    }
    if (!b) {
        return a;
    }
    ptreap t;
    if (a->y < b->y) {
        a->r = merge(a->r, b);
        t = a;
    } else {
        b->l = merge(a, b->l);
        t = b;
    }
    recalc(t);
    return t;
}

ptreap r_add[1111111];
ptreap r_rem[1111111];

int get_pref(ptreap t, int x) {
    ptreap* a = split(t, x);
    int res = get_sz(a[0]);
    t = merge(a[0], a[1]);
    return res;
}

ptreap insert(ptreap t, int x) {
    ptreap* a = split(t, x);
    a[0] = merge(a[0], new Treap(x));
    return merge(a[0], a[1]);
}

int main() {
    srand(31);
    scid(n);
    unordered_map<int, int> num;
    num.reserve(n);
    for (int i = 0; i < n; i++) {
        sciiid(a, t, x);
        if (num.find(x) == num.end()) {
            int ts = num.size();
            num[x] = ts;
        }
        x = num[x];
        if (a == 1) {
            r_add[x] = insert(r_add[x], t);
        } else if (a == 2) {
            r_rem[x] = insert(r_rem[x], t);
        } else {
            printf("%d\n", get_pref(r_add[x], t) - get_pref(r_rem[x], t));
        }
    }

    return 0;
}