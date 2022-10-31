#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MX = 1<<23;

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
uniform_int_distribution<int> gen(0, 1e9);

struct node{
    int key, siz;
    node *lson, *rson;
    node(int v = 0){
        key = v; siz = 1;
        lson = rson = NULL;
    }
    void calc(){siz = (lson?lson->siz:0)+(rson?rson->siz:0)+1;}
} pool[40000000]; int top, z;

bool side(int a, int b){return gen(rng)%(a+b)<a;}

node* newnode(int v = 0){pool[top] = node(v); return &pool[top++];}

node* merge(node* t1, node* t2){
    if(!t1) return t2;
    if(!t2) return t1;
    node* t = newnode();
    if(side(t1->siz, t2->siz)){
        *t = *t1; ++z;
        t->rson = merge(t->rson, t2);
        t->calc(); return t;
    }
    *t = *t2; ++z;
    t->lson = merge(t1, t->lson);
    t->calc(); return t;
}

pair<node*, node*> split(node* t1, int k){
    if(!t1) return {NULL, NULL};
    node* t = newnode();
    *t = *t1; ++z;
    int tmp = (t1->lson?t1->lson->siz:0)+1;
    if(k<tmp){
        auto pa = split(t1->lson, k); 
        t->lson = pa.second;
        t->calc(); return {pa.first, t};
    }
    auto pa = split(t1->rson, k-tmp);
    t->rson = pa.first;
    t->calc(); return {t, pa.second};
}

int n, m, s, up[51][N], haha[N];
long long t;
node* p;

node* get(int l, int r){
    while(l<=0) l += n, r += n;
    while(l>n) l -= n, r -= n;
    if(r>n) return merge(get(l, n), get(n+1, r));
    auto t1 = split(p, r);
    auto t2 = split(t1.first, l-1);
    return t2.second;
}

void dfs(node* v, int* a, int& cur){
    if(v->lson) dfs(v->lson, a, cur);
    a[++cur] = v->key;
    if(v->rson) dfs(v->rson, a, cur);
}

node* build(int* a, int l, int r){
    if(l>r) return NULL;
    int m = (l+r)>>1;
    node* p = newnode(a[m]);
    p->lson = build(a, l, m-1);
    p->rson = build(a, m+1, r);
    p->calc(); return p;
}

node* rebuild(node* t){
    int ts = 0;
    dfs(t, haha, ts);
    return build(haha, 1, ts);
}

void brute(){
    if(s<=m) s = (t+s)%n;
    else s = ((-t+s)%n+n)%n;
    if(s==0) s = n; --t;
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> s >> t;
    for(int i = 1; i<=n; ++i)
        p = merge(p, newnode(i));
    for(int i = 1; i<n; ++i){
        int pz = z;
        p = merge(get(1+i, m+i), get(m+1-i, n-i));
        if(z-pz>1000) p = rebuild(p);
    }
    int lol = 0; dfs(p, up[0], lol);
    for(int i = 1; i<=50; ++i)
        for(int j = 1; j<=n; ++j)
            up[i][j] = up[i-1][up[i-1][j]];
    while(t%n) brute(); t/=n;
    for(int i = 50; i>=0; --i)
        if(t&(1ll<<i))
            s = up[i][s];
    cout << s << '\n';
}