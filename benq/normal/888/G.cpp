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
    tnode* c[2];
    tnode() { c[0] = c[1] = NULL; }
};

void ins(tnode* x, int val) {
    F0Rd(i,30) {
        int b = val&(1<<i) ? 1 : 0;
        if (!x->c[b]) x->c[b] = new tnode();
        x = x->c[b];
    }
}

tnode* merge(tnode* l, tnode* r) {
    if (!l) return r;
    if (!r) return l;
    l->c[0] = merge(l->c[0],r->c[0]);
    l->c[1] = merge(l->c[1],r->c[1]);
    return l;
}

int query(tnode* x, int val) {
    int ans = 0;
    F0Rd(i,30) {
        int b = (val&(1<<i))?1:0;
        if (x->c[b]) x = x->c[b];
        else {
            ans ^= 1<<i;
            x = x->c[b^1];
        }
    }
    return ans;
}

int process(tnode* l, tnode* r, int lev, int cur) {
    if (lev == -1) {
        return query(r,cur);
    } else {
        int tmp = 2*MOD;
        if (l->c[0]) tmp = min(tmp,process(l->c[0],r,lev-1,cur));
        if (l->c[1]) tmp = min(tmp,process(l->c[1],r,lev-1,cur^(1<<lev)));
        return tmp;
    }
}

int n;
ll ans = 0;
tnode* root = new tnode();

tnode* solve(tnode* x, int lev, int cur) {
    if (!x) return x;
    if (lev == -1) {
        tnode* tmp = new tnode();
        ins(tmp,cur);
        return tmp;
    }
    
    auto l = solve(x->c[0],lev-1,cur), r = solve(x->c[1],lev-1,cur^(1<<lev));
    if (l && r) ans += process(l,r,29,0);
    return merge(l,r);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) {
	    int a; cin >> a;
	    ins(root,a);
	}
	solve(root,29,0);
	cout << ans;
}

// read!
// ll vs. int!