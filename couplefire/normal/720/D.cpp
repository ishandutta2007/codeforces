#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int n, m, k, num = 0;
struct evt{
    int x, l, r, type;
} a[200010];
struct tree{
    int l, r, sum;
    bool set0;
    tree *lc, *rc;
    tree(int l, int r) : l(l), r(r), lc(NULL), rc(NULL), sum(0), set0(0) {}
} *root;
multiset<int> s;

int cmp(evt x, evt y){
    return x.x == y.x ? (x.type == y.type ? x.l > y.l : x.type > y.type) : x.x < y.x;
}
tree *bt(int l, int r){
    tree *i = new tree(l, r);
    if (l < r){
        int md = l + r >> 1;
        i->lc = bt(l, md);
        i->rc = bt(md + 1, r);
    }
    return i;
}
void pushdown(tree *i){
    if (i->set0){
        i->lc->set0 = i->rc->set0 = true;
        i->lc->sum = i->rc->sum = 0;
        i->set0 = false;
    }
}
void add(tree *i, int p, int x){
    if (i->l == i->r){
        (i->sum += x) %= mod;
        return;
    }
    int md = i->l + i->r >> 1;
    pushdown(i);
    if (p <= md) add(i->lc, p, x);
    else add(i->rc, p, x);
    i->sum = (i->lc->sum + i->rc->sum) % mod;
}
int get(tree *i, int l, int r){
    if (l > r) return 0;
    if (i->l == l && i->r == r) return i->sum;
    int md = i->l + i->r >> 1;
    pushdown(i);
    if (r <= md) return get(i->lc, l, r);
    else if (l > md) return get(i->rc, l, r);
    else return (get(i->lc, l, md) + get(i->rc, md + 1, r)) % mod;
}
void set0(tree *i, int l, int r){
    if (i->l == l && i->r == r){
        i->set0 = true;
        i->sum = 0;
        return;
    }
    int md = i->l + i->r >> 1;
    pushdown(i);
    if (r <= md) set0(i->lc, l, r);
    else if (l > md) set0(i->rc, l, r);
    else set0(i->lc, l, md), set0(i->rc, md + 1, r);
    i->sum = (i->lc->sum + i->rc->sum) % mod;
}
void print(tree *i){
    if (!i) return;
    printf("l: %d r: %d sum: %d set0: %d\n", i->l, i->r, i->sum, i->set0);
    print(i->lc);
    print(i->rc);
}
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; i++){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        a[++num] = {x1, y1, y2, 1};
        a[++num] = {x2 + 1, y1, y2, -1};
    }
    sort(a + 1, a + 1 + num, cmp);
    root = bt(1, m);
    add(root, 1, 1);
    s.insert(0);
    s.insert(m + 1);
    int hh;
    for (hh = 1; hh <= num && a[hh].x == 1; hh++){
        s.insert(a[hh].l);
        s.insert(a[hh].r);
    }
    for (int i = hh; i <= num && a[i].x <= n; i++){
        if (a[i].type == 1){
            if (*s.upper_bound(a[i].r) > a[i].r + 1)
                add(root, a[i].r + 1, get(root, *(--s.upper_bound(a[i].r)) + 1, a[i].r))/*, printf("%d %d\n", *(--s.upper_bound(a[i].r)) + 1, a[i].r)*/;
            set0(root, a[i].l, a[i].r);
            s.insert(a[i].l);
            s.insert(a[i].r);
        }
        else{
            s.erase(s.lower_bound(a[i].l));
            s.erase(s.lower_bound(a[i].r));
        }
    }
    multiset<int>::iterator it = s.end();
    it--;
    it--;
    printf("%d\n", get(root, *it + 1, m));
}