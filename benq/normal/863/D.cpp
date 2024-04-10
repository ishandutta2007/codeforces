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

int n,q,m;

struct tnode {
    int val, pri, sz, flip;
    tnode *c[2];
    tnode (int v) {
        c[0] = c[1] = NULL;
        pri = (rand()<<15)+rand(), flip = 0; // note that this is < (1<<15) on windows!
        val = v;
        sz = 1;
    }
    void recalc() {
        sz = 1;
        if (c[0]) sz += c[0]->sz;
        if (c[1]) sz += c[1]->sz;
    }
    void propogate() {
        if (flip) {
            swap(c[0],c[1]);
            if (c[0]) c[0]->flip ^= 1;
            if (c[1]) c[1]->flip ^= 1;
            flip = 0;
        }
    }
};

tnode *root;

void inOrder(tnode *cur) {
    if (!cur) return;
    cout << "NODE " << cur->val << " PRIORITY: " << cur->pri << " SIZE " << cur->sz << "\n";
    if (cur->c[0]) cout << "LEFT: " << cur->c[0]->val << "\n";
    if (cur->c[1]) cout << "RIGHT: " << cur->c[1]->val << "\n";
    cout << "\n";
    inOrder(cur->c[0]);
    inOrder(cur->c[1]);
}

pair<tnode*,tnode*> split(tnode* t, int v) { 
	if (!t) return {t,t};

    t->propogate();
    int tmp = t->c[0] ? t->c[0]->sz : 0;
	if (v <= tmp) {
		pair<tnode*,tnode*> p = split(t->c[0], v);
		t->c[0] = p.s;
		t->recalc();
		return {p.f, t};
	} else {
		pair<tnode*,tnode*> p = split(t->c[1], v-tmp-1);
		t->c[1] = p.f; 
		t->recalc();
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

tnode* ins(tnode* x, int pos, int val) {
    auto a = split(x,pos);
    tnode* z = new tnode(val);
    return merge(merge(a.f,z),a.s);
}

tnode* del(tnode* x, int pos) {
    auto a = split(x,pos);
    auto b = split(a.s,1);
    delete b.f;
    
    return merge(a.f,b.s);
}

int get(int ind) {
    auto a = split(root,ind);
    auto b = split(a.s,1);
    int t = b.f->val;
    root = merge(a.f,merge(b.f,b.s));
    return t;
}

tnode* reverse(tnode* x, int l, int r) {
    auto a = split(x,l);
    auto b = split(a.s,r-l+1);
    b.f->flip ^= 1;
    return merge(a.f,merge(b.f,b.s));
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> q >> m;
	F0R(i,n) {
	    int a; cin >> a;
	    root = ins(root,i,a);
	}
	F0R(i,q) {
	    int t,l,r; cin >> t >> l >> r;
	    l--, r--;
	    if (t == 1) {
	        int x = get(r); 
	        root = del(root,r);
	        root = ins(root,l,x);
	    } else {
	        root = reverse(root,l,r);
	    }
	}
	F0R(i,m) {
	    int x; cin >> x; x--;
	    cout << get(x) << " ";
	}
}

// read!
// ll vs. int!