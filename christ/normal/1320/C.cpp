#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define lc ind<<1
#define rc ind<<1|1
const int MN = 2e5+3, MOD = 1e9+7;
struct Item {
    int v,c;
    bool operator< (const Item &o) const {
        return make_pair(v,c) < make_pair(o.v,o.c);
    }
};
struct Monster {
    int a,b,c;
};
struct Node {
    ll v,lz;
} tree[MN << 2];
void build (int ind, int l, int r, vector<Item>&defense) {
    if (l == r) {
        tree[ind].v = -defense[l-1].c;
        return;
    }
    int mid = (l+r)/2;
    build(lc,l,mid,defense); build(rc,mid+1,r,defense);
    tree[ind].v = max(tree[lc].v,tree[rc].v);
}
void push_down (int ind, int l, int r) {
    if (!tree[ind].lz) return;
    tree[ind].v += tree[ind].lz;
    if (l != r) {
        tree[lc].lz += tree[ind].lz;
        tree[rc].lz += tree[ind].lz;
    }
    tree[ind].lz = 0;
}
void update (int ind, int tl, int tr, int l, int r, int v) {
    push_down(ind,tl,tr);
    if (tl > r || tr < l) return;
    if (tl >= l && tr <= r) {
        tree[ind].lz += v;
        push_down(ind,tl,tr);
        return;
    }
    int mid = (tl+tr)/2;
    update(lc,tl,mid,l,r,v); update(rc,mid+1,tr,l,r,v);
    tree[ind].v = max(tree[lc].v,tree[rc].v);
}
int main() {
    int n,m,p;
    scanf ("%d %d %d",&n,&m,&p);
    vector<Item> attack(n);
    vector<Item> defense(m);
    vector<Monster> monsters(p);
    for (auto &au : attack) {
        scanf ("%d %d",&au.v,&au.c);
    }
    for (auto &au : defense) {
        scanf ("%d %d",&au.v,&au.c);
    }
    for (auto &au : monsters) {
        scanf ("%d %d %d",&au.a,&au.b,&au.c);
    }
    sort(all(attack));
    sort(all(monsters),[](Monster a, Monster b) {return a.a < b.a;});
    sort(all(defense));
    build(1,1,m,defense);
    int mp = 0; ll ret = LLONG_MIN;
    for (int i = 0; i < n; i++) { //use this attack
        while (mp < p && monsters[mp].a < attack[i].v) { //can use this monster
            auto it = lower_bound(all(defense),Item{monsters[mp].b,INT_MAX});
            if (it != defense.end()) {
                update(1,1,m,it-defense.begin()+1,m,monsters[mp].c);
            }
            ++mp;
        }
        ret = max(ret,tree[1].v - attack[i].c);
    }
    printf ("%lld\n",ret);
    return 0;
}