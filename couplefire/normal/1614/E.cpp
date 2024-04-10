#include <bits/stdc++.h>
using namespace std;

struct node{
    int mn, mx, lazy = 0, tl, tr;
    node *l = nullptr, *r = nullptr;
    node(int tl, int tr): mn(tl), mx(tr), tl(tl), tr(tr){}
}; node* rt = new node(0, 1e9);

void push(node* v){
    v->mn += v->lazy;
    v->mx += v->lazy;
    if(v->l) v->l->lazy += v->lazy;
    if(v->r) v->r->lazy += v->lazy;
    v->lazy = 0;
}

void upd(node* v, int bd, bool dir){
    push(v);
    if(!dir && v->mn>bd) return;
    if(dir && v->mx<bd) return;
    if(!dir && v->mx<=bd) return ++v->lazy, push(v), void();
    if(dir && v->mn>=bd) return --v->lazy, push(v), void();
    if(!v->l || !v->r){
        int tm = (v->tl+v->tr)>>1;
        v->l = new node(v->tl, tm);
        v->r = new node(tm+1, v->tr);
        int dif = v->mn-v->tl;
        v->l->mn += dif; v->l->mx += dif;
        v->r->mn += dif; v->r->mx += dif;
    }
    upd(v->l, bd, dir); upd(v->r, bd, dir);
    v->mn = v->l->mn;
    v->mx = v->r->mx;
}

int query(node* v, int x){
    push(v);
    if(!v->l || !v->r) return x+v->mn-v->tl;
    if(x<=v->l->tr) return query(v->l, x);
    return query(v->r, x);
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n; int pans = 0;
    for(int i = 0; i<n; ++i){
        int t; cin >> t;
        upd(rt, t-1, 0); upd(rt, t+1, 1);
        int k; cin >> k;
        while(k--){
            int x; cin >> x;
            x = (x+pans)%((int)1e9+1);
            cout << (pans = query(rt, x)) << '\n';
        }
    }
}