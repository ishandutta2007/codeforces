#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;

int n,m,vmax;
ll seed;

int rnd() {
    int ret = seed;
    seed = (seed * 7 + 13) % MOD;
    return ret;
}

ll po(ll b, int p, int mo) {
    return !p?1:po(b*b%mo,p/2,mo)*(p&1?b:1)%mo;
}

struct tnode {
    ll val, lazy;
    int pri, sz, sum;
    
    tnode *c[2];
    tnode (ll v, int s) {
        c[0] = c[1] = NULL;
        pri = rand()+(rand()<<15);
        val = v; lazy = 0;
        sz = sum = s;
    }
    void propogate() {
        if (!lazy) return;
        val += lazy;
        F0R(i,2) if (c[i]) c[i]->lazy += lazy;
        lazy = 0;
    }
    void recalc() {
        sum = sz;
        F0R(i,2) if (c[i]) sum += c[i]->sum;
    }
};

pair<tnode*,tnode*> split(tnode* t, int v) { 
    if (!t) return {t,t};
    t->propogate();
    
    int sum0 = t->c[0]?t->c[0]->sum:0;
    if (v <= sum0) {
        pair<tnode*,tnode*> p = split(t->c[0], v);
        t->c[0] = p.s; t->recalc();
        return {p.f, t};
    } else if (v < sum0+t->sz) {
        tnode* t1 = new tnode(t->val,v-sum0); t1->c[0] = t->c[0]; t1->recalc();
        tnode* t2 = new tnode(t->val,sum0+t->sz-v); t2->c[1] = t->c[1]; t2->recalc();
        return {t1,t2};
    } else {
        pair<tnode*,tnode*> p = split(t->c[1], v-sum0-t->sz);
        t->c[1] = p.f; t->recalc();
        return {t, p.s};
    }
}
    
tnode* merge(tnode* l, tnode* r) {
    if (!l) return r; 
    if (!r) return l;
    l->propogate(), r->propogate();
    
    if (l->pri > r->pri) {
        l->c[1] = merge(l->c[1],r);
        l->recalc();
        return l;
    } else {
        r->c[0] = merge(l,r->c[0]);
        r->recalc();
        return r;
    }
}


tnode* root;

void ins(int val) {
    root = merge(root,new tnode(val,1));
}

vector<pair<ll,int>> v;

void trav(tnode* x, bool f = 0) {
    if (!x) return;
    x->propogate();
    
    trav(x->c[0],f);
    v.pb(mp(x->val,x->sz));
    if (x->val < 0) cout << "DARN " << x->lazy << " " << x->val << "\n";
    if (f) F0R(i,x->sz) cout << x->val << " ";
    trav(x->c[1],f);
}

void op1(int l, int r, int x) {
    auto a = split(root,r+1);
    auto b = split(a.f,l);
    
    b.s->lazy += x;
    
    root = merge(merge(b.f,b.s),a.s);
}

void op2(int l, int r, int x) {
    auto a = split(root,r+1);
    auto b = split(a.f,l);
    root = merge(merge(b.f,new tnode(x,r-l+1)),a.s);
}

void op3(int l, int r, int x) { // something is wrong with this
    auto a = split(root,r+1);
    auto b = split(a.f,l);
    v.clear();
    trav(b.s);
    int co = 0;
    
    sort(v.begin(),v.end());
    F0R(i,v.size()) {
        co += v[i].s;
        if (co >= x) {
            if (v[i].f == 542737099) {
                for (auto z: v) cout << "OH " << z.f << " " << z.s << "\n";
            }
            cout << v[i].f << "\n";
            break;
        }
    }
    root = merge(merge(b.f,b.s),a.s);
}

void op4(int l, int r, int x, int y) { 
    auto a = split(root,r+1);
    auto b = split(a.f,l);
    v.clear();
    trav(b.s);
    
    ll co = 0;
    F0R(i,v.size()) {
        co += v[i].s*po(v[i].f%y,x,y);
        co %= y;
    }
    cout << co << "\n";
    root = merge(merge(b.f,b.s),a.s);
}

int main() {
	cin >> n >> m >> seed >> vmax;
    F0R(i,n) ins(rnd()%vmax+1);
    FOR(i,1,m+1) {
        int op = rnd()%4 + 1;
        int l = rnd()%n, r = rnd()%n;
        if (l > r) swap(l, r);
        
        int x,y;
        if (op == 3) x = rnd()%(r-l+1)+1;
        else x = rnd()%vmax+1;
        if (op == 4) y = rnd()%vmax+1;
        
        if (op == 1) op1(l,r,x);
        else if (op == 2) op2(l,r,x);
        else if (op == 3) {
            op3(l,r,x);
        } else if (op == 4) {
            op4(l,r,x,y);
        }
    }
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!