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

struct tnode {
    int val, pri, lazy;
    tnode *c[2];
    tnode (int v) {
        val = v;
        pri = (rand()<<15)+rand();
        lazy = 0;
        c[0] = c[1] = NULL;
    }
    void propogate() {
        val += lazy;
        if (c[0]) c[0]->lazy += lazy;
        if (c[1]) c[1]->lazy += lazy;
        lazy = 0;
    }
};

tnode* root;
int n;

/// OK
void rot (tnode *&p, int d) { // takes care of both left / right rotations
    tnode *q = p->c[d];
    p->propogate(), q->propogate();
    p->c[d] = q->c[d^1];
    q->c[d^1] = p;
    p = q;
}

/// OK
pair<tnode*,tnode*> split(tnode* t, int v) { // >= x goes to the right
	if (!t) return {t,t};

    t->propogate();
	if (v <= t->val) {
		pair<tnode*,tnode*> p = split(t->c[0], v);
		t->c[0] = p.s; 
		return {p.f, t};
	} else {
		pair<tnode*,tnode*> p = split(t->c[1], v);
		t->c[1] = p.f; 
		return {t, p.s};
	}
}

/// OK
tnode* inslst(tnode* x, int val) {
    if (!x) return new tnode(val);
    x->propogate();
    x->c[1] = inslst(x->c[1],val);
    if (x->c[1]->pri > x->pri) rot(x,1);
    return x;
}

/// OK
tnode* remfst(tnode* x) {
    x->propogate();
    if (!x->c[0]) {
        tnode* c = x->c[1]; 
        delete x;
        return c;
    }
    x->c[0] = remfst(x->c[0]);
    return x;
}

/// OK
tnode* merge(tnode* l, tnode* r) {
    if (!l) return r; 
    if (!r) return l;
    l->propogate(), r->propogate();
    if (l->pri > r->pri) {
        l->c[1] = merge(l->c[1],r);
        return l;
    } else {
        r->c[0] = merge(l,r->c[0]);
        return r;
    }
}

int inorder(tnode* x) {
    if (!x) return 0;
    x->propogate();
    int ans = inorder(x->c[0]);
    //cout << "HI " << x->val << "\n";
    return ans+1+inorder(x->c[1]);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) {
	    int l,r; cin >> l >> r; // l to r-1
	    auto a = split(root,l);
	    auto b = split(a.s,r);
	    a.f = inslst(a.f,l);
	    if (b.f) b.f->lazy ++;
	    if (b.s) b.s = remfst(b.s);
	    root = merge(a.f,merge(b.f,b.s));
	}
	cout << inorder(root) << "\n";
}

// read!
// ll vs. int!