#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005

struct node{
    int pri, key; node* c[2];
    int siz, val;
    bool flip = 0;
    node(int kk, int vv){
        key = kk; pri = rand();
        siz = 1; val = vv;
        c[0] = c[1] = NULL;
    }
};

node* treap;

int getsiz(node* x){return x?x->siz:0;}

node* prop(node* x){
    if(!x || !x->flip) return x;
    swap(x->c[0], x->c[1]);
    x->flip = 0;
    for(int i = 0; i<2; i++) if(x->c[i]) (x->c[i])->flip ^= 1;
    return x;
}

node* calc(node* x){
    node* a = x->c[0]; node* b = x->c[1];
    assert(!x->flip); prop(a); prop(b);
    x->siz = getsiz(a)+getsiz(b)+1;
    return x;
}

void tour(node* x){
    if(!x) return; 
    prop(x); tour(x->c[0]); cout << x->key << endl; tour(x->c[1]);
}

pair<node*, node*> split(node* x, int v, int add = 0){
    if(!x) return {x, x};
    prop(x);
    if(getsiz(x->c[0])+add >= v){
        auto p = split(x->c[0], v, add); x->c[0] = p.second;
        return {p.first, calc(x)};
    }
    else{
        auto p = split(x->c[1], v, add+1+getsiz(x->c[0])); x->c[1] = p.first;
        return {calc(x), p.second};
    }
}

node* merge(node* l, node* r){
    if(!l || !r) return l?:r;
    prop(l); prop(r); node* x;
    if(l->pri > r->pri) l->c[1] = merge(l->c[1], r), x = l;
    else r->c[0] = merge(l, r->c[0]), x = r;
    return calc(x);
}

node* reverse(node* x, int l, int r){
    auto b = split(x, r+1); auto a = split(b.first, l);
    a.second->flip ^= 1;
    return merge(merge(a.first, a.second), b.second);
}

node* ins(node* x, int key, int val){
    auto b = split(x, key+1); auto a = split(b.first, key);
    return merge(a.first, merge(new node(key, val), b.second));
}

node* del(node* x, int v){
    auto b = split(x, v+1); auto a = split(b.first, v);
    return merge(a.first, b.second);
}

int n, q, m;
int arr[MAXN];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
    cin >> n >> q >> m;
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int i = 0; i<n; i++) treap = ins(treap, i, arr[i]);

    while(q--){
        int t, l, r; cin >> t >> l >> r; --l; --r;
        if(t == 2){
            treap = reverse(treap, l, r);
        }
        else{
            auto b = split(treap, r+1);
            auto c = split(b.first, r);
            auto a = split(c.first, l);
            treap = merge(a.first, merge(merge(c.second, a.second), b.second));
        }
    }
    
    for(int i = 0; i<m; i++){
        int id; cin >> id; --id;
        auto b = split(treap, id+1);
        auto a = split(b.first, id);
        cout << (a.second)->val << endl;
        treap = merge(merge(a.first, a.second), b.second);
    }
}