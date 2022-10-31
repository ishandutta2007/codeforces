#include <bits/stdc++.h>
using namespace std;

struct node{
    node* l, *r;
    int lazy = 0, ans = -1;
    node(node* _l = nullptr, node* _r = nullptr): l(_l), r(_r){}
};

int query(int l, int r){
    cout << "? " << l << " " << r << endl;
    int val; cin >> val;
    return val;
}

node* build(int tl, int tr){
    if(tl == tr) return new node();
    int tm = (tl+tr)>>1;
    return new node(build(tl, tm), build(tm+1, tr));
}

void upd(int pos, node* v, int tl, int tr){
    if(v->ans != -1) v->lazy++;
    if(tl == tr) return;
    int tm = (tl+tr)>>1;
    if(pos <= tm) upd(pos, v->l, tl, tm);
    else upd(pos, v->r, tm+1, tr);
}

int find(int k, node* v, int tl, int tr){
    if(tl == tr) return tl;
    int tm = (tl+tr)>>1;
    if(v->l->ans == -1) v->l->ans = query(tl, tm);
    if(v->l->ans + v->l->lazy + k <= tm-tl+1) return find(k, v->l, tl, tm);
    return find(k-(tm-tl+1)+(v->l->ans + v->l->lazy), v->r, tm+1, tr);
}

int n, t;
node* root;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> t;
    root = build(1, n);
    while(t--){
        int k; cin >> k;
        int pos = find(k, root, 1, n);
        cout << "! " << pos << endl;
        upd(pos, root, 1, n);
    }
}