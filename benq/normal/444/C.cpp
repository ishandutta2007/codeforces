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
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;

int n,m;

const ll INF = 1e18;

template<class T, int SZ> struct LazySegTree {
    T sum[2*SZ], lazy[2*SZ]; // set SZ to a power of 2
    
    LazySegTree() {
        memset (sum,0,sizeof sum);
        memset (lazy,0,sizeof lazy);
    }
    
    void push(int ind, int L, int R) {
        sum[ind] += (R-L+1)*lazy[ind];
        if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
        lazy[ind] = 0;
    }
    
    void pull(int ind) {
        sum[ind] = sum[2*ind]+sum[2*ind+1];
    }
    
    void build() {
        F0Rd(i,SZ) pull(i);
    }
    
    T qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return sum[ind];
        
        int M = (L+R)/2;
        return qsum(lo,hi,2*ind,L,M)+qsum(lo,hi,2*ind+1,M+1,R);
    }
    
    void upd(int lo, int hi, ll inc, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind,L,R);
            return;
        }
        
        int M = (L+R)/2;
        upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
};

LazySegTree<ll,1<<17> seg;
set<pair<pii,int>> s;

void process(int l, int r, int x, auto it) {
    auto a = *it;
    if (a.f.s > r) {
        s.insert({{r+1,a.f.s},a.s});
        a.f.s = r;
    }
    if (a.f.f < l) {
        s.insert({{a.f.f,l-1},a.s});
        a.f.f = l;
    }
    seg.upd(a.f.f,a.f.s,abs(x-a.s));
    s.erase(it);
}

void mod(int l, int r, int x) {
    auto i1 = prev(s.lb({{l+1,-MOD},-MOD})); // first one before the first one >= l+1
    while (i1 != s.end() && i1->f.f <= r) {
        auto i = i1;
        i1 = next(i1);
        process(l,r,x,i);
    }
    s.insert({{l,r},x});
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	F0R(i,n) s.insert({{i,i},i+1});
	F0R(i,m) {
	    int t,l,r; cin >> t >> l >> r; l--, r--;
	    if (t == 1) {
	        int x; cin >> x;
	        mod(l,r,x);
	    } else {
	        cout << seg.qsum(l,r) << "\n";
	    }
	}
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!